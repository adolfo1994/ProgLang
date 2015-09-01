#include <stdio.h>
#include <ctype.h>
/* Global declarations */
/* Variables */
int charClass;
char lexeme [100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp, *fopen();

/* Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();
/* Character classes */
#define LETTER 0
#define DIGIT 1
#define FLOAT_SEPARATOR 2
#define INVALID 98
#define UNKNOWN 99
/* Token codes */
#define INT_LIT 10
#define FLOAT_LIT 11
#define IDENT 12
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

/******************************************************/
/* main driver */
main() {
/* Open the input data file and process its contents */
	if ((in_fp = fopen("front.in", "r")) == NULL)
 		printf("ERROR - cannot open front.in \n");
 	else {
 		getChar();
 		do {
 			lex();
 		} while (nextToken != EOF);
 	}
}
/*****************************************************/
/* lookup - a function to lookup operators and parentheses
 and return the token */
int lookup(char ch) {
	switch (ch) {
 		case '(':
 			addChar();
 			nextToken = LEFT_PAREN;
			break;
 		case ')':
 			addChar();
 			nextToken = RIGHT_PAREN;
 			break;
 		case '+':
			addChar();
 			nextToken = ADD_OP;
 			break;
 		case '-':
 			addChar();
 			nextToken = SUB_OP;
 			break;
 		case '*':
 			addChar();
 			nextToken = MULT_OP;
 			break;
		case '/':
			addChar();
			nextToken = DIV_OP;
			break;
 		default:
			addChar();
			nextToken = EOF;
			break;
		}
	return nextToken;
}

/* addChar - a function to add nextChar to lexeme */
void addChar() {
	if (lexLen <= 98) {
		lexeme[lexLen++] = nextChar;
		lexeme[lexLen] = 0;
	}
	else
 		printf("Error - lexeme is too long \n");
}

/* getChar - a function to get the next character of
 input and determine its character class */
void getChar() {
	int prevCharClass;
	if ((nextChar = getc(in_fp)) != EOF) {
		prevCharClass = charClass;
		if (isalpha(nextChar))
			charClass = LETTER;
		else{
			charClass = INVALID;
		}	
		if (isdigit(nextChar))
			charClass = DIGIT;
		else if(nextChar == '.')
			charClass = FLOAT_SEPARATOR;
		else 
			charClass = UNKNOWN;

		if(charClass == LETTER && prevCharClass){
			charClass = DIGIT;
		}
	}
 	else
 		charClass = EOF;
}

void getNonBlank() {
	while (isspace(nextChar))
		getChar();
}
/* lex - a simple lexical analyzer for arithmetic
 expressions */
int lex() {
	lexLen = 0;
	getNonBlank();
	switch (charClass) {
		/* Parse identifiers */
 		case LETTER:
			addChar();
			getChar();
			while (charClass == LETTER || charClass == DIGIT) {
				addChar();
				getChar();
			}
 			nextToken = IDENT;
 			break;
/* Parse integer literals */
 		case DIGIT:
			addChar();
			getChar();
			nextToken = INT_LIT;
			while (charClass == DIGIT || charClass ==  FLOAT_SEPARATOR) {
 				addChar();
 				getChar();
 				if (charClass == FLOAT_SEPARATOR){
 					nextToken = FLOAT_LIT;
 				}
 			}
			break;
/* Parentheses and operators */
		case UNKNOWN:
 			lookup(nextChar);
 			getChar();
 			break;
 		case INVALID:
 			addChar();
 			getChar();
 			break;
/* EOF */
 		case EOF:
			nextToken = EOF;
 			lexeme[0] = 'E';
 			lexeme[1] = 'O';
 			lexeme[2] = 'F';
			lexeme[3] = 0;
 			break;
 	} /* End of switch */
	printf("Next token is: %d, Next lexeme is %s\n",
		nextToken, lexeme);
	return nextToken;
} 
