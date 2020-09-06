# Setup Instructions
The code contained in this project is structured as follows:
* Folder **src** contains the source code:
	* Package **frontend** contains the code for the lexer and some helper code:
		* File *Token.java* contains a class defining the token type used for this lab; you do not need to modify it, but you should read and understand it.
		* File *lexer.flex* contains the source code for the lexer; to complete this lab assignment, you will need to complete the code of the lexer as indicated by the comments in lexer.flexand the problem description below.
	* Package test contains the unit test suite in file *LexerTests.java*; to test your token specificationsin *lexer.flex*, you should add more tests here.
* Folder **lib** contains third-party libraries.
* *build.xml* is an Apache Ant build file that we will use to generate the lexer from *lexer.flex*.


# Problem Description
## Tokens for PL/3007
PL/3007 has fourteen keywords: boolean, break, else, false, if, import, int, module, public, return, true, type, void and while. Note that keywords are case sensitive; e.g., Boolean is not a keyword, but an identifier.

There are eight punctuation symbols: the comma (“,”), the left bracket (“[”), the left curly brace (“{”), the leftparenthesis (“(”), the right bracket (“]”), the right curly brace (“}”), the right parenthesis (“)”), and the semicolon (“;”).

Furthermore, PL/3007 has eleven operators (a subset of the operators of Java): the division operator (“/”), the equals operator (“==”), the assignment operator (“=”), the greater-or-equal operator (“>=”), the greater-than operator (“>”), the less-or-equal operator (“<=”), the less-than operator (“<”), the minus operator (“-”), the not-equals operator (“!=”), the plus operator (“+”), and the times operator (“\*”).

An identifier in PL/3007 is a sequence of one or more characters.The first character must be a letter. Each subsequent character in the sequence must be a letter, a digit or an underscore.

Finally, there are two kinds of literals: integer literals and string literals.

Integer literals consist of a sequence of one or more decimal digits. Note that integer literals are unsigned: positive or negative sign are considered to be unary operators. Also note that superfluous leading zeros are allowed.

String literals in PL/3007 are enclosed by double quotes, and may contain zero or more characters (except the double quote and the newline character). For example, “a\”” is not allowed because it contains a double quote character. You are advised not to introduce other lexical states to process string literals in your lexer.flexbecause our test suite assumes you do not use special state for string literals .

Apart from the above tokens, PL/3007 source code may contain whitespace characters (blank, tab, newline, return), which are skipped by the lexer. For the moment, we do not specify a syntax for comments, and your lexer does not need to handle them.

There is also a pseudo-token EOF indicating the end of input. The template code already handles this, so you do not need to worry about it.

## Token.java
The enum type Type in class Token contains one enum constant for every token type in PL/3007 as described above. Your lexer should return, for every token, an instance of class Token that has the correct token type and lexeme, together with the source position of the token. This is done by calling the constructor of the Token class. For example, when keyword “module” or identifier “average” is recognized by the lexer, the corresponding token may be created by calling the constructor Token():

> new Token(MODULE, yyline, yycolumn, yytext()); 
> new Token(ID, yyline, yycolumn, yytext());

yyline and yycolumn together specify the text position of the token in the source file. yytext() gives the matched text.

## lexer.flex
lexer.flexspecification consists of three parts, divided by %%:
* Usercode
* Options and declarations
* Lexical rules

You do not have to change anything in the usercode section. This section is copied verbatim into the beginning of the source file of the generated lexer before the scanner class is declared. This is the place to put package declarations and import statements.

In the options and declarations section, we see these options:
> %public
> %final
> %class Lexer
> %function nextToken 
> %type Token
> %unicode
> %line
> %column

*%public* and *%final* make the generated class public and final. *%class Lexer* tells JFlex to give the generated class the name “Lexer” and to write the generated code to a file “Lexer.java”. *%function nextToken* causes the scanning method to get the name “nextToken”. *%type Token* causes the scanning method to be declared as returning values of the type “Token”. Actions in the specification can then return values of Token as tokens. *%unicode* defines the set of characters the scanner will work on. *%line* switches line counting on (the current line number can be accessed via the variable yyline) and *%column* switches column counting on (current column is accessed via yycolumn).

The code included in *%{ ... %}* is copied verbatim into the generated lexer class source. Here you can declare member variables and functions that are used inside scanner actions. Fill in the code in the two methods
> private Token token(Token.Type type)
> private Token token(Token.Type type, String text)

which can be called in the lexer rule actions to create a token without providing all 4 parameter values as in Section 3.2. For example, with these two methods, you may use
> return token(MODULE);
> return token(ID, yytext());

in the lexer rule actions to return the two tokens respectively.

Note that for string literals, *yytext()* includes the beginning and ending double quotes but the lexeme of the token should exclude them. So the first and last characters of *yytext()* should be excluded. You may want to use the *substring()* method in Java to do this.

## Test Suite
The first call to *runtest()* states that when the lexer analyses the string "module false\n\treturn while", it should produce five tokens: a token of type MODULE, followed by a token of type FALSE, then a token of type RETURN, a token of type WHILE, and finally a token of type EOF, each with the appropriate line and column information (which are given as the second and the third arguments to the Token constructor), and lexeme (the fourth argument to the constructor). The line number and the column number in the source both start from 0.

Each character occupies one column in the line. Note that escaped characters like “\n’ or “\t” also occupy one column each. After each “\n”, the line number increases by 1 and column number restarts from 0.

The second call to *runtest()* tests a string with 3 double quote characters. The first two double quotes are recognized as an empty string literal. The lexer is expected not to recognize the third double quote as a valid token so it is expected to return a null token. Note that whenever the lexer is expected not to recognize something as a valid token, it is expected to return the null token.

The third call to *runtest()* tests a string literal of two characters which is a backslash followed by ‘n’. What the lexer sees is a character stream: a double quote, a backslash, a character n and a double quote. This is recognized as a string literal.

## Resources
The JFlex user’s manual is available online at http://jflex.de/manual.html. It contains documentation on the JFlex specification syntax and some examples of its use, which you are welcome to study. You do not need to understand lexer states for this lab.

You also do not need to learn about how to invoke JFlex from the command line. This is taken care of by the Ant build script provided to you.