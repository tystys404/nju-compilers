%{
	#include<stdlib.h>
	#include<string.h>
	#include<stdio.h>
	#include <stdarg.h>
	#include "syntax.tab.h"
	#include "node.h"
	int yyerror(char* msg);
	struct TN* tree_root;
	extern int right;
	typedef int BOOL;
	#define true 1
	#define false 0
%}
%union 
{
    struct TN* node;
}
%token <node> INT
%token <node> FLOAT
%token <node> ID
%token <node> STRUCT RETURN IF ELSE WHILE
%token <node> TYPE
%token <node> SEMI COMMA 
%token <node> LC RC

%type <node> Program ExtDefList ExtDef Specifier ExtDecList FunDec CompSt VarDec StructSpecifier OptTag DefList Tag VarList ParamDec StmtList Exp Stmt Def DecList Dec Args

%right <node> ASSIGNOP
%left <node> OR
%left <node> AND
%left <node> RELOP
%left <node> PLUS MINUS
%left <node> STAR DIV
%right <node> NOT
%left <node> LP RP LB RB DOT
%nonassoc LOWER_THAN_ELSE
%nonassoc  ELSE

%%
Program: ExtDefList {$$=add_node("Program",1,$1);tree_root=$$;};
ExtDefList: ExtDef ExtDefList {$$=add_node("ExtDefList",2,$1,$2);}
    | {$$=NULL;};
ExtDef : Specifier ExtDecList SEMI {$$ = add_node("ExtDef",3,$1,$2,$3);}
	| Specifier SEMI {$$ = add_node("ExtDef",2,$1,$2);}
	| Specifier FunDec CompSt {$$ = add_node("ExtDef",3,$1,$2,$3);}
	| error ExtDef {}
    | error CompSt {right = false;}
    | Specifier error SEMI {right = false;}
    | Specifier error CompSt {right = false;}
	| error SEMI {right = false;};
ExtDecList:VarDec {$$=add_node("ExDecList",1,$1);}
    | VarDec COMMA ExtDecList {$$=add_node("ExDecList",3,$1,$2,$3);};
Specifier:TYPE {$$=add_node("Specifier",1,$1);}
    | StructSpecifier {$$=add_node("Specifier",1,$1);};
StructSpecifier:STRUCT OptTag LC DefList RC {$$=add_node("StructSpecifier",5,$1,$2,$3,$4,$5);}
    | STRUCT Tag {$$=add_node("StructSpecifier",2,$1,$2);};
OptTag: ID {$$=add_node("OptTag",1,$1);}
    | {$$=NULL;};
Tag : ID {$$ = add_node("Tag",1,$1);};
VarDec : ID	{$$ = add_node("VarDec",1,$1);}
	| VarDec LB INT RB {$$ = add_node("VarDec",4,$1,$2,$3,$4);}
	| error RB {right=false;};
FunDec : ID LP VarList RP {$$ = add_node("FunDec",4,$1,$2,$3,$4);}
	| ID LP RP {$$ = add_node("FunDec",3,$1,$2,$3);}
	| error RP {right=false;};
VarList : ParamDec COMMA VarList {$$ = add_node("VarList",3,$1,$2,$3);}
	| ParamDec {$$ = add_node("VarList",1,$1);};
ParamDec : Specifier VarDec	{$$ = add_node("ParamDec",2,$1,$2);};
CompSt : LC DefList StmtList RC {$$ = add_node("CompSt",4,$1,$2,$3,$4);}
	| error RC {right=false;};
StmtList : Stmt StmtList {$$ = add_node("StmtList",2,$1,$2);}
	| {$$ = NULL;};
Stmt : Exp SEMI	{$$ = add_node("Stmt",2,$1,$2);}
	| error SEMI {right=false;}
	| CompSt {$$ = add_node("Stmt",1,$1);}
	| RETURN Exp SEMI {$$ = add_node("Stmt",3,$1,$2,$3);}	
	| IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {$$ = add_node("Stmt",5,$1,$2,$3,$4,$5);}
	| IF LP Exp RP Stmt ELSE Stmt {$$ = add_node("Stmt",7,$1,$2,$3,$4,$5,$6,$7);}
	| WHILE LP Exp RP Stmt {$$ = add_node("Stmt",5,$1,$2,$3,$4,$5);};
DefList : Def DefList {$$ = add_node("DefList",2,$1,$2);}
	| {$$ = NULL;}; 	
Def : Specifier DecList SEMI {$$ = add_node("Def",3,$1,$2,$3);}
DecList : Dec {$$ = add_node("DecList",1,$1);}
	| Dec COMMA DecList	{$$ = add_node("DecList",3,$1,$2,$3);};
Dec : VarDec {$$ = add_node("Dec",1,$1);}
	| VarDec ASSIGNOP Exp {$$ = add_node("Dec",3,$1,$2,$3);};
Exp : Exp ASSIGNOP Exp {$$ = add_node("Exp",3,$1,$2,$3);}
	| Exp AND Exp {$$ = add_node("Exp",3,$1,$2,$3);}
	| Exp OR Exp {$$ = add_node("Exp",3,$1,$2,$3);}
	| Exp RELOP Exp	{$$ = add_node("Exp",3,$1,$2,$3);}
	| Exp PLUS Exp {$$ = add_node("Exp",3,$1,$2,$3);}
	| Exp MINUS Exp	{$$ = add_node("Exp",3,$1,$2,$3);}
	| Exp STAR Exp {$$ = add_node("Exp",3,$1,$2,$3);}
	| Exp DIV Exp {$$ = add_node("Exp",3,$1,$2,$3);}
	| LP Exp RP	{$$ = add_node("Exp",3,$1,$2,$3);}
	| MINUS Exp	{$$ = add_node("Exp",2,$1,$2);}
	| NOT Exp {$$ = add_node("Exp",2,$1,$2);}
	| ID LP Args RP	{$$ = add_node("Exp",4,$1,$2,$3,$4);}
	| ID LP RP {$$ = add_node("Exp",3,$1,$2,$3);}
	| Exp LB Exp RB	{$$ = add_node("Exp",4,$1,$2,$3,$4);}
	| Exp DOT ID {$$ = add_node("Exp",3,$1,$2,$3);}
	| ID {$$ = add_node("Exp",1,$1);}
	| INT {$$ = add_node("Exp",1,$1);}
	| FLOAT {$$ = add_node("Exp",1,$1);};
Args : Exp COMMA Args {$$ = add_node("Args",3,$1,$2,$3);}
	| Exp {$$ = add_node("Args",1,$1);};
%%
#include "lex.yy.c"
int yyerror(char* msg)
{
	fprintf(stderr, "Error type B at line %d:%s\n",yylineno,msg);
	return 0;
}