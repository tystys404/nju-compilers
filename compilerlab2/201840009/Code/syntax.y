%{
    #include <stdio.h>
    #include "node.h"
    extern int syntax_errs;
    extern int yylineno;
    extern char* yytext;
    int yyerr_line=0;
    void yyerror(const char *msg);
    int yylex();
    #define YYDEBUG 1
    extern struct TN* root;
%}
%define parse.error verbose
%locations

%union {
    struct TN* node;
}
%token <node> INT FLOAT
%token <node> LP RP LB RB LC RC SEMI COMMA
%token <node> RELOP
%token <node> ASSIGNOP PLUS MINUS STAR DIV AND OR DOT NOT
%token <node> STRUCT RETURN IF ELSE WHILE TYPE error
%token <node> ID

%type <node> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier
%type <node> OptTag Tag VarDec FunDec VarList ParamDec CompSt
%type <node> StmtList Stmt DefList Def DecList Dec Exp Args

%start Program
%right ASSIGNOP
%left  OR
%left  AND
%left  RELOP
%left  PLUS MINUS
%left  STAR DIV
%right NOT
%left  DOT LP RP LB RB
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
/* High-level Definitions */
Program: ExtDefList                                 { $$=add_node("Program",@$.first_line,1,$1);root=$$; }
;               
ExtDefList: ExtDef ExtDefList                       { $$=add_node("ExtDefList",@$.first_line,2,$1,$2); }
    | /* empty */                                   { $$=NULL; }
;               
ExtDef: Specifier ExtDecList SEMI                   { $$=add_node("ExtDef",@$.first_line,3,$1,$2,$3); }
    | Specifier SEMI                                { $$=add_node("ExtDef",@$.first_line,2,$1,$2); }
    | Specifier FunDec CompSt                       { $$=add_node("ExtDef",@$.first_line,3,$1,$2,$3); }
    | error ExtDef                                  {} 
    | error CompSt                                  { yyerrok; }
    | error SEMI                                    { yyerrok; }
    | Specifier error SEMI                          { yyerrok; }
    | Specifier error CompSt                        { yyerrok; }
;               
ExtDecList: VarDec                                  { $$=add_node("ExtDecList",@$.first_line,1,$1); }
    | VarDec COMMA ExtDecList                       { $$=add_node("ExtDecList",@$.first_line,3,$1,$2,$3); }
;
/* Specifiers */
Specifier: TYPE                                     { $$=add_node("Specifier",@$.first_line,1,$1); }
    | StructSpecifier                               { $$=add_node("Specifier",@$.first_line,1,$1); }
;
StructSpecifier: STRUCT OptTag LC DefList RC        { $$=add_node("StructSpecifier",@$.first_line,5,$1,$2,$3,$4,$5); }
    | STRUCT Tag                                    { $$=add_node("StructSpecifier",@$.first_line,2,$1,$2); }
    | STRUCT OptTag LC DefList error RC             { yyerrok; }
;   
OptTag: ID                                          { $$=add_node("OptTag",@$.first_line,1,$1); }
    | /* empty */                                   { $$=NULL; }
;
Tag: ID                                             { $$=add_node("Tag",@$.first_line,1,$1); }
;
/* Declarators */
VarDec: ID                                          { $$=add_node("VarDec",@$.first_line,1,$1); }
    | VarDec LB INT RB                              { $$=add_node("VarDec",@$.first_line,4,$1,$2,$3,$4); }
;               
FunDec: ID LP VarList RP                            { $$=add_node("FunDec",@$.first_line,4,$1,$2,$3,$4); }
    | ID LP RP                                      { $$=add_node("FunDec",@$.first_line,3,$1,$2,$3); }
;
VarList: ParamDec COMMA VarList                     { $$=add_node("VarList",@$.first_line,3,$1,$2,$3); }
    | ParamDec                                      { $$=add_node("VarList",@$.first_line,1,$1); }
;
ParamDec: Specifier VarDec                          { $$=add_node("ParamDec",@$.first_line,2,$1,$2); }
;
/* Statements */
CompSt: LC DefList StmtList RC                      { $$=add_node("CompSt",@$.first_line,4,$1,$2,$3,$4); }
;
StmtList: Stmt StmtList                             { $$=add_node("StmtList",@$.first_line,2,$1,$2); }
    | /* empty */                                   { $$=NULL; }
;
Stmt: Exp SEMI                                      { $$=add_node("Stmt",@$.first_line,2,$1,$2); }
    | CompSt                                        { $$=add_node("Stmt",@$.first_line,1,$1); }
    | RETURN Exp SEMI                               { $$=add_node("Stmt",@$.first_line,3,$1,$2,$3); }
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE       { $$=add_node("Stmt",@$.first_line,5,$1,$2,$3,$4,$5); }
    | IF LP Exp RP Stmt ELSE Stmt                   { $$=add_node("Stmt",@$.first_line,7,$1,$2,$3,$4,$5,$6,$7); }
    | WHILE LP Exp RP Stmt                          { $$=add_node("Stmt",@$.first_line,5,$1,$2,$3,$4,$5); }                       
    | error SEMI                                    { yyerrok; }
    | error Stmt                                    { yyerrok; }
    | Exp error                                     { yyerrok; }
    | IF LP error RP Stmt %prec LOWER_THAN_ELSE     { yyerrok; }
    | IF LP error RP Stmt ELSE Stmt                 { yyerrok; }
    | WHILE LP error RP Stmt                        { yyerrok; }
;
/* Local Definitions */
DefList: Def DefList                                { $$=add_node("DefList",@$.first_line,2,$1,$2); }
    | /* empty */                                   { $$=NULL; }
;
Def: Specifier DecList SEMI                         { $$=add_node("Def",@$.first_line,3,$1,$2,$3); }
    | Specifier DecList error SEMI                  { yyerrok; }
    | Specifier error SEMI                          { yyerrok; }
;
DecList: Dec                                        { $$=add_node("DecList",@$.first_line,1,$1); }
    | Dec COMMA DecList                             { $$=add_node("DecList",@$.first_line,3,$1,$2,$3); }
;
Dec: VarDec                                         { $$=add_node("Dec",@$.first_line,1,$1); }
    | VarDec ASSIGNOP Exp                           { $$=add_node("Dec",@$.first_line,3,$1,$2,$3); }
;
/* Expressions */
Exp: Exp ASSIGNOP Exp                               { $$=add_node("Exp",@$.first_line,3,$1,$2,$3); }
    | Exp AND Exp                                   { $$=add_node("Exp",@$.first_line,3,$1,$2,$3); }
    | Exp OR Exp                                    { $$=add_node("Exp",@$.first_line,3,$1,$2,$3); }
    | Exp RELOP Exp                                 { $$=add_node("Exp",@$.first_line,3,$1,$2,$3); }
    | Exp PLUS Exp                                  { $$=add_node("Exp",@$.first_line,3,$1,$2,$3); }
    | Exp MINUS Exp                                 { $$=add_node("Exp",@$.first_line,3,$1,$2,$3); }
    | Exp STAR Exp                                  { $$=add_node("Exp",@$.first_line,3,$1,$2,$3); }
    | Exp DIV Exp                                   { $$=add_node("Exp",@$.first_line,3,$1,$2,$3); }
    | LP Exp RP                                     { $$=add_node("Exp",@$.first_line,3,$1,$2,$3); }
    | MINUS Exp                                     { $$=add_node("Exp",@$.first_line,2,$1,$2); }
    | NOT Exp                                       { $$=add_node("Exp",@$.first_line,2,$1,$2); }
    | ID LP Args RP                                 { $$=add_node("Exp",@$.first_line,4,$1,$2,$3,$4); }
    | ID LP RP                                      { $$=add_node("Exp",@$.first_line,3,$1,$2,$3); }
    | Exp LB Exp RB                                 { $$=add_node("Exp",@$.first_line,4,$1,$2,$3,$4); }
    | Exp DOT ID                                    { $$=add_node("Exp",@$.first_line,3,$1,$2,$3); }
    | ID                                            { $$=add_node("Exp",@$.first_line,1,$1); }
    | INT                                           { $$=add_node("Exp",@$.first_line,1,$1); }
    | FLOAT                                         { $$=add_node("Exp",@$.first_line,1,$1); }
    | Exp ASSIGNOP error                            { yyerrok; }  
    | Exp AND error                                 { yyerrok; }    
    | Exp OR error                                  { yyerrok; }    
    | Exp RELOP error                               { yyerrok; }    
    | Exp PLUS error                                { yyerrok; }    
    | Exp MINUS error                               { yyerrok; }  
    | Exp STAR error                                { yyerrok; }    
    | Exp DIV error                                 { yyerrok; }     
    | LP error RP                                   { yyerrok; }   
    | LP Exp error                                  { yyerrok; }             
    | NOT error                                     { yyerrok; }  
    | ID LP error RP                                { yyerrok; }  
    | Exp LB error RB                               { yyerrok; }  
;
Args: Exp COMMA Args                                { $$=add_node("Args",@$.first_line,3,$1,$2,$3); }
    | Exp                                           { $$=add_node("Args",@$.first_line,1,$1); }
    | error COMMA Exp                               { yyerrok; }
;
%%

#include "lex.yy.c"
void yyerror(const char *msg) {
    if(yyerr_line==yylineno)return;
    yyerr_line=yylineno;
    syntax_errs++;
    printf("Error type B at Line %d :%s.\n",yylineno,msg);
}