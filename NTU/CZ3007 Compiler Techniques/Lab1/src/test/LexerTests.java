package test;

import static org.junit.Assert.*;

import java.io.IOException;
import java.io.StringReader;

import lexer.Lexer;

import org.junit.Test;

import frontend.Token;
import frontend.Token.Type;
import static frontend.Token.Type.*;

/**
 * This class contains unit tests for your lexer. Currently, there is only one test, but you
 * are strongly encouraged to write your own tests.
 */
public class LexerTests {
	// helper method to run tests; no need to change this
	private final void runtest(String input, Token... output) {
		Lexer lexer = new Lexer(new StringReader(input));
		int i=0;
		Token actual=new Token(MODULE, 0, 0, ""), expected;
		try {
			do {
				assertTrue(i < output.length);
				expected = output[i++];
				try {
					actual = lexer.nextToken();
					assertEquals(expected, actual);
				} catch(Error e) {
					if(expected != null)
						fail(e.getMessage());
					/* return; */
				}
			} while(!actual.isEOF());
		} catch (IOException e) {
			e.printStackTrace();
			fail(e.getMessage());
		}
	}

	/** Example unit test. */
	@Test
	public void testKWs() {
		// first argument to runtest is the string to lex; the remaining arguments
		// are the expected tokens
		runtest("module false return while",
				new Token(MODULE, 0, 0, "module"),
				new Token(FALSE, 0, 7, "false"),
				new Token(RETURN, 0, 13, "return"),
				new Token(WHILE, 0, 20, "while"),
				new Token(EOF, 0, 25, ""));
	}

	@Test
	public void testStringLiteralWithDoubleQuote() {
		runtest("\"\"\"",
				new Token(STRING_LITERAL, 0, 0, ""),
				(Token)null,
				new Token(EOF, 0, 3, ""));
	}

	@Test
	public void testStringLiteral() {
		runtest("\"\\n\"", 
				new Token(STRING_LITERAL, 0, 0, "\\n"),
				new Token(EOF, 0, 4, ""));
	}

	@Test
	public void testStringLiteral2() {
		runtest("\"\\\"", 
				new Token(STRING_LITERAL, 0, 0, "\\"),
				new Token(EOF, 0, 3, ""));
	}
	
	@Test
	public void testStringLiteral3() {
		runtest("\"abc\"", 
				new Token(STRING_LITERAL, 0, 0, "abc"),
				new Token(EOF, 0, 5, ""));
	}
	
	@Test
	public void testWhileLoop() {
		runtest("while (b=1) \n{b=b*3;}", 
				new Token(WHILE, 0, 0, "while"),
				new Token(LPAREN,0, 6, "(" ),
				new Token(ID, 0, 7, "b"),
				new Token(EQL, 0, 8, "="),
				new Token(INT_LITERAL, 0, 9, "1"),
				new Token(RPAREN, 0, 10, ")"),
				new Token(LCURLY, 1, 0, "{"),
				new Token(ID, 1, 1, "b"),
				new Token(EQL, 1, 2, "="),
				new Token(ID, 1, 3, "b"),
				new Token(TIMES, 1, 4, "*"),
				new Token(INT_LITERAL, 1, 5, "3"),
				new Token(SEMICOLON, 1, 6, ";"),
				new Token(RCURLY, 1, 7, "}"),
				new Token(EOF, 1, 8, ""));
	}
	
	@Test
	public void testAllKws() {
		runtest("boolean break else false if import int module public return true type void while",
				new Token(BOOLEAN, 0, 0, "boolean"),
				new Token(BREAK, 0, 8, "break"),
				new Token(ELSE, 0, 14, "else"),
				new Token(FALSE, 0, 19, "false"),
				new Token(IF, 0, 25, "if"),
				new Token(IMPORT, 0, 28, "import"),
				new Token(INT, 0, 35, "int"),
				new Token(MODULE, 0, 39, "module"),
				new Token(PUBLIC, 0, 46, "public"),
				new Token(RETURN, 0, 53, "return"),
				new Token(TRUE, 0, 60, "true"),
				new Token(TYPE, 0, 65, "type"),
				new Token(VOID, 0, 70, "void"),
				new Token(WHILE, 0, 75, "while"),
				new Token(EOF,0, 80, ""));	
	}
	
	@Test
	public void testAllPSs(){
		runtest(", [ { ( ) } ] ;", 
			new Token(COMMA, 0, 0, ","),
			new Token(LBRACKET, 0, 2, "["),
			new Token(LCURLY, 0, 4, "{"),
			new Token(LPAREN, 0, 6, "("),
			new Token(RPAREN, 0, 8, ")"),
			new Token(RCURLY, 0, 10, "}"),
			new Token(RBRACKET, 0, 12, "]"),
			new Token(SEMICOLON, 0, 14, ";"),
			new Token(EOF, 0, 15, ""));
	}
	
	@Test
	public void testAllOperators(){
		runtest("/ == = >= > <= < - != + *",
				new Token(DIV, 0, 0, "/"),
				new Token(EQEQ, 0, 2, "=="),
				new Token(EQL, 0, 5, "="),
				new Token(GEQ, 0, 7, ">="),
				new Token(GT, 0, 10, ">"),
				new Token(LEQ, 0, 12, "<="),
				new Token(LT, 0, 15, "<"),
				new Token(MINUS, 0, 17, "-"),
				new Token(NEQ, 0, 19, "!="),
				new Token(PLUS, 0, 22, "+"),
				new Token(TIMES, 0, 24, "*"),
				new Token(EOF, 0, 25, ""));
	}
	
	@Test
	public void testOnIntOp(){
		runtest("++234 ===",
				new Token(PLUS, 0, 0, "+"),
				new Token(PLUS, 0, 1, "+"),
				new Token(INT_LITERAL, 0, 2, "234"),
				new Token(EQEQ, 0, 6, "=="),
				new Token(EQL, 0, 8, "="),
				new Token(EOF, 0, 9, "")
				
				);
	}
}
