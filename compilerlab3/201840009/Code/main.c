#include <stdio.h>
#include "ircode.h"
#include "semant.h"
#include "syntax.tab.h"

int syntax_errs = 0;
int semant_err = 0;
InterCodes doublelink;
extern int yydebug;
struct TN *root;
FILE *ir_out;
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
        if (!(ir_out = fopen(argv[2], "w")))
        {
            perror(argv[2]);
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
        if (semant_err == 0)
        {
            translate_Program(root);
            // gen_ir(doublelink, IR_LABEL, gen_operand(OP_CONSTANT, 2, -1, NULL), NULL, NULL, -1, NULL);
            // gen_ir(doublelink, IR_ASSIGN, gen_operand(OP_CONSTANT, 2, -1, NULL), gen_operand(OP_CONSTANT, 3, -1, NULL), NULL, -1, NULL);
            // gen_ir(doublelink, IR_SUB, gen_operand(OP_CONSTANT, 2, -1, NULL), gen_operand(OP_CONSTANT, 3, -1, NULL), gen_operand(OP_CONSTANT, 4, -1, NULL), -1, NULL);
            print_irlist(doublelink);
        }
    }
    return 0;
}