package backend;

import soot.RefType;
import soot.Type;
import ast.ArrayType;
import ast.BooleanType;
import ast.JavaType;
import ast.TypeDescriptor;
import ast.Visitor;
import ast.VoidType;

/** Utility class for converting from source-level types to Soot types. */
public class SootTypeUtil {
	/** Determines the Soot-level type for the given type descriptor. */
	public static Type getSootType(TypeDescriptor td) {
		return td.accept(new Visitor<Type>() {
			@Override
			public Type visitIntType(ast.IntType nd) {
				return soot.IntType.v();
			}
			
			@Override
			public Type visitBooleanType(BooleanType nd) {
				return soot.BooleanType.v();
			}
			
			@Override
			public Type visitVoidType(VoidType nd) {
				return soot.VoidType.v();
			}
			
			@Override
			public Type visitArrayType(ArrayType nd) {
				return nd.getElementType().accept(this).makeArrayType();
			}
			
			@Override
			public Type visitJavaType(JavaType nd) {
				return RefType.v(nd.getName());
			}
		});
	}
}
