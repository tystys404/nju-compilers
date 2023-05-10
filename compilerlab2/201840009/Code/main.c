#include <stdio.h>

#include "semant.h"
#include "syntax.tab.h"

int syntax_errs = 0;
extern int yydebug;
struct TN *root;
int yylex();
int yyparse(void);
void yyrestart(FILE *input_file);
HashNode hashtable[TABLESIZE + 10];

int main(int argc, char **argv)
{
    FILE *yyin;
    if (argc == 1)
        return 1;
    if (argc > 1)
    {
        if (!(yyin = fopen(argv[1], "r")))
        {
            perror(argv[1]);
            return 1;
        }
        if (yydebug)
            printf("open file:%s\n", argv[1]);
    }
    yyrestart(yyin);
    yyparse();
    fclose(yyin);
    if (syntax_errs != 0)
    {
        /* meet erros */
        if (yydebug)
            printf("totally meet %d syntax errors\n", syntax_errs);
    }
    else
    {
        /* Print the AST tree */
        // print_tree(root, 0);
        Program(root);
    }
    return 0;
}