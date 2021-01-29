package backend;

import java.util.ArrayList;

import soot.Local;
import soot.Scene;
import soot.SootClass;
import soot.SootMethodRef;
import soot.Type;
import soot.Unit;
import soot.Value;
import soot.jimple.Constant;
import soot.jimple.IntConstant;
import soot.jimple.Jimple;
import soot.jimple.NopStmt;
import soot.jimple.StaticInvokeExpr;
import soot.jimple.StringConstant;
import soot.util.Chain;
import ast.AddExpr;
import ast.ArrayIndex;
import ast.ArrayLiteral;
import ast.Assignment;
import ast.BinaryExpr;
import ast.BooleanLiteral;
import ast.Call;
import ast.CompExpr;
import ast.DivExpr;
import ast.EqExpr;
import ast.Expr;
import ast.FunctionDeclaration;
import ast.GeqExpr;
import ast.GtExpr;
import ast.IntLiteral;
import ast.LeqExpr;
import ast.LtExpr;
import ast.ModExpr;
import ast.Module;
import ast.MulExpr;
import ast.NegExpr;
import ast.NeqExpr;
import ast.Parameter;
import ast.StringLiteral;
import ast.SubExpr;
import ast.VarDecl;
import ast.VarName;
import ast.Visitor;

/**
 * This class is in charge of creating Jimple code for a given expression (and its nested
 * expressions, if applicable).
 */
public class ExprCodeGenerator extends Visitor<Value> {
	/** The {@link FunctionCodeGenerator} that instantiated this object. */
	private final FunctionCodeGenerator fcg;
	
	/** We cache the statement list of the enclosing function for convenience. */
	private final Chain<Unit> units;
	
	private ExprCodeGenerator(FunctionCodeGenerator fcg) {
		this.fcg = fcg;
		this.units = fcg.getBody().getUnits();
	}
	
	/**
	 * Ensures that the given value can be used as an operand; that is, if the
	 * value is not a {@link Local} or a {@link Constant}, this method allocates
	 * a new temporary variable and stores the value into that temporary.
	 */
	private Value wrap(Value v) {
		if(v == null || v instanceof Local || v instanceof Constant) {
			return v;
		} else {
			Local temp = fcg.mkTemp(v.getType());
			units.add(Jimple.v().newAssignStmt(temp, v));
			return temp;
		}
	}

	/** 
	 * Convenience method to generate code for an expression and wrap it.
	 */
	public static Value generate(Expr expr, FunctionCodeGenerator fcg) {
		ExprCodeGenerator gen = new ExprCodeGenerator(fcg);
		return gen.wrap(expr.accept(gen));
	}
	
	/** Generate code for an assignment. */
	@Override
	public Value visitAssignment(Assignment nd) {
		// note that the left hand side should _not_ be wrapped!
		Value lhs = nd.getLHS().accept(this),
			  rhs = wrap(nd.getRHS().accept(this));
		units.add(Jimple.v().newAssignStmt(lhs, rhs));
		return rhs;
	}
	
	/** Generate code for an integer literal. */
	@Override
	public Value visitIntLiteral(IntLiteral nd) {
		/* TODO: return something meaningful here */
		Value value = IntConstant.v(nd.getValue().intValue());
		return value;
	}
	
	/** Generate code for a string literal. */
	@Override
	public Value visitStringLiteral(StringLiteral nd) {
		/* TODO: return something meaningful here */
		Value strValue = StringConstant.v(nd.getValue());
		return strValue;
		
	}
	
	/** Generate code for a Boolean literal. */
	@Override
	public Value visitBooleanLiteral(BooleanLiteral nd) {
		/* TODO: return something meaningful here (hint: translate 'true' to integer
		 *       constant 1, 'false' to integer constant 0) */
        Boolean b = nd.getValue(); 
        
        if(!b) 
        	return IntConstant.v(0);//false
        else 
        	return IntConstant.v(1);//true
	}
	
	/** Generate code for an array literal. */
	@Override
	public Value visitArrayLiteral(ArrayLiteral nd) {
		Type elttp = SootTypeUtil.getSootType(nd.getElement(0).type());
		// create a new array with the appropriate number of elements
		Value array = wrap(Jimple.v().newNewArrayExpr(elttp, IntConstant.v(nd.getNumElement())));
		for(int i=0;i<nd.getNumElement();++i) {
			// generate code to store the individual expressions into the elements of the array
			Value elt = wrap(nd.getElement(i).accept(this));
			units.add(Jimple.v().newAssignStmt(Jimple.v().newArrayRef(array, IntConstant.v(i)), elt));
		}
		return array;
	}
	
	/** Generate code for an array index expression. */
	@Override
	public Value visitArrayIndex(ArrayIndex nd) {
		/* TODO: generate code for array index */
		Value arrayIndex = wrap(nd.getIndex().accept(this));
		Value arrayBase = wrap(nd.getBase().accept(this));
		Value value = Jimple.v().newArrayRef(arrayBase, arrayIndex);
		return value;
	}
	
	/** Generate code for a variable name. */
	@Override
	public Value visitVarName(VarName nd) {
		VarDecl decl = nd.decl();
		// determine whether this name refers to a local or to a field
		if(decl.isLocal()) {
			return fcg.getSootLocal(decl);
		} else {
			SootClass declaringClass = fcg.getModuleCodeGenerator().getProgramCodeGenerator().getSootClass(decl.getModule());
			Type fieldType = SootTypeUtil.getSootType(decl.getTypeName().getDescriptor());
			return Jimple.v().newStaticFieldRef(Scene.v().makeFieldRef(declaringClass, decl.getName(), fieldType, true));
		}
	}
	
	/** Generate code for a binary expression. */
	@Override
	public Value visitBinaryExpr(BinaryExpr nd) {
		/* TODO: generate code for binary expression here; you can either use a visitor
		 *       to determine the type of binary expression you are dealing with, or
		 *       generate code in the more specialised visitor methods visitAddExpr,
		 *       visitSubExpr, etc., instead
		 */
		
		final Value binLeft = wrap(nd.getLeft().accept(this));
        final Value binRight = wrap(nd.getRight().accept(this));
        
        Value binRes = nd.accept(new Visitor<Value>() {
        	
            @Override
            public Value visitAddExpr(AddExpr nd){ //Returns AddExpr, which is subinterface of Value
                return Jimple.v().newAddExpr(binLeft, binRight);
            }
            @Override
            public Value visitSubExpr(SubExpr nd){ //Returns SubExpr, which is subinterface of Value
                return Jimple.v().newSubExpr(binLeft, binRight);
            }
            @Override
            public Value visitMulExpr(MulExpr nd){ //Returns MulExpr, which is subinterface of Value
                return Jimple.v().newMulExpr(binLeft, binRight);
            }
            @Override
            public Value visitDivExpr(DivExpr nd){ //Returns DivExpr, which is subinterface of Value
                return Jimple.v().newDivExpr(binLeft, binRight);
            }
            @Override
            public Value visitModExpr(ModExpr nd){ //Returns RemExpr, which is subinterface of Value
                return Jimple.v().newRemExpr(binLeft, binRight);
            }
        });
        return binRes;
		
		
	}
	
	/** Generate code for a comparison expression. */
	@Override
	public Value visitCompExpr(CompExpr nd) {
		final Value left = wrap(nd.getLeft().accept(this)),
					right = wrap(nd.getRight().accept(this));
		Value res = nd.accept(new Visitor<Value>() {
			@Override
			public Value visitEqExpr(EqExpr nd) {
				return Jimple.v().newEqExpr(left, right);
			}
			@Override
			public Value visitNeqExpr(NeqExpr nd) {
				return Jimple.v().newNeExpr(left, right);
			}
			@Override
			public Value visitLtExpr(LtExpr nd) {
				return Jimple.v().newLtExpr(left, right);
			}
			@Override
			public Value visitGtExpr(GtExpr nd) {
				return Jimple.v().newGtExpr(left, right);
			}
			@Override
			public Value visitLeqExpr(LeqExpr nd) {
				return Jimple.v().newLeExpr(left, right);
			}
			@Override
			public Value visitGeqExpr(GeqExpr nd) {
				return Jimple.v().newGeExpr(left, right);
			}
		});
		// compute a result of 0 or 1 depending on the truth value of the expression
		Local resvar = fcg.mkTemp(SootTypeUtil.getSootType(nd.type()));
		units.add(Jimple.v().newAssignStmt(resvar, IntConstant.v(1)));
		NopStmt join = Jimple.v().newNopStmt();
		units.add(Jimple.v().newIfStmt(res, join));
		units.add(Jimple.v().newAssignStmt(resvar, IntConstant.v(0)));
		units.add(join);
		return resvar;
	}
	
	/** Generate code for a negation expression. */
	@Override
	public Value visitNegExpr(NegExpr nd) {
		/* TODO: generate code for negation expression */
		
        Value value = Jimple.v().newNegExpr(wrap(nd.getOperand().accept(this)));
	
        return value;
		
	}
	
	/** Generate code for a function call. */
	@Override
	public Value visitCall(Call nd) {
		String calleeName = nd.getCallee().getName();
		FunctionDeclaration calleeDecl = nd.getCallTarget();
		Module calleeModule = calleeDecl.getModule();
		ArrayList<Type> parmTypes = new ArrayList<Type>(calleeDecl.getNumParameter());
		for(Parameter parm : calleeDecl.getParameters())
			parmTypes.add(SootTypeUtil.getSootType(parm.type()));
		Type rettp = SootTypeUtil.getSootType(calleeDecl.getReturnType().getDescriptor());
		
		// compute reference to callee
		SootClass calleeSootClass = fcg.getModuleCodeGenerator().getProgramCodeGenerator().getSootClass(calleeModule);
		SootMethodRef callee = Scene.v().makeMethodRef(calleeSootClass, calleeName, parmTypes, rettp, true);
		
		// prepare arguments
		Value[] args = new Value[nd.getNumArgument()];
		for(int i=0;i<args.length;++i)
			args[i] = wrap(nd.getArgument(i).accept(this));
		
		// assemble invoke expression
		StaticInvokeExpr invk = Jimple.v().newStaticInvokeExpr(callee, args);
		
		// decide what to do with the result
		if(rettp == soot.VoidType.v()) {
			units.add(Jimple.v().newInvokeStmt(invk));
			return null;
		} else {
			Local res = fcg.mkTemp(rettp);
			units.add(Jimple.v().newAssignStmt(res, invk));
			return res;
		}		
	}
}