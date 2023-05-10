#ifndef __OBJECTCODE_H__
#define __OBJECTCODE_H__
#include "semant.h"
#include "node.h"
#include "ircode.h"
#include <stdbool.h>
extern InterCodes doublelink;
typedef struct Varoff_ *Varoff;
typedef struct Offlist_ *Offlist;
typedef struct Register_ Register;
struct Varoff_
{
    char name[50];
    int reg_num;
    int offset;
    Operand op;
};
struct Offlist_
{
    Varoff var;
    Offlist next;
};
struct Register_
{
    bool if_used;
    char *name;
    Varoff var;
}; // registers
void init_registers();
void init_offlist();
void print_offlist();
void insert_list(Varoff var);
void addoptolist(Operand op);
int find_register(Operand op, FILE *outfile, bool if_load);
Varoff get_offset(Operand op);
void save_register(int reg_idx, FILE *outfile);
void make_varoff(Operand op);
void gen_objcode(FILE *outfile);
void gen_label_code(InterCode ir, FILE *outfile);
void gen_function_code(InterCode ir, FILE *outfile);
void gen_assign_code(InterCode ir, FILE *outfile);
void gen_add_code(InterCode ir, FILE *outfile);
void gen_sub_code(InterCode ir, FILE *outfile);
void gen_mul_code(InterCode ir, FILE *outfile);
void gen_div_code(InterCode ir, FILE *outfile);
void gen_addr_code(InterCode ir, FILE *outfile);
void gen_starequal_code(InterCode ir, FILE *outfile);
void gen_equalstar_code(InterCode ir, FILE *outfile);
void gen_return_code(InterCode ir, FILE *outfile);
void gen_param_code(InterCode ir, FILE *outfile);
void gen_read_code(InterCode ir, FILE *outfile);
void gen_write_code(InterCode ir, FILE *outfile);
void gen_dec_code(InterCode ir, FILE *outfile);
void gen_call_code(InterCode ir, FILE *outfile);
void gen_arg_code(InterCode ir, FILE *outfile);
void gen_ifgoto_code(InterCode ir, FILE *outfile);
void gen_goto_code(InterCode ir, FILE *outfile);
#endif