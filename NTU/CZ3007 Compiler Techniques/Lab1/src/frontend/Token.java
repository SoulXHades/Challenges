package frontend;

/**
 * Class for representing tokens. Each token is characterised by its token type, its lexeme,
 * and its source position (given by its line and column numbers).
 * 
 * You do not need to change anything in this file.
 */
public final class Token {
	/** Token types are provided as an enum. */
	public enum Type {
		// keywords
		BOOLEAN,
		BREAK,
		ELSE,
		FALSE,
		IF,
		IMPORT,
		INT,
		MODULE,
		PUBLIC,
		RETURN,
		TRUE,
		TYPE,
		VOID,
		WHILE,
		
		// punctuation symbols
		COMMA,						/* , */
		LBRACKET,					/* [ */
		LCURLY,						/* { */
		LPAREN,						/* ( */
		RBRACKET,					/* ] */
		RCURLY,						/* } */
		RPAREN,						/* ) */
		SEMICOLON,					/* ; */
		
		// operators
		DIV,						/* / */
		EQEQ,						/* == */
		EQL,						/* = */
		GEQ,						/* >= */
		GT,							/* > */
		LEQ,						/* <= */
		LT,							/* < */
		MINUS,						/* - */
		NEQ,						/* != */
		PLUS,						/* + */
		TIMES,						/* * */
		
		// identifier
		ID,
		
		// literals
		INT_LITERAL,
		STRING_LITERAL,
		
		// special end-of-file token
		EOF
	};
	
	private final Type type;
	private final int line, column;
	private final String lexeme;
	
	public Token(Type type, int line, int column, String lexeme) {
		assert type != null;
		assert line >= 0;
		assert column >= 0;
		assert lexeme != null;
		
		this.type = type;
		this.line = line;
		this.column = column;
		this.lexeme = lexeme;
	}
	
	public boolean isEOF() {
		return type == Type.EOF;
	}
	
	@Override
	public String toString() {
		return type + "@" + line + ":" + column + "='" + lexeme + "'";
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + column;
		result = prime * result + lexeme.hashCode();
		result = prime * result + line;
		return prime * result + type.hashCode();
	}

	@Override
	public boolean equals(Object obj) {
		if(obj instanceof Token) {
			Token that = (Token)obj;
			return this.type == that.type &&
				   this.line == that.line &&
				   this.column == that.column &&
				   this.lexeme.equals(that.lexeme);
		} else {
			return false;
		}
	}
}
