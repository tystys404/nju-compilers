%{
#include "syntax.tab.h"
#include "node.h"
extern YYSTYPE yylval;
int yycolumn = 1;
extern int yydebug;
#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;
int yylex();
bool right=true;
%}

%option yylineno
DIGIT [0-9]
letter [a-zA-Z]
unsignedint [1-9]{DIGIT}*
LP "(" 
RP ")"
LB "["
RB "]"
LC "{"
RC "}"
SEMI ";"
COMMA ","
RELOP ">="|"<="|"=="|">"|"<"|"!="
ASSIGNOP "="
PLUS "+"
MINUS "-"
STAR "*"
DIV "/"
AND "&&"
OR "||"
NOT "!"
STRUCT "struct"
RETURN "return"
IF "if"
ELSE "else"
WHILE "while"
TYPE "int"|"float"
DOT "."

ID ({letter}|_)({letter}|_|{DIGIT})*
INT (0|{unsignedint})
FLOAT ([0-9]+\.[0-9]+)|((([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+))[eE][+-]?[0-9]+)
WS [ \t\r]+

%x INLINE_COMMENT
%%
{SEMI}                              { yylval.node=newNode("SEMI", 4, NULL);return SEMI; }
{COMMA}                             { yylval.node=newNode("COMMA", 4, NULL);return COMMA; }
{RELOP}                             { yylval.node=newNode("RELOP", 4, NULL);return RELOP; }
{ASSIGNOP}                          { yylval.node=newNode("ASSIGNOP", 4, NULL);return ASSIGNOP; }
{PLUS}                              { yylval.node=newNode("PLUS", 4, NULL);return PLUS; }
{MINUS}                             { yylval.node=newNode("MINUS", 4, NULL);return MINUS; }
{STAR}                              { yylval.node=newNode("STAR", 4, NULL); return STAR; }
{DIV}                               { yylval.node=newNode("DIV", 4, NULL); return DIV;}
{AND}                               { yylval.node=newNode("AND", 4, NULL);return AND; }
{OR}                                { yylval.node=newNode("OR", 4, NULL);return OR; }
{DOT}                               { yylval.node=newNode("DOT", 4, NULL);return DOT; }
{NOT}                               { yylval.node=newNode("NOT", 4, NULL);return NOT; }
{TYPE}                              { yylval.node=newNode("TYPE", 3, yytext);return TYPE; }
{LP}                                { yylval.node=newNode("LP", 4, NULL);return LP; }
{RP}                                { yylval.node=newNode("RP", 4, NULL);return RP; }
{LB}                                { yylval.node=newNode("LB", 4, NULL);return LB; }
{RB}                                { yylval.node=newNode("RB", 4, NULL);return RB; }
{LC}                                { yylval.node=newNode("LC", 4, NULL);return LC; }
{RC}                                { yylval.node=newNode("RC", 4, NULL);return RC; }
{STRUCT}                            { yylval.node=newNode("STRUCT", 4, NULL);return STRUCT; }
{RETURN}                            { yylval.node=newNode("RETURN", 4, NULL);return RETURN; }
{IF}                                { yylval.node=newNode("IF", 4, NULL);return IF; }
{ELSE}                              { yylval.node=newNode("ELSE", 4, NULL);return ELSE; }
{WHILE}                             { yylval.node=newNode("WHILE", 4, NULL);return WHILE; }
{INT}                               { yylval.node=newNode("INT", 0, yytext);return INT; }
{FLOAT}                             { yylval.node=newNode("FLOAT", 1, yytext);return FLOAT; }
{ID}                                { yylval.node=newNode("ID", 2, yytext);return ID; }
{WS}	                            {}
"\n"                                { yycolumn = 1; }
.                                   {printf("Error type A at Line %d: Mysterious character \'%s\'.\n", yylineno, yytext); right = false;}
<<EOF>>                             { return 0; }
"/*" {
    char c;
    c=input();
    while (c!= '\0') {
        if (c == '*') {
            while (c == '*') c=input();
            if (c == '/') {
                break;
            }
        }
        c=input();
    }
    if (c == '\0') 
    {
        printf("Error type B at Line %d: Syntax error.\n",yylineno);
        right=1;    
    }
}
"*/"                                { printf("Error type A at Line %d: %s %s.\n", yylineno, "illegal comment" ,yytext); }
"//"                                { BEGIN(INLINE_COMMENT); }
<INLINE_COMMENT>[^\n]*              {}
<INLINE_COMMENT>\n                  { BEGIN(INITIAL); }
%%