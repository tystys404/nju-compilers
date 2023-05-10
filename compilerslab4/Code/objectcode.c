#include "objectcode.h"
Register rgsts[32];
char *regname[32] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra"};
int offsetcnt = 0;
int argcnt = 0;
int param_num = 0;
Offlist off_head = NULL;
void init_registers()
{
    for (int i = 0; i < 32; i++)
    {
        rgsts[i].name = regname[i];
        rgsts[i].if_used = false;
        rgsts[i].var = NULL;
    }
}
void init_offlist()
{
    offsetcnt = 0;
    off_head = NULL;
}
void print_offlist()
{
    Offlist tmp_head = off_head;
    while (tmp_head != NULL)
    {
        printf("operand offset,name:%s,offset:%d \n", tmp_head->var->name, tmp_head->var->offset);
        tmp_head = tmp_head->next;
    }
    return;
}
void insert_list(Varoff var)
{
    Offlist tmp_var = (Offlist)malloc(sizeof(struct Offlist_));
    tmp_var->var = var;
    tmp_var->next = off_head;
    off_head = tmp_var;
}
void addoptolist(Operand op)
{
    if (op->kind == OP_CONSTANT)
        return;
    if (get_offset(op) == NULL)
    {
        offsetcnt = offsetcnt - 4;
        Varoff tmp_var = (Varoff)malloc(sizeof(struct Varoff_));
        tmp_var->reg_num = -1;
        tmp_var->op = op;
        tmp_var->offset = offsetcnt;
        insert_list(tmp_var);
    }
}
int find_register(Operand op, FILE *outfile, bool if_load)
{
    int i = 0;
    for (i = 8; i <= 15; i++)
    {
        if (rgsts[i].if_used == false)
            break;
    }
    if (op->kind == OP_CONSTANT)
    {
        rgsts[i].if_used = true;
        rgsts[i].var = NULL;
        fprintf(outfile, "  li %s, %d\n", rgsts[i].name, op->u.value);
        return i;
    }
    else
    {
        printf("try to get offset\n");
        Varoff tmp_offset = get_offset(op);
        printf("get offset success\n");
        printf("tmp_off reg num:%d\n", tmp_offset->reg_num);
        printf("into print obj code\n");
        tmp_offset->reg_num = i;
        rgsts[i].if_used = true;
        rgsts[i].var = tmp_offset;
        if (if_load == true && (op->kind == OP_TMP || op->kind == OP_VARIABLE || op->kind == OP_ADDRESS))
        {
            fprintf(outfile, "  lw %s, %d($fp)\n", rgsts[i].name, tmp_offset->offset);
        }
        else if (op->kind == OP_ARRAY)
        {
            fprintf(outfile, "  addi %s, $fp, %d\n", rgsts[i].name, tmp_offset->offset);
        }
    }
    return i;
}
Varoff get_offset(Operand op)
{
    if (op->kind == OP_CONSTANT)
        return NULL;
    Offlist tmp_head = off_head;
    Varoff rt_off = NULL;
    int tmp_kind = op->kind;
    while (tmp_head != NULL)
    {
        if (tmp_head->var->op->kind != tmp_kind)
            tmp_head = tmp_head->next;
        else
        {
            if (op->kind == OP_VARIABLE && tmp_head->var->op->u.no_val == op->u.no_val)
                return tmp_head->var;
            else if (op->kind == OP_ARRAY && tmp_head->var->op->u.no_val == op->u.no_val)
                return tmp_head->var;
            else if (op->kind == OP_TMP && tmp_head->var->op->u.no_val == op->u.no_val)
                return tmp_head->var;
            else if (op->kind == OP_ADDRESS && tmp_head->var->op->u.no_addr == op->u.no_addr)
                return tmp_head->var;
            else if (op->kind == OP_VARIABLE || op->kind == OP_ARRAY || op->kind == OP_TMP || op->kind == OP_ADDRESS)
            {
                printf("no operation\n");
            }
            else
            {
                printf("unknown type:%d\n", op->kind);
                assert(0);
            }
            tmp_head = tmp_head->next;
        }
    }
    return rt_off;
}
void save_register(int reg_idx, FILE *outfile)
{
    if (rgsts[reg_idx].var == NULL)
        return;
    int tmp_offset = rgsts[reg_idx].var->offset;
    fprintf(outfile, "  sw %s, %d($fp)\n", rgsts[reg_idx].name, rgsts[reg_idx].var->offset);
    rgsts[reg_idx].if_used = false;
    rgsts[reg_idx].var = NULL;
}
void make_varoff(Operand op)
{
    if (op->kind == OP_CONSTANT)
        return;
    Varoff tmp_var = get_offset(op);
    if (tmp_var == NULL)
    {
        offsetcnt = offsetcnt + 4;
        Varoff newoff = (Varoff)malloc(sizeof(struct Varoff_));
        if (op->kind == OP_VARIABLE)
        {
            strcpy(newoff->name, op->u.name);
        }
        else if (op->kind == OP_TMP)
        {
            strcpy(newoff->name, op->u.name);
        }
        newoff->offset = -offsetcnt;
        insert_list(newoff);
    }
}
void gen_objcode(FILE *outfile)
{
    init_registers();
    init_offlist();
    // head
    fprintf(outfile, ".data\n");
    fprintf(outfile, "_prompt: .asciiz \"Enter an integer:\"\n");
    fprintf(outfile, "_ret: .asciiz \"\\n\"\n");
    fprintf(outfile, ".globl main\n");

    // read
    fprintf(outfile, ".text\n");
    fprintf(outfile, "read:\n");
    fprintf(outfile, "  li $v0, 4\n");
    fprintf(outfile, "  la $a0, _prompt\n");
    fprintf(outfile, "  syscall\n");
    fprintf(outfile, "  li $v0, 5\n");
    fprintf(outfile, "  syscall\n");
    fprintf(outfile, "  jr $ra\n");
    fprintf(outfile, "\n");

    // write
    fprintf(outfile, "write:\n");
    fprintf(outfile, "  li $v0, 1\n");
    fprintf(outfile, "  syscall\n");
    fprintf(outfile, "  li $v0, 4\n");
    fprintf(outfile, "  la $a0, _ret\n");
    fprintf(outfile, "  syscall\n");
    fprintf(outfile, "  move $v0, $0\n");
    fprintf(outfile, "  jr $ra\n");
    fprintf(outfile, "\n");
    // 现要初始化把operand加入符号表,不然可能会空NULL
    InterCodes tmp = doublelink->next;
    int flag = 0;
    while (tmp != doublelink || flag == 0)
    {
        int tmp_kind = tmp->code->kind;
        switch (tmp_kind)
        {
        case IR_LABEL:
            printf("transform IR_LABEL,cur flag:%d\n", flag);
            if (flag == 0)
            {
            }
            else
                gen_label_code(tmp->code, outfile);
            break;
        case IR_FUNCTION:
            printf("transform IR_FUNCTION\n");
            if (flag == 0)
            {
            }
            else
                gen_function_code(tmp->code, outfile);
            break;
        case IR_ASSIGN:
            printf("transform IR_ASSIGN\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.assign.left);
                addoptolist(tmp->code->u.assign.right);
            }
            else
                gen_assign_code(tmp->code, outfile);
            break;
        case IR_ADD:
            printf("transform IR_ADD\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.binop.res);
                addoptolist(tmp->code->u.binop.op1);
                addoptolist(tmp->code->u.binop.op2);
            }
            else
            {
                gen_add_code(tmp->code, outfile);
            }
            break;
        case IR_SUB:
            printf("transform IR_SUB\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.binop.res);
                addoptolist(tmp->code->u.binop.op1);
                addoptolist(tmp->code->u.binop.op2);
            }
            else
            {
                gen_sub_code(tmp->code, outfile);
            }
            break;
        case IR_MUL:
            printf("transform IR_MUL\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.binop.res);
                addoptolist(tmp->code->u.binop.op1);
                addoptolist(tmp->code->u.binop.op2);
            }
            else
            {
                gen_mul_code(tmp->code, outfile);
            }
            break;
        case IR_DIV:
            printf("transform IR_DIV\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.binop.res);
                addoptolist(tmp->code->u.binop.op1);
                addoptolist(tmp->code->u.binop.op2);
            }
            else
            {
                gen_div_code(tmp->code, outfile);
            }
            break;
        case IR_ADDR:
            printf("transform IR_ADDR\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.assign.left);
                addoptolist(tmp->code->u.assign.right);
            }
            else
            {
                gen_addr_code(tmp->code, outfile);
            }
            break;
        case IR_STAREQUAL:
            printf("transform IR_STAREQUAL\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.assign.left);
                addoptolist(tmp->code->u.assign.right);
            }
            else
            {
                gen_starequal_code(tmp->code, outfile);
            }
            break;
        case IR_EQUALSTAR:
            printf("transform IR_EQUALSTAR\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.assign.left);
                addoptolist(tmp->code->u.assign.right);
            }
            else
            {
                gen_equalstar_code(tmp->code, outfile);
            }
            break;
        case IR_GOTO:
            printf("transform IR_GOTO\n");
            if (flag == 1)
                gen_goto_code(tmp->code, outfile);
            break;
        case IR_RETURN:
            printf("transform IR_RETURN\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.sinop.op);
            }
            else
            {
                gen_return_code(tmp->code, outfile);
            }
            break;
        case IR_ARG:
            printf("transform IR_ARG\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.sinop.op);
            }
            else
            {
                gen_arg_code(tmp->code, outfile);
            }
            break;
        case IR_PARAM:
            printf("transform IR_PARAM\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.sinop.op);
                Varoff var = (Varoff)malloc(sizeof(struct Varoff_));
                var->reg_num = -1;
                var->op = tmp->code->u.sinop.op;
                var->offset = 8 + 4 * param_num++;
                insert_list(var);
            }
            else
            {
                gen_param_code(tmp->code, outfile);
            }
            break;
        case IR_READ:
            printf("transform IR_READ\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.sinop.op);
            }
            else
            {
                gen_read_code(tmp->code, outfile);
            }
            break;
        case IR_WRITE:
            printf("transform IR_WRITE\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.sinop.op);
            }
            else
            {
                gen_write_code(tmp->code, outfile);
            }
            break;
        case IR_DEC:
            printf("transform IR_DEC\n");
            if (flag == 0)
            {
                offsetcnt -= (tmp->code->u.decop.size - 4);
                addoptolist(tmp->code->u.decop.op);
            }
            else
            {
                gen_dec_code(tmp->code, outfile);
            }
            break;
        case IR_CALL:
            printf("transform IR_CALL\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.assign.left);
            }
            else
            {
                gen_call_code(tmp->code, outfile);
            }
            break;
        case IR_IFGOTO:
            printf("transform IR_IFGOTO\n");
            if (flag == 0)
            {
                addoptolist(tmp->code->u.gotorelop.x);
                addoptolist(tmp->code->u.gotorelop.y);
            }
            else
            {
                gen_ifgoto_code(tmp->code, outfile);
            }
            break;
        default:
            assert(0);
            break;
        }
        tmp = tmp->next;
        if (tmp == doublelink && flag == 0)
        {
            tmp = doublelink->next;
            flag = 1;
        }
    }
}
void gen_label_code(InterCode ir, FILE *outfile)
{
    fprintf(outfile, "  label%d:\n", ir->u.sinop.op->u.no_val);
}
void gen_function_code(InterCode ir, FILE *outfile)
{
    fprintf(outfile, "%s:\n", ir->u.sinop.op->u.name);
    fprintf(outfile, "  move $fp, $sp\n"); // 初始化帧指针
    fprintf(outfile, "  addi $sp, $sp, %d\n", offsetcnt);
}
void gen_assign_code(InterCode ir, FILE *outfile)
{
    printf("try to find register,left op kind:%d\n", ir->u.assign.left->kind);
    int reg1 = find_register(ir->u.assign.left, outfile, false);
    printf("find1 success\n");
    int reg2 = find_register(ir->u.assign.right, outfile, true);
    printf("find2 success\n");
    fprintf(outfile, "  move %s, %s\n", rgsts[reg1].name, rgsts[reg2].name);
    save_register(reg1, outfile);
    rgsts[reg2].if_used = false;
    rgsts[reg2].var = NULL;
}
void gen_add_code(InterCode ir, FILE *outfile)
{
    int op1_rgt = find_register(ir->u.binop.op1, outfile, true);
    int op2_rgt = find_register(ir->u.binop.op2, outfile, true);
    int res_rgt = find_register(ir->u.binop.res, outfile, false);
    fprintf(outfile, "  add %s, %s, %s\n", rgsts[res_rgt].name, rgsts[op1_rgt].name, rgsts[op2_rgt].name);
    save_register(res_rgt, outfile);
    rgsts[op1_rgt].if_used = false;
    rgsts[op1_rgt].var = NULL;
    rgsts[op2_rgt].if_used = false;
    rgsts[op2_rgt].var = NULL;
    return;
}
void gen_sub_code(InterCode ir, FILE *outfile)
{
    int op1_rgt = find_register(ir->u.binop.op1, outfile, true);
    int op2_rgt = find_register(ir->u.binop.op2, outfile, true);
    int res_rgt = find_register(ir->u.binop.res, outfile, false);
    fprintf(outfile, "  sub %s, %s, %s\n", rgsts[res_rgt].name, rgsts[op1_rgt].name, rgsts[op2_rgt].name);
    save_register(res_rgt, outfile);
    rgsts[op1_rgt].if_used = false;
    rgsts[op1_rgt].var = NULL;
    rgsts[op2_rgt].if_used = false;
    rgsts[op2_rgt].var = NULL;
    return;
}
void gen_mul_code(InterCode ir, FILE *outfile)
{
    int op1_rgt = find_register(ir->u.binop.op1, outfile, true);
    int op2_rgt = find_register(ir->u.binop.op2, outfile, true);
    int res_rgt = find_register(ir->u.binop.res, outfile, false);
    fprintf(outfile, "  mul %s, %s, %s\n", rgsts[res_rgt].name, rgsts[op1_rgt].name, rgsts[op2_rgt].name);
    save_register(res_rgt, outfile);
    rgsts[op1_rgt].if_used = false;
    rgsts[op1_rgt].var = NULL;
    rgsts[op2_rgt].if_used = false;
    rgsts[op2_rgt].var = NULL;
    return;
}
void gen_div_code(InterCode ir, FILE *outfile)
{
    int op1_rgt = find_register(ir->u.binop.op1, outfile, true);
    int op2_rgt = find_register(ir->u.binop.op2, outfile, true);
    int res_rgt = find_register(ir->u.binop.res, outfile, false);
    fprintf(outfile, "  div %s, %s\n", rgsts[op1_rgt].name, rgsts[op2_rgt].name);
    fprintf(outfile, "  mflo %s\n", rgsts[res_rgt].name);
    save_register(res_rgt, outfile);
    rgsts[op1_rgt].if_used = false;
    rgsts[op1_rgt].var = NULL;
    rgsts[op2_rgt].if_used = false;
    rgsts[op2_rgt].var = NULL;
    return;
}
void gen_addr_code(InterCode ir, FILE *outfile)
{
    printf("try to find register,left op kind:%d\n", ir->u.assign.left->kind);
    int reg1 = find_register(ir->u.assign.left, outfile, false);
    printf("find1 success\n");
    int reg2 = find_register(ir->u.assign.right, outfile, true);
    printf("find2 success\n");
    fprintf(outfile, "  move %s, %s\n", rgsts[reg1].name, rgsts[reg2].name);
    save_register(reg1, outfile);
    rgsts[reg2].if_used = false;
    rgsts[reg2].var = NULL;
}
void gen_starequal_code(InterCode ir, FILE *outfile)
{
    int rg1 = find_register(ir->u.assign.left, outfile, true);
    int rg2 = find_register(ir->u.assign.right, outfile, true);
    fprintf(outfile, "  sw %s, 0(%s)\n", rgsts[rg2].name, rgsts[rg1].name);
    rgsts[rg1].if_used = false;
    rgsts[rg2].if_used = false;
    rgsts[rg1].var = NULL;
    rgsts[rg2].var = NULL;
}
void gen_equalstar_code(InterCode ir, FILE *outfile)
{
    int rg1 = find_register(ir->u.assign.left, outfile, false);
    int rg2 = find_register(ir->u.assign.right, outfile, true);
    fprintf(outfile, "  lw %s, 0(%s)\n", rgsts[rg1].name, rgsts[rg2].name);
    rgsts[rg1].if_used = false;
    rgsts[rg2].if_used = false;
    rgsts[rg1].var = NULL;
    rgsts[rg2].var = NULL;
}
void gen_return_code(InterCode ir, FILE *outfile)
{
    int rg = find_register(ir->u.sinop.op, outfile, true);
    fprintf(outfile, "  move $v0, %s\n", rgsts[rg].name);
    fprintf(outfile, "  jr $ra\n");
    rgsts[rg].if_used = false;
    rgsts[rg].var = NULL;
}
void gen_arg_code(InterCode ir, FILE *outfile)
{
    int rg = find_register(ir->u.sinop.op, outfile, true);
    argcnt++;
    fprintf(outfile, "  addi $sp, $sp, -4\n");
    fprintf(outfile, "  sw %s, 0($sp)\n", rgsts[rg].name);
    rgsts[rg].if_used = false;
    rgsts[rg].var = NULL;
}
void gen_param_code(InterCode ir, FILE *outfile)
{
    return;
}
void gen_read_code(InterCode ir, FILE *outfile)
{
    int rg = find_register(ir->u.sinop.op, outfile, true);
    fprintf(outfile, "  addi $sp, $sp, -4\n");
    fprintf(outfile, "  sw $ra, 0($sp)\n");
    fprintf(outfile, "  jal read\n");
    fprintf(outfile, "  lw $ra, 0($sp)\n");
    fprintf(outfile, "  addi $sp, $sp, 4\n");
    fprintf(outfile, "\tmove %s, $v0\n", rgsts[rg].name);
    save_register(rg, outfile);
}
void gen_write_code(InterCode ir, FILE *outfile)
{
    int rg = find_register(ir->u.sinop.op, outfile, true);
    fprintf(outfile, "  move $a0, %s\n", rgsts[rg].name);
    fprintf(outfile, "  addi $sp, $sp, -4\n");
    fprintf(outfile, "  sw $ra, 0($sp)\n");
    fprintf(outfile, "  jal write\n");
    fprintf(outfile, "  lw $ra, 0($sp)\n");
    fprintf(outfile, "  addi $sp, $sp, 4\n");
    rgsts[rg].if_used = false;
    rgsts[rg].var = NULL;
}
void gen_dec_code(InterCode ir, FILE *outfile)
{
    return;
}
void gen_call_code(InterCode ir, FILE *outfile)
{
    fprintf(outfile, "  addi $sp, $sp, -8\n");
    fprintf(outfile, "  sw $fp, 0($sp)\n");
    fprintf(outfile, "  sw $ra, 4($sp)\n");
    fprintf(outfile, "  jal %s\n", ir->u.sinop.op->u.name);
    fprintf(outfile, "  move $sp, $fp\n");
    fprintf(outfile, "  lw $ra, 4($sp)\n");
    fprintf(outfile, "  lw $fp, 0($sp)\n");
    fprintf(outfile, "  addi $sp, $sp, %d\n", 8 + argcnt * 4);
    int rg = find_register(ir->u.assign.left, outfile, false);
    fprintf(outfile, "  move %s, $v0\n", rgsts[rg].name);
    save_register(rg, outfile);
    argcnt = 0;
}
void gen_ifgoto_code(InterCode ir, FILE *outfile)
{
    int rg1 = find_register(ir->u.gotorelop.x, outfile, true);
    int rg2 = find_register(ir->u.gotorelop.y, outfile, true);
    if (strcmp(ir->u.gotorelop.relop, "==") == 0)
    {
        fprintf(outfile, "  beq %s, %s, label%d\n", rgsts[rg1].name, rgsts[rg2].name, ir->u.gotorelop.z->u.no_val);
    }
    else if (strcmp(ir->u.gotorelop.relop, "!=") == 0)
    {
        fprintf(outfile, "  bne %s, %s, label%d\n", rgsts[rg1].name, rgsts[rg2].name, ir->u.gotorelop.z->u.no_val);
    }
    else if (strcmp(ir->u.gotorelop.relop, ">") == 0)
    {
        fprintf(outfile, "  bgt %s, %s, label%d\n", rgsts[rg1].name, rgsts[rg2].name, ir->u.gotorelop.z->u.no_val);
    }
    else if (strcmp(ir->u.gotorelop.relop, "<") == 0)
    {
        fprintf(outfile, "  blt %s, %s, label%d\n", rgsts[rg1].name, rgsts[rg2].name, ir->u.gotorelop.z->u.no_val);
    }
    else if (strcmp(ir->u.gotorelop.relop, ">=") == 0)
    {
        fprintf(outfile, "  bge %s, %s, label%d\n", rgsts[rg1].name, rgsts[rg2].name, ir->u.gotorelop.z->u.no_val);
    }
    else if (strcmp(ir->u.gotorelop.relop, "<=") == 0)
    {
        fprintf(outfile, "  ble %s, %s, label%d\n", rgsts[rg1].name, rgsts[rg2].name, ir->u.gotorelop.z->u.no_val);
    }
    rgsts[rg1].if_used = false;
    rgsts[rg1].var = NULL;
    rgsts[rg2].if_used = false;
    rgsts[rg2].var = NULL;
}
void gen_goto_code(InterCode ir, FILE *outfile)
{
    fprintf(outfile, "  j label%d\n", ir->u.sinop.op->u.no_val);
}