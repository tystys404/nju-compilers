#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <stdarg.h>
#include<stdbool.h>
#include "syntax.tab.h"
extern int right;
extern struct TN* tree_root;
extern int yyparse();
extern void yyrestart(FILE*);
extern void print_tree(struct TN* root,int depth);
int main(int argc, char** argv)
{
	if(argc <= 1) 
	{
		yyparse();
		return 1;
	}
	FILE* f = fopen(argv[1], "r");
	if (!f)
	{
		perror(argv[1]);
		return 1;
	}
	yyrestart(f);
	yyparse();
	fclose(f);
	if(right==true)
		print_tree(tree_root,0);
	return 0; 
}