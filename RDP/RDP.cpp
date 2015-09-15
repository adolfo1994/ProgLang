#include <iostream>
#include <stdio.h>
using namespace std;

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

int nextToken;

void expr();
void term();
void factor();
void error();
/* expr
 Parses strings in the language generated by the rule:
 <expr> -> <term> {(+ | -) <term>}
 */
void expr() {
    printf("Enter <expr>\n");
    /* Parse the first term */
    term();
    /* As long as the next token is + or -, get
    the next token and parse the next term */
    while (nextToken == ADD_OP || nextToken == SUB_OP) {
        lex();
        term();
    }
    printf("Exit <expr>\n");
}

/* term
Parses strings in the language generated by the rule:
<term> -> <factor> {(* | /) <factor>)
*/
void term() {
    printf("Enter <term>\n");
    /* Parse the first factor */
    factor();
    /* As long as the next token is * or /, get the
    next token and parse the next factor */
    while (nextToken == MULT_OP || nextToken == DIV_OP) {
        lex();
        factor();
    }
    printf("Exit <term>\n");
} 

/* factor
Parses strings in the language generated by the rule:
<factor> -> id | int_constant | ( <expr )
*/
void factor() {
    printf("Enter <factor>\n");
    /* Determine which RHS */
    if (nextToken == IDENT || nextToken == INT_LIT)
        /* Get the next token */
        lex();
        /* If the RHS is ( <expr>), call lex to pass over the
        left parenthesis, call expr, and check for the right
        parenthesis */
    else {
        if (nextToken == LEFT_PAREN) {
            lex();
            expr();
            if (nextToken == RIGHT_PAREN)
                lex();
            else
                error();
        } else
            error();
    } /* End of else */
    printf("Exit <factor>\n");;
} 

 /* Function ifstmt
 Parses strings in the language generated by the rule:
 <ifstmt> -> if (<boolexpr>) <statement>
 [else <statement>]
 */
void ifstmt() {
    if (nextToken != IF_CODE)
        error();
    else {
        lex();
        if (nextToken != LEFT_PAREN)
            error();
         else {
            boolexpr();
            if (nextToken != RIGHT_PAREN)
                error();
            else {
                statement();
                if (nextToken == ELSE_CODE) {
                    lex();
                    statement();
                } 
            } 
        } 
    } 
} 

void error(){
    cout<<"Error"<<endl;
}

int main(int argc, char const *argv[])
{
    expr();
    return 0;
}