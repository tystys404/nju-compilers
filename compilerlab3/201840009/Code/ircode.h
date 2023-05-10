#ifndef _IRCODE_H_
#define _IRCODE_H_
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"
#include "semant.h"
typedef struct TN *Tnode;
typedef struct Operand_ *Operand;
typedef struct InterCode_ *InterCode;
typedef struct InterCodes_ *InterCodes;
struct InterCodes_
{
    InterCode code;
    InterCodes prev, next;
};
struct Operand_
{
    enum
    {
        OP_VARIABLE,
        OP_CONSTANT,
        OP_ADDRESS,
        OP_LABEL,
        OP_FUNCTION,
        OP_ARRAY,
        OP_STRUCTURE,
        OP_TMP,
    } kind;
    union
    {
        int no_val;
        int value;
        char name[50];
        int no_addr;
    } u;
    Type type;         // 存储结构体或者数组
    int size;          // 如果存储结构体,那么就存储大小
    bool is_structure; // 表示是不是结构体
    int base_offset;   // 初始自带的offset
};
struct InterCode_
{
    enum
    {
        IR_LABEL,
        IR_FUNCTION,
        IR_ASSIGN,
        IR_ADD,
        IR_SUB,
        IR_MUL,
        IR_DIV,
        IR_ADDR,
        IR_STAREQUAL, //*x=y
        IR_EQUALSTAR, // x=*y
        IR_GOTO,
        IR_RETURN,
        IR_ARG,
        IR_PARAM,
        IR_READ,
        IR_WRITE,
        IR_DEC,
        IR_CALL,
        IR_IFGOTO,
    } kind;
    union
    {
        struct
        {
            Operand right, left;
        } assign;
        struct
        {
            Operand res, op1, op2;
        } binop;
        struct
        {
            Operand op;
        } sinop;
        struct
        {
            Operand x, y, z;
            char relop[50];
        } gotorelop;
        struct
        {
            Operand op;
            int size;
        } decop;
    } u;
};
// tool functions
void print_operand(Operand op);
void print_intercode(InterCodes global_ir);
void print_irlist(InterCodes root_head);
InterCodes make_intercodes(InterCode ir_code, InterCodes prev_codes, InterCodes next_codes);
Operand make_operand(int op_kind, int val, int number, char *name);
InterCode make_ir(InterCodes root_head, int ir_kind, ...);
void addtocodes(InterCodes root_head, InterCode ir_code);
int get_size(Type type);
int my_min(int a, int b);
Operand new_temp();
Operand new_addr();
Operand new_label();
void make_assign(int ir_kind, Operand op1, Operand op2);
void make_binop(int ir_kind, Operand res, Operand op1, Operand op2);
void make_sinop(int ir_kind, Operand op);
void make_gotorelop(int ir_kind, Operand op1, Operand op2, Operand op3, char *name);
void make_decop(int ir_kind, Operand op, int size);
// translation functions
void translate_Program(Tnode root);
void translate_ExtDefList(Tnode root);
void translate_ExtDef(Tnode root);
void translate_ExtDecList(Tnode root);
void translate_FunDec(Tnode root);
void translate_VarList(Tnode root);
void translate_ParamDec(Tnode root);
void translate_CompSt(Tnode root);
void translate_Def(Tnode root);
void translate_DefList(Tnode root);
void translate_StmtList(Tnode root);
void translate_Stmt(Tnode root);
void translate_Dec(Tnode root);
void translate_Assign(Operand op1, Operand t1);
void translate_DecList(Tnode root);
Operand translate_VarDec(Tnode root);
Operand translate_Exp(Tnode root, Operand place, bool if_load);
void translate_Args(Tnode root, bool write_flag);
void translate_Cond(Tnode root, Operand label_true, Operand label_false);
#endif