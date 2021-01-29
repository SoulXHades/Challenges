package test;

import static org.junit.Assert.fail;

import java.io.StringReader;

import lexer.Lexer;

import org.junit.Test;

import parser.Parser;
import ast.CompilerError;
import ast.List;
import ast.Module;
import ast.Program;

public class SemanticAnalyserTests {
	private void runtest(String... srcs) {
		runtest(true, srcs);
	}

	private void runtest(boolean succeed, String... srcs) {
		Parser parser = new Parser();
		try {
			List<Module> modules = new List<Module>();
			for(String src : srcs)
				modules.add((Module)parser.parse(new Lexer(new StringReader(src))));
			Program prog = new Program(modules);
			prog.namecheck();
			if(!prog.hasErrors()) prog.typecheck();
			if(succeed) {
				if(prog.hasErrors()) {
					StringBuffer errors = new StringBuffer();
					for(CompilerError err : prog.getErrors())
						errors.append("\n" + err);
					fail("Program was expected to pass semantic checks, but the following " +
						 "errors were reported:" + errors);
				}
			} else if(!prog.hasErrors()) {
				fail("Program was expected to fail semantic checks, but passed.");
			}
		} catch (Throwable e) {
			if(e instanceof AssertionError) {
				throw (AssertionError)e;
			} else {
				e.printStackTrace();
				if(succeed)
					fail(e.getMessage());
			}
		}
	}

	@Test
	public void testModuleNameClash() {
		runtest(false, 
				"module M { }",
				"module M { }");
	}
	
	@Test
	public void testModuleNameNoClash() {
		runtest("module M { }",
				"module N { }");
	}
	
	@Test
	public void testUnresolvedImport() {
		runtest(false,
				"module M { import N; }");
	}
	
	@Test
	public void testResolvedImport() {
		runtest("module M { import N; }",
				"module N { }");
	}
	
	@Test
	public void testSelfImport() {
		runtest(false, "module M { import M; }");
	}

	@Test
	public void testFunctionNameClash() {
		runtest(false,
				"module M {" +
				"  void foo() { }" +
				"  void foo() { }" +
				"}");
	}
	
	@Test
	public void testFunctionNoNameClash() {
		runtest("module M {" +
				"  void foo() { }" +
				"  void bar() { }" +
				"}");
	}
	
	@Test
	public void testFunctionShadowingImport() {
		runtest("module M {" +
				"  import N;" +
				"  void foo() {}" +
				"}",
				"module N {" +
				"  public void foo() {}" +
				"}");
	}

	@Test
	public void testTypeNameClash() {
		runtest(false,
				"module M {" +
				"   type foo = \"int\";" +
				"  int bar;" +
				"  type foo = \"boolean\";"   +
				"}");
	}
	
		@Test
	public void testTypeNameNoClash() {
		runtest("module M {" +
				"   type foo = \"int\";" +
				"  int bar;" +
				"  foo moo;" +
				"  type bar = \"boolean\";"   +
				"}");
	}
	
	@Test
	public void testTypeShadowingImport() {
		runtest("module M {" +
				"  import N;" +
				"  type foo = \"int\";" +
				"}",
				"module N {" +
				"  public type foo = \"boolean\";" +
				"}");
	}
	
	@Test
	public void testVarNameClash() {
		runtest(false,
				"module M {" +
				"  void foo() {" +
				"    int x;" +
				"    boolean x;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testFieldNameClash() {
		runtest("module M {" +
				"  int x;" +
				"  void foo() {" +
				"    boolean x;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testFieldNameShadowingImport() {
		runtest("module M {" +
				"  import N;" +
				"  int x;" +
				"}",
				"module N {" +
				"  public int x;" +
				"}");
	}
	
	@Test
	public void testVarParameterNoNameClash() {
		runtest("module M {" +
				"  void foo(int x) {" +
				"    boolean x;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testParameterNameClash() {
		runtest(false,
				"module M {" +
				"  void foo(int x; boolean x) {" +
				"  }" +
				"}");
	}
	
	@Test
	public void testVarFieldNoNameClash() {
		runtest("module M {" +
				"  int x;" +
				"  void foo() {" +
				"    boolean x;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testVarNoNameClash() {
		runtest("module M {" +
				"  void foo() {" +
				"    int x;" +
				"    {" +
				"      boolean x;" +
				"    }" +
				"  }" +
				"}");
	}
	
	@Test
	public void testUndeclaredVariable() {
		runtest(false,
				"module M {" +
					"  int foo() {" +
				"    return res;" + 
				"  }" +
				"}");
	}
	
	@Test
	public void testUndeclaredFunctionName() {
		runtest(false,
				"module M {" +
					"  int foo() {" +
				"    return bar(0);" + 
				"  }" +
				"}");
	}
	
	@Test
	public void testUndefinedUserType() {
		runtest(false,
				"module M {" +
				"  foo bar;" +
				"}");
	}
	
	@Test
	public void testBreakOutsideLoop() {
		runtest(false,
				"module M {" +
				"  void foo() {" +
				"    break;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testBreakInsideLoop() {
		runtest("module M {" +
				"  void foo() {" +
				"    while(true)" +
				"      break;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testBreakNestedInsideLoop() {
		runtest("module M {" +
				"  void foo() {" +
				"    while(true) {" +
				"      if(true) {" +
				"        { break; }" +
				"      }" +
				"    }" +
				"  }" +
				"}");
	}
	
	@Test
	public void testBreakNestedOutsideLoop() {
		runtest(false,
				"module M {" +
				"  void foo() {" +
				"    while(true) {}" +
				"    if(true) {" +
				"      { break; }" +
				"    }" +
				"  }" +
				"}");
	}

	@Test
	public void testLookupLocal() {
		runtest("module M {" +
				"  int foo() {" +
				"    int res;" +
				"    res = 23;" +
				"    return res;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testLookupLocalBad() {
		runtest(false,
				"module M {" +
				"  void foo() {" +
				"    res = 23;" +
				"    int res;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testLookupLocalNested() {
		runtest("module M {" +
				"  int foo() {" +
				"    int res;" +
				"    res = 23;" +
				"    if(true)" +
				"      return res;" +
				"    return 0;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testLookupFunction() {
		runtest("module M {" +
				"  int bar() { return 23; }" +
				"  int foo() {" +
				"    return bar();" +
				"  }" +
				"}");
	}
	
	@Test
	public void testLookupImportedFunction() {
		runtest("module M {" +
				"  import N;" +
				"  int foo() {" +
				"    return bar();" +
				"  }" +
				"}",
				"module N {" +
				"  public int bar() { return 23; }" +
				"}");
	}

	 @Test
	public void testLookupImportedFunctionFail() {
		runtest(false,
				"module M {" +
				"  import N;" +
				"  int foo() {" +
				"    return bar();" +
				"  }" +
				"}",
				"module N {" +
				"  int bar() { return 23; }" +
				"}");
	}
	
	@Test
	public void testLookupField() {
		runtest("module M {" +
				"  int res;" +
				"  int foo() {" +
				"    return res;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testLookupImportedField() {
		runtest("module M {" +
				"  import N;" +
				"  int foo() {" +
				"    return res;" +
				"  }" +
				"}",
				"module N {" +
				"  public int res;" +
				"}");
	}
	
	@Test
	public void testLookupImportedFieldFail() {
		runtest(false,
				"module M {" +
				"  import N;" +
				"  int foo() {" +
				"    return res;" +
				"  }" +
				"}",
				"module N {" +
				"  int res;" +
				"}");
	}
	
	@Test
	public void testVoidField() {
		runtest(false,
				"module M {" +
				"  void foo;" +
				"}");
	}
	
	@Test
	public void testVoidParameter() {
		runtest(false,
				"module M {" +
				"  int foo(void x) {}" +
				"}");
	}
	
	@Test
	public void testVoidLocal() {
		runtest(false,
				"module M {" +
				"  int foo() { void x; }" +
				"}");
	}
	
	@Test
	public void testBooleanIfCond() {
		runtest("module M {" +
				"  int foo() {" +
				"    if(true)" +
				"      return 42;" +
				"    return 23;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testCompIfCond() {
		runtest("module M {" +
				"  int foo() {" +
				"    if(0<1+1)" +
				"      return 42;" +
				"    return 23;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testNonBooleanIfCond() {
		runtest(false,
				"module M {" +
				"  int foo() {" +
				"    if(0)" +
				"      return 42;" +
				"    return 23;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testReturnTypeWrong() {
		runtest(false,
				"module M {" +
				"  int foo() {" +
				"    return true;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testVoidReturn() {
		runtest("module M {" +
				"  void foo() {" +
				"    return;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testExprReturn() {
		runtest("module M {" +
				"  int foo() {" +
				"    return 0;" +
				"  }" +
				"}");
	}

	@Test
	public void testExprReturnVoid() {
		runtest(false,
				"module M {" +
				"  boolean foo() {" +
				"    return;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testVoidTypeReturnWrong() {
		runtest(false,
				"module M {" +
				"  void foo() {" +
				"    return 0;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testBooleanLoopCond() {
		runtest("module M {" +
				"  int foo() {" +
				"    while(6>=0)" +
				"      return 42;" +
				"    return 23;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testNonBooleanWhileCond() {
		runtest(false,
				"module M {" +
				"  int foo() {" +
				"    while(5+5)" +
				"      return 42;" +
				"    return 23;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testCorrectArrayExpression() {
		runtest("module M {" +
				"  boolean foo(boolean[][] bss, int i, int j) {" +
				"    return bss[i][j];" +
				"  }" +
				"}");
	}
	
	@Test
	public void testIncorrectArrayBaseExpression() {
		runtest(false,
				"module M {" +
				"  boolean foo() {" +
				"  boolean[][] bss;" +
				"  bss[0] = true;" +
				"  return false;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testIncorrectArrayIndexExpression() {
		runtest(false,
				"module M {" +
				"  boolean foo(boolean[][] bss, int i, boolean j) {" +
				"    return bss[i][j];" +
				"  }" +
				"}");
	}
	
	@Test
	public void testArityMatch() {
		runtest(
				"module M {" +
				"  int id(int x, int y) { return x+y; }" +
				"  int foo() { return id(23, 42); }" +
				"}");
	}
	
	@Test
	public void testArityMismatchTooMany() {
		runtest(false,
				"module M {" +
				"  int id(int a) { return a; }" +
				"  int foo() { return id(1, 1); }" +
				"}");
	}
	
	@Test
	public void testArityMismatchTooFew() {
		runtest(false,
				"module M {" +
				"  int plus(int x, int y) { return x+y; }" +
				"  int foo() { return plus(23); }" +
				"}");
	}
	
	@Test
	public void testArgumentTypeMismatch() {
		runtest(false,
				"module M {" +
				"  int plus(int x, int y) { return x+y; }" +
				"  int foo() { return plus(23, false); }" +
				"}");
	}
	
	@Test
	public void testCorrectAssignment() {
		runtest("module M {" +
				"  boolean foo() {" +
				"    boolean res;" +
				"    res = true;" +
				"    return res;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testNonNumericBinary() {
		runtest(false,
				"module M {" +
				"  int plus(boolean x) {" +
				"    return x + x;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testComparison() {
		runtest("module M {" +
				"  void foo(int x) {" +
				"    if(x == 42)" +
				"      x = 23;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testInvalidComparison() {
		runtest(false,
				"module M {" +
				"  void foo(int x) {" +
				"    if(x == true)" +
				"      x = 0;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testInvalidArithmeticComparison() {
		runtest(false,
				"module M {" +
				"  void foo(boolean x) {" +
				"    if(x > true)" +
				"      x = false;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testUnaryOperator() {
		runtest("module M {" +
				"  int foo() {" +
				"    return -23;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testInvalidUnaryOperator() {
		runtest(false,
				"module M {" +
				"  int foo(boolean s) {" +
				"    return -s;" +
				"  }" +
				"}");
	}
	
	@Test
	public void testArrayLiteral() {
		runtest("module M {" +
				"  int[] foo() {" +
				"    return [23, 42];" +
				"  }" +
				"}");
	}
	
	@Test
	public void testInvalidArrayLiteral() {
		runtest(false,
				"module M {" +
				"  int[] foo() {" +
				"    return [true, 42];" +
				"  }" +
				"}");
	}
	
	@Test
	public void testInvalidArrayLiteral2() {
		runtest(false,
				"module M {" +
				"  void bar() {}" +
				"  int[] foo() {" +
				"    return [bar()];" +
				"  }" +
				"}");
	}
	
	@Test
	public void testVoidArrayType() {
		runtest(false,
				"module M {" +
				"  void[] bar;" +
				"}");
	}
	
}
	