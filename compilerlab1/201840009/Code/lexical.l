%option yylineno
%{
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "syntax.tab.h"
#include"node.h"
typedef int BOOL;
#define true 1
#define false 0
int right=true;
struct TN* newNode(char* name,char* text);
%}

digit       [0-9]
delim       [ \t\n\r]
letter      [a-zA-Z]
INT ([1-9][0-9]*)|0
FLOAT [0-9]+\.[0-9]+
ID [a-zA-Z][a-zA-Z0-9]*
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
COMMENT "//"
%%
{delim}      {;}
{STRUCT}  {yylval.node = newNode("STRUCT", yytext); return STRUCT;}
{RETURN}  {yylval.node = newNode("RETURN", yytext); return RETURN;}
{IF}      {yylval.node = newNode("IF", yytext); return IF;}
{ELSE}    {yylval.node = newNode("ELSE", yytext); return ELSE;}
{WHILE}   {yylval.node = newNode("WHILE", yytext); return WHILE;}
{TYPE}  {yylval.node = newNode("TYPE", yytext); return TYPE;}
{LP}    {yylval.node = newNode("LP", yytext); return LP;}
{RP}     {yylval.node = newNode("RP", yytext); return RP;}
{LB}   {yylval.node = newNode("LB", yytext); return LB;}
{RB}   {yylval.node = newNode("RB", yytext); return RB;}
{LC}     {yylval.node = newNode("LC", yytext); return LC;}
{RC}     {yylval.node = newNode("RC", yytext); return RC;}
{SEMI}     {yylval.node = newNode("SEMI", yytext); return SEMI;}
{COMMA}       {yylval.node = newNode("COMMA", yytext); return COMMA;}
{ASSIGNOP}       {yylval.node = newNode("ASSIGNOP", yytext); return ASSIGNOP;}
{RELOP} {yylval.node = newNode("RELOP", yytext); return RELOP;}
{PLUS}     {yylval.node = newNode("PLUS", yytext); return PLUS;}
{MINUS}       {yylval.node = newNode("MINUS", yytext); return MINUS;}
{STAR}     {yylval.node = newNode("STAR", yytext); return STAR;}
{DIV}     {yylval.node = newNode("DIV", yytext); return DIV;}
{AND}     {yylval.node = newNode("AND", yytext); return AND;}
{OR}    {yylval.node = newNode("OR", yytext); return OR;}
{DOT}     {yylval.node = newNode("DOT", yytext); return DOT;}
{NOT}       {yylval.node = newNode("NOT", yytext); return NOT;}
{ID}   {yylval.node = newNode("ID", yytext); return ID;}
{INT}       {yylval.node = newNode("INT", yytext); return INT;}
{FLOAT}   {yylval.node = newNode("FLOAT", yytext); return FLOAT;}
{COMMENT} {char getin=input(); while(getin!='\n') getin=input();}
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
.   {printf("Error type A at Line %d: Mysterious character \'%s\'.\n", yylineno, yytext); right = false;}
%%
struct TN* newNode(char* name,char* value)
{
    yylval.node=(struct TN*)malloc(sizeof(struct TN));
    yylval.node->node_line=yylineno;
    yylval.node->if_token=true;
    yylval.node->node_name = malloc((strlen(name) + 1) * sizeof(char));
    yylval.node->node_val = malloc((strlen(value) + 1) * sizeof(char));
    strcpy(yylval.node->node_name,name);
    strcpy(yylval.node->node_val,value);
    yylval.node->node_child=NULL;
    yylval.node->node_next=NULL;
}