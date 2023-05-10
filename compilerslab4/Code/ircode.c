#include "ircode.h"
#include "semant.h"
#include "node.h"
#include <stdarg.h>
extern FILE *ir_out;
extern InterCodes doublelink;
int tempNo = 1;  // 临时变量编号
int labelNo = 1; // 跳转编号
int addrNo = 1;  // 地址编号
int varNo = 1;
int irdebug = 1;
int struct_num = 0;
void print_operand(Operand op)
{
    switch (op->kind)
    {
    case OP_VARIABLE:
        fprintf(ir_out, "var%d ", op->u.no_val);
        break;
    case OP_CONSTANT:
        fprintf(ir_out, "#%d ", op->u.value);
        break;
    case OP_ADDRESS:
        fprintf(ir_out, "addr%d ", op->u.no_addr);
        break;
    case OP_LABEL:
        fprintf(ir_out, "label%d ", op->u.no_val);
        break;
    case OP_FUNCTION:
        fprintf(ir_out, "%s ", op->u.name);
        break;
    case OP_ARRAY:
        fprintf(ir_out, "array%d ", op->u.no_val);
        break;
    case OP_TMP:
        fprintf(ir_out, "t%d ", op->u.no_val);
        break;
    case OP_STRUCTURE:
        fprintf(ir_out, "structure%d ", op->u.no_val);
        break;
    defalut:
        fprintf(ir_out, "not an operand");
        break;
    }
}
void print_intercode(InterCodes global_ir)
{
    switch (global_ir->code->kind)
    {
    case IR_LABEL:
        fprintf(ir_out, "LABEL ");
        print_operand(global_ir->code->u.sinop.op);
        fprintf(ir_out, ": ");
        break;
    case IR_FUNCTION:
        fprintf(ir_out, "FUNCTION ");
        print_operand(global_ir->code->u.sinop.op);
        fprintf(ir_out, ": ");
        break;
    case IR_ASSIGN:
        print_operand(global_ir->code->u.assign.left);
        fprintf(ir_out, " := ");
        print_operand(global_ir->code->u.assign.right);
        break;
    case IR_ADD:
        print_operand(global_ir->code->u.binop.res);
        fprintf(ir_out, " := ");
        print_operand(global_ir->code->u.binop.op1);
        fprintf(ir_out, " + ");
        print_operand(global_ir->code->u.binop.op2);
        break;
    case IR_SUB:
        print_operand(global_ir->code->u.binop.res);
        fprintf(ir_out, " := ");
        print_operand(global_ir->code->u.binop.op1);
        fprintf(ir_out, " - ");
        print_operand(global_ir->code->u.binop.op2);
        break;
    case IR_MUL:
        print_operand(global_ir->code->u.binop.res);
        fprintf(ir_out, ":= ");
        print_operand(global_ir->code->u.binop.op1);
        fprintf(ir_out, " * ");
        print_operand(global_ir->code->u.binop.op2);
        break;
    case IR_DIV:
        print_operand(global_ir->code->u.binop.res);
        fprintf(ir_out, " := ");
        print_operand(global_ir->code->u.binop.op1);
        fprintf(ir_out, " / ");
        print_operand(global_ir->code->u.binop.op2);
        break;
    case IR_ADDR:
        print_operand(global_ir->code->u.assign.left);
        fprintf(ir_out, " := &");
        print_operand(global_ir->code->u.assign.right);
        break;
    case IR_STAREQUAL:
        fprintf(ir_out, "*");
        print_operand(global_ir->code->u.assign.left);
        fprintf(ir_out, " := ");
        print_operand(global_ir->code->u.assign.right);
        break;
    case IR_EQUALSTAR:
        print_operand(global_ir->code->u.assign.left);
        fprintf(ir_out, " := *");
        print_operand(global_ir->code->u.assign.right);
        break;
    case IR_GOTO:
        fprintf(ir_out, "GOTO ");
        print_operand(global_ir->code->u.sinop.op);
        // fprintf(ir_out, ":");
        break;
    case IR_RETURN:
        fprintf(ir_out, "RETURN ");
        print_operand(global_ir->code->u.sinop.op);
        break;
    case IR_ARG:
        fprintf(ir_out, "ARG ");
        print_operand(global_ir->code->u.sinop.op);
        break;
    case IR_PARAM:
        fprintf(ir_out, "PARAM ");
        print_operand(global_ir->code->u.sinop.op);
        break;
    case IR_READ:
        fprintf(ir_out, "READ ");
        print_operand(global_ir->code->u.sinop.op);
        break;
    case IR_WRITE:
        fprintf(ir_out, "WRITE ");
        print_operand(global_ir->code->u.sinop.op);
        break;
    case IR_DEC:
        fprintf(ir_out, "DEC ");
        print_operand(global_ir->code->u.decop.op);
        fprintf(ir_out, " ");
        fprintf(ir_out, "%d", global_ir->code->u.decop.size);
        break;
    case IR_CALL:
        print_operand(global_ir->code->u.assign.left);
        fprintf(ir_out, " := CALL ");
        print_operand(global_ir->code->u.assign.right);
        break;
    case IR_IFGOTO:
        fprintf(ir_out, "IF ");
        print_operand(global_ir->code->u.gotorelop.x);
        // fprintf(ir_out, " ");
        fprintf(ir_out, "%s", global_ir->code->u.gotorelop.relop);
        fprintf(ir_out, " ");
        print_operand(global_ir->code->u.gotorelop.y);
        fprintf(ir_out, "GOTO ");
        print_operand(global_ir->code->u.gotorelop.z);
        break;
    default:
        fprintf(ir_out, "not an intercode");
        assert(0);
        break;
    }
}
void print_irlist(InterCodes root_head)
{
    InterCodes tmp = root_head->next;
    while (tmp != root_head)
    {
        int flag = 0;
        if (tmp->code->kind == IR_ASSIGN)
        {
            Operand left = tmp->code->u.assign.left;
            Operand right = tmp->code->u.assign.right;
            if (left->kind == right->kind && left->u.no_val == right->u.no_val)
            {
                InterCodes tmp_last = tmp->prev;
                tmp_last->next = tmp->next;
                tmp = tmp_last;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            print_intercode(tmp);
            fprintf(ir_out, "\n");
        }
        tmp = tmp->next;
    }
}
InterCodes make_intercodes(InterCode ir_code, InterCodes prev_codes, InterCodes next_codes)
{
    InterCodes new_tmp = (InterCodes)malloc(sizeof(struct InterCodes_));
    new_tmp->code = ir_code;
    new_tmp->prev = prev_codes;
    new_tmp->next = next_codes;
    return new_tmp;
}
Operand make_operand(int op_kind, int val, int number, char *name)
{
    Operand cur = (Operand)malloc(sizeof(struct Operand_));
    cur->kind = op_kind;
    FieldList tmp_fd = NULL;
    switch (op_kind)
    {
    case OP_VARIABLE:
        tmp_fd = search_node(name);
        cur->u.no_val = tmp_fd->index;
        break;
    case OP_CONSTANT:
        cur->u.value = val;
        break;
    case OP_ADDRESS:
        cur->u.no_addr = number;
        break;
    case OP_LABEL:
        cur->u.no_val = number;
        break;
    case OP_FUNCTION:
        strcpy(cur->u.name, name);
        break;
    case OP_ARRAY:
        tmp_fd = search_node(name);
        cur->u.no_val = tmp_fd->index;
        break;
    case OP_STRUCTURE:
        tmp_fd = search_node(name);
        printf("get index\n");
        // cur->u.no_val = struct_num++;
        cur->u.no_val = tmp_fd->index;
        printf("index correct:%d\n", cur->u.no_val);
        break;
    case OP_TMP:
        cur->u.no_val = number;
        break;
    default:
        break;
    }
    return cur;
}
InterCode make_ir(InterCodes root_head, int ir_kind, ...)
{
    va_list argp;
    va_start(argp, ir_kind);
    if (ir_kind == IR_LABEL || ir_kind == IR_FUNCTION || ir_kind == IR_GOTO || ir_kind == IR_RETURN || ir_kind == IR_ARG || ir_kind == IR_PARAM || ir_kind == IR_READ || ir_kind == IR_WRITE)
    {
        Operand op1 = va_arg(argp, Operand);
        make_sinop(ir_kind, op1);
    }
    else if (ir_kind == IR_ASSIGN || ir_kind == IR_ADDR || ir_kind == IR_EQUALSTAR || ir_kind == IR_STAREQUAL || ir_kind == IR_CALL)
    {
        Operand op1 = va_arg(argp, Operand);
        Operand op2 = va_arg(argp, Operand);
        make_assign(ir_kind, op1, op2);
    }
    else if (ir_kind == IR_DEC)
    {
        Operand op1 = va_arg(argp, Operand);
        int dec_size = va_arg(argp, int);
        make_decop(ir_kind, op1, dec_size);
    }
    else if (ir_kind == IR_ADD || ir_kind == IR_SUB || ir_kind == IR_MUL || ir_kind == IR_DIV)
    {
        Operand op1 = va_arg(argp, Operand);
        Operand op2 = va_arg(argp, Operand);
        Operand op3 = va_arg(argp, Operand);
        make_binop(ir_kind, op1, op2, op3);
    }
    else if (ir_kind == IR_IFGOTO)
    {
        Operand op1 = va_arg(argp, Operand);
        Operand op2 = va_arg(argp, Operand);
        Operand op3 = va_arg(argp, Operand);
        char *relop = va_arg(argp, char *);
        make_gotorelop(ir_kind, op1, op2, op3, relop);
    }
    else
        exit(-1);
}
void make_assign(int ir_kind, Operand op1, Operand op2)
{
    InterCode cur = (InterCode)malloc(sizeof(struct InterCode_));
    cur->kind = ir_kind;
    if (op1 == NULL || op2 == NULL)
        return;
    cur->u.assign.left = op1;
    cur->u.assign.right = op2;
    addtocodes(doublelink, cur);
}
void make_binop(int ir_kind, Operand res, Operand op1, Operand op2)
{
    InterCode cur = (InterCode)malloc(sizeof(struct InterCode_));
    cur->kind = ir_kind;
    if (op1 == NULL || op2 == NULL || res == NULL)
        return;
    cur->u.binop.res = res;
    cur->u.binop.op1 = op1;
    cur->u.binop.op2 = op2;
    addtocodes(doublelink, cur);
}
void make_sinop(int ir_kind, Operand op)
{
    InterCode cur = (InterCode)malloc(sizeof(struct InterCode_));
    cur->kind = ir_kind;
    if (op == NULL)
        return;
    cur->u.sinop.op = op;
    addtocodes(doublelink, cur);
}
void make_gotorelop(int ir_kind, Operand op1, Operand op2, Operand op3, char *name)
{
    InterCode cur = (InterCode)malloc(sizeof(struct InterCode_));
    cur->kind = ir_kind;
    if (op1 == NULL || op2 == NULL || op3 == NULL || name == NULL)
        return;
    cur->u.gotorelop.x = op1;
    cur->u.gotorelop.y = op2;
    cur->u.gotorelop.z = op3;
    strcpy(cur->u.gotorelop.relop, name);
    addtocodes(doublelink, cur);
}
void make_decop(int ir_kind, Operand op, int size)
{
    InterCode cur = (InterCode)malloc(sizeof(struct InterCode_));
    cur->kind = ir_kind;
    if (op == NULL)
        return;
    cur->u.decop.op = op;
    cur->u.decop.size = size;
    addtocodes(doublelink, cur);
}
void addtocodes(InterCodes root_head, InterCode ir_code)
{
    InterCodes tail = root_head->prev;
    InterCodes new_Tnode = make_intercodes(ir_code, tail, root_head);
    tail->next = new_Tnode;
    root_head->prev = new_Tnode;
}
Operand new_temp()
{
    return make_operand(OP_TMP, -1, tempNo++, NULL);
}
Operand new_addr()
{
    return make_operand(OP_ADDRESS, -1, addrNo++, NULL);
}
Operand new_label()
{
    return make_operand(OP_LABEL, -1, labelNo++, NULL);
}
int childnum(Tnode root)
{
    int i = 0;
    Tnode tmp = root->childs[0];
    while (tmp != NULL)
    {
        i++;
        tmp = root->childs[i];
    }
    return root->child_num;
}
int my_divide(int dividend, int divisor)
{
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; // 确定商的符号
    long long dvd = labs(dividend);                       // 转化为 long long 防止溢出
    long long dvs = labs(divisor);
    int quotient = 0;
    while (dvd >= dvs)
    {
        long long tmp = dvs, multiple = 1;
        while (dvd >= (tmp << 1))
        {
            tmp <<= 1;      // 倍增除数
            multiple <<= 1; // 对应倍增的商
        }
        dvd -= tmp;           // 减去倍增后最大的小于被除数的除数
        quotient += multiple; // 加上对应倍增的商
    }
    quotient *= sign; // 根据符号确定最终的商
    return quotient;
}
int get_size(Type type)
{
    if (type == NULL)
        return 0;
    else if (type->kind == BASIC)
        return 4;
    else if (type->kind == ARRAY)
        return get_size(type->u.array.elem) * (type->u.array.size);
    else if (type->kind == STRUCTURE)
    {
        int size = 0;
        FieldList fd = type->u.struct_pnt->type->u.struct_def;
        while (fd != NULL)
        {
            size += get_size(fd->type);
            fd = fd->tail;
        }
        return size;
    }
    else
        assert(0);
    return -1;
}
void translate_Program(Tnode root)
{
    doublelink = (InterCodes)malloc(sizeof(struct InterCodes_));
    doublelink->code = NULL;
    doublelink->prev = doublelink;
    doublelink->next = doublelink;
    assert(doublelink != NULL);
    if (root == NULL)
        return;
    //  Program -> ExtDefList
    assert(childnum(root) <= 1);
    translate_ExtDefList(root->childs[0]);
}
void translate_ExtDefList(Tnode root)
{
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("ExtDefList,child number:%d", childnum(root));
    Tnode n0 = root->childs[0];
    Tnode n1 = root->childs[1];
    // ExtDefList -> ExtDef ExtDefList
    if (n0 != NULL && n1 != NULL)
    {
        translate_ExtDef(n0);
        translate_ExtDefList(n1);
    }
    else if (n0 != NULL && n1 == NULL)
        translate_ExtDef(n0);
}
void translate_ExtDef(Tnode root)
{
    /*
    ExtDef -> Specifier ExtDecList SEMI
    | Specifier SEMI
    | Specifier FunDec CompSt
    | Specifier FunDec SEMI
    */
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("ExtDef,child number:%d", childnum(root));
    Tnode n0 = root->childs[0];
    Tnode n1 = root->childs[1];
    Tnode n2 = root->childs[2];
    if (childnum(root) == 3)
    {
        if (strcmp(n1->node_name, "ExtDecList") == 0)
        { // ExtDef -> Specifier ExtDecList SEMI
            translate_ExtDecList(n1);
        }
        else if (strcmp(n2->node_name, "CompSt") == 0)
        { // ExtDef -> Specifier FunDec CompSt
            translate_FunDec(n1);
            translate_CompSt(n2);
        }
    }
    return;
    // ExtDef -> Specifier SEMI
}
void translate_ExtDecList(Tnode root)
{
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("ExtDecList,child number:%d", childnum(root));
    Tnode n0 = root->childs[0];
    Tnode n1 = root->childs[1];
    Tnode n2 = root->childs[2];
    if (n0 != NULL)
    {
        translate_VarDec(n0);
        if (n2 != NULL)
            translate_ExtDecList(n2);
    }
}
Operand translate_VarDec(Tnode root)
{
    if (root == NULL)
        return NULL;
    if (irdebug)
        printf("VarDec,child number:%d", childnum(root));

    assert(childnum(root) == 1 || childnum(root) == 4);

    if (childnum(root) == 4) // VarDec -> VarDec LB INT RB
        return translate_VarDec(root->childs[0]);

    Tnode id_node = root->childs[0];
    assert(strcmp(id_node->node_name, "ID") == 0);

    FieldList field = search_node(id_node->node_val);
    if (field == NULL)
    {
        printf("no such field\n");
        assert(0);
    }

    Operand op = make_operand(OP_VARIABLE, -1, -1, id_node->node_val);
    op->type = field->type;

    switch (field->type->kind)
    {
    case BASIC:
        // do nothing
        break;
    case ARRAY:
        op->kind = OP_ARRAY;
        op->size = field->type->u.array.size;
        op->type = field->type->u.array.elem;
        if (op->type == NULL || op->type->kind == ARRAY)
        {
            printf("high dimension array\n");
            assert(0);
        }
        make_ir(doublelink, IR_DEC, op, get_size(field->type));
        break;
    case STRUCTURE:
        op->kind = OP_STRUCTURE;
        op->is_structure = true;
        op->type = field->type;
        make_ir(doublelink, IR_DEC, op, get_size(field->type));
        break;
    default:
        assert(0);
    }
    return op;
}
void translate_FunDec(Tnode root)
{
    if (root == NULL)
        return;

    if (irdebug == 1)
        printf("FunDec,child number:%d", childnum(root));

    assert(childnum(root) == 3 || childnum(root) == 4);

    Tnode n0 = root->childs[0];
    FieldList func_field = search_node(n0->node_val);

    // FUNCTION func.name
    Operand func_op = make_operand(OP_FUNCTION, -1, -1, n0->node_val);
    make_ir(doublelink, IR_FUNCTION, func_op);

    // FunDec -> ID LP RP
    if (childnum(root) == 3)
        return;

    // FunDec -> ID LP VarList RP
    Tnode n2 = root->childs[2];

    FieldList cur_fd = func_field->type->u.function.params;
    while (cur_fd)
    {
        Operand cur_op;
        if (cur_fd->type->kind == BASIC)
            cur_op = make_operand(OP_VARIABLE, -1, -1, cur_fd->name);
        else if (cur_fd->type->kind == ARRAY)
            cur_op = make_operand(OP_ARRAY, -1, -1, cur_fd->name);
        else if (cur_fd->type->kind == STRUCTURE)
            cur_op = make_operand(OP_STRUCTURE, -1, -1, cur_fd->name);
        else
            assert(0);

        // PARAM arg.name
        make_ir(doublelink, IR_PARAM, cur_op);

        cur_fd = cur_fd->tail;
    }
}
void translate_VarList(Tnode root)
{
    /*
   VarList -> ParamDec COMMA VarList
   | ParamDec
   */
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("VarList,child number:%d", childnum(root));
    Tnode n0 = root->childs[0];
    Tnode n2 = root->childs[2];
    translate_ParamDec(n0);
    if (n2 != NULL)
        translate_VarList(n2);
}
void translate_ParamDec(Tnode root)
{
    // ParamDec → Specifier VarDec
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("ParamDec,child number:%d", childnum(root));
    Tnode n0 = root->childs[0];
    Tnode n1 = root->childs[1];
    if (n1 != NULL)
        translate_VarDec(n1);
}
void translate_CompSt(Tnode root)
{
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("CompSt,child number:%d", childnum(root));
    Tnode n0 = root->childs[0];
    Tnode n1 = root->childs[1];
    Tnode n2 = root->childs[2];
    // CompSt -> LC DefList StmtList RC
    assert(childnum(root) == 4);
    if (n1 != NULL)
        translate_DefList(n1);
    if (n2 != NULL)
        translate_StmtList(n2);
}

void translate_StmtList(Tnode root)
{
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("StmtList,child number:%d", childnum(root));
    Tnode n0 = root->childs[0];
    Tnode n1 = root->childs[1];
    Tnode n2 = root->childs[2];
    // Stmtlist -> Stmt Stmtlist
    assert(childnum(root) == 2);
    if (n0 != NULL)
        translate_Stmt(n0);
    if (n1 != NULL)
        translate_StmtList(n1);
}
void translate_Stmt(Tnode root)
{
    if (root == NULL)
    {
        return;
    }
    if (irdebug == 1)
    {
        printf("Stmt, child number:%d", childnum(root));
    }
    int num_child = childnum(root);
    assert(num_child <= 3 || num_child == 5 || num_child == 7);

    Tnode n0 = root->childs[0];
    Tnode n1 = root->childs[1];
    Tnode n2 = root->childs[2];
    Tnode n4 = root->childs[4];
    Tnode n6 = root->childs[6];

    switch (num_child)
    {
    case 1: // Stmt -> CompSt
        translate_CompSt(n0);
        break;

    case 2: // Stmt -> Exp SEMI
        translate_Exp(n0, new_temp(), false);
        break;

    case 3:
    { // Stmt -> RETURN Exp SEMI
        Operand t1 = translate_Exp(n1, new_temp(), true);
        make_ir(doublelink, IR_RETURN, t1);
        break;
    }

    case 5:
    case 7:
    {
        if (strcmp(n0->node_name, "IF") == 0)
        { // Stmt -> IF LP Exp RP Stmt
            Operand label1 = new_label();
            Operand label2 = new_label();
            Operand label3 = new_label();

            translate_Cond(n2, label1, label2);
            make_ir(doublelink, IR_LABEL, label1);
            translate_Stmt(n4);
            if (root->childs[5] != NULL)
            { // Stmt -> IF LP Exp RP Stmt ELSE Stmt
                make_ir(doublelink, IR_GOTO, label3);
                make_ir(doublelink, IR_LABEL, label2);
                translate_Stmt(n6);
                make_ir(doublelink, IR_LABEL, label3);
            }
            else
                make_ir(doublelink, IR_LABEL, label2);
        }
        else if (strcmp(n0->node_name, "WHILE") == 0)
        { // Stmt -> WHILE LP Exp RP Stmt
            Operand label1 = new_label();
            Operand label2 = new_label();
            Operand label3 = new_label();
            make_ir(doublelink, IR_LABEL, label1);
            translate_Cond(n2, label2, label3);
            make_ir(doublelink, IR_LABEL, label2);
            translate_Stmt(n4);
            make_ir(doublelink, IR_GOTO, label1);
            make_ir(doublelink, IR_LABEL, label3);
        }
        break;
    }
    }
}
void translate_DefList(Tnode root)
{
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("DefList,child number:%d", childnum(root));
    Tnode n0 = root->childs[0];
    Tnode n1 = root->childs[1];
    Tnode n2 = root->childs[2];
    // DefList -> Def DefList
    assert(root->child_num == 2);
    if (n0 != NULL)
        translate_Def(n0);
    if (n1 != NULL)
        translate_DefList(n1);
}

void translate_Def(Tnode root)
{
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("Def,child number:%d", childnum(root));
    // Def -> Specifier DecList SEMI
    assert(childnum(root) == 3);
    translate_DecList(root->childs[1]);
}

void translate_DecList(Tnode root)
{
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("DecList,child number:%d", childnum(root));
    Tnode n0 = root->childs[0];
    Tnode n1 = root->childs[1];
    Tnode n2 = root->childs[2];
    assert(childnum(root) == 1 || childnum(root) == 3);
    if (childnum(root) == 1) // DecList -> Dec
        translate_Dec(n0);
    else if (n1 != NULL && n2 != NULL)
    { // DecList -> Dec COMMA DecList
        translate_Dec(n0);
        translate_DecList(n2);
    }
}
void translate_Dec(Tnode root)
{
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("Dec,child number:%d", childnum(root));
    Tnode n0 = root->childs[0];
    Tnode n1 = root->childs[1];
    Tnode n2 = root->childs[2];
    assert(childnum(root) == 1 || childnum(root) == 3);
    if (childnum(root) == 1)
    { // Dec -> VarDec
        translate_VarDec(n0);
    }
    else if (childnum(root) == 3)
    { // VarDec ASSIGNOP Exp
        Operand op1 = translate_VarDec(n0);
        Operand t1 = translate_Exp(n2, new_temp(), false);
        // if (op1->kind == OP_ARRAY)
        // {
        // }
        if (op1->kind == OP_VARIABLE)
            translate_Assign(op1, t1);
    }
}

void translate_Assign(Operand op1, Operand t1)
{
    if (t1->kind == OP_ADDRESS)
    {
        Operand tmp = new_temp();
        // place := *addr
        make_ir(doublelink, IR_EQUALSTAR, tmp, t1);
        t1 = tmp;
    }
    make_ir(doublelink, IR_ASSIGN, op1, t1);
}

Operand translate_Exp(Tnode root, Operand place, bool if_load)
{
    /*
    Exp -> Exp ASSIGNOP Exp
    | Exp AND Exp
    | Exp OR Exp
    | Exp RELOP Exp
    | Exp PLUS Exp
    | Exp MINUS Exp
    | Exp STAR Exp
    | Exp DIV Exp
    | LP Exp RP
    | MINUS Exp
    | NOT Exp
    | ID LP Args RP
    | ID LP RP
    | Exp LB Exp RB
    | Exp DOT ID
    | ID
    | INT
    | FLOAT
    */
    if (root == NULL)
        return NULL;
    if (irdebug == 1)
        printf("Exp,child number:%d", childnum(root));
    Tnode n0 = root->childs[0];
    Tnode n1 = root->childs[1];
    Tnode n2 = root->childs[2];
    assert(childnum(root) <= 4);
    if (childnum(root) == 3 && strcmp(n0->node_name, "LP") == 0)
    { // Exp -> LP Exp RP
        translate_Exp(n1, place, false);
    }
    else if (childnum(root) == 3 && strcmp(n0->node_name, "ID") == 0)
    { // Exp -> ID LP RP
        printf("into read call ID LP RP\n");
        FieldList function = search_node(n0->node_val);
        if (strcmp(function->name, "read") == 0)
        {
            // READ place
            make_ir(doublelink, IR_READ, place);
        }
        else
        {
            // place := CALL function.name
            make_ir(doublelink, IR_CALL, place, make_operand(OP_FUNCTION, -1, -1, function->name));
        }
    }
    else if ((n0 != NULL && strcmp(n0->node_name, "Exp") == 0 && (strcmp(n1->node_name, "AND") == 0 || strcmp(n1->node_name, "OR") == 0 || strcmp(n1->node_name, "RELOP") == 0)))
    {
        /*
         * Exp -> Exp RELOP Exp
         * Exp -> Exp AND Exp
         * Exp -> Exp OR Exp
         */
        Operand label1 = new_label();
        Operand label2 = new_label();
        make_ir(doublelink, IR_ASSIGN, place, make_operand(OP_CONSTANT, 0, -1, NULL));
        translate_Cond(root, label1, label2);
        make_ir(doublelink, IR_LABEL, label1);
        make_ir(doublelink, IR_ASSIGN, place, make_operand(OP_CONSTANT, 1, -1, NULL));
        make_ir(doublelink, IR_LABEL, label2);
    }
    else if (childnum(root) == 2 && strcmp(n0->node_name, "NOT") == 0)
    { // Exp -> NOT Exp
        Operand label1 = new_label();
        Operand label2 = new_label();
        make_ir(doublelink, IR_ASSIGN, place, make_operand(OP_CONSTANT, 0, -1, NULL));
        translate_Cond(root, label1, label2);
        make_ir(doublelink, IR_LABEL, label1);
        make_ir(doublelink, IR_ASSIGN, place, make_operand(OP_CONSTANT, 1, -1, NULL));
        make_ir(doublelink, IR_LABEL, label2);
    }
    else if (n0 != NULL && n1 == NULL && strcmp(n0->node_name, "INT") == 0)
    {
        // place := #value
        int get_value = atoi(n0->node_val);
        place->kind = OP_CONSTANT;
        place->u.no_val = get_value;
        // make_ir(doublelink, IR_ASSIGN, place, make_operand(OP_CONSTANT, get_value, -1, NULL));
    }
    else if (n0 != NULL && n1 == NULL && strcmp(n0->node_name, "ID") == 0) // Exp->ID
    {
        FieldList result = search_node(n0->node_val);
        printf("Exp->ID,ID type kind:%d", result->type->kind);
        if (result->type->kind == BASIC)
        {
            // place := variable.name
            place->kind = OP_VARIABLE;
            place->u.no_val = result->index;
            // make_ir(doublelink, IR_ASSIGN, place, make_operand(OP_VARIABLE, -1, -1, result->name));
        }
        else if (result->type->kind == ARRAY && result->is_param == true)
        {
            Operand array = make_operand(OP_ARRAY, -1, -1, result->name);
            place->kind = OP_ADDRESS;
            place->u.no_addr = addrNo++;
            make_ir(doublelink, IR_ASSIGN, place, array);
            place->type = result->type->u.array.elem;
            place->size = result->type->u.array.size;
        }
        else if (result->type->kind == ARRAY && result->is_param == false)
        {
            Operand array = make_operand(OP_ARRAY, -1, -1, result->name);
            place->kind = OP_ARRAY;
            place->u.no_val = result->index;
            place->type = result->type->u.array.elem;
            place->size = result->type->u.array.size;
            // make_ir(doublelink, IR_ASSIGN, place, array);
        }
        else if (result->type->kind == STRUCTURE)
        { // 结构体变量
            printf("Exist struct param\n");
            Operand stru = make_operand(OP_VARIABLE, -1, -1, result->name);
            place->kind = OP_ADDRESS;
            place->u.no_val = result->index;
            place->type = result->type;
            make_ir(doublelink, IR_ADDR, stru, place);
            printf("struct handle done,struct id:%d\n", place->u.no_addr);
            place->kind = OP_STRUCTURE;
            place->is_structure = true;
            // assert(0);
        }
    }
    else if (childnum(root) == 2 && strcmp(n0->node_name, "MINUS") == 0) // Exp->MINUS EXP
    {
        Operand t1 = translate_Exp(n1, new_temp(), true);
        make_ir(doublelink, IR_SUB, place, make_operand(OP_CONSTANT, 0, -1, NULL), t1);
        if (t1->kind == OP_CONSTANT)
        {
            place->kind = OP_CONSTANT;
            place->u.value = -1 * t1->u.value;
        }
    }
    else if (childnum(root) == 3 && strcmp(n1->node_name, "DOT") == 0)
    {
        // Exp -> Exp DOT ID
        printf("into struct visit\n");
        Operand t1 = translate_Exp(root->childs[0], new_temp(), false);
        // assert(t1 != NULL);
        printf("ready offset\n");
        printf("t1 type: %d \n", t1->kind);
        printf("ID value: %s \n", root->childs[2]->node_val);
        Operand offset = new_temp();
        int offset_num = 0;
        Type iterator = t1->type;
        FieldList it_fd = iterator->u.struct_pnt->type->u.struct_def;
        while (it_fd != NULL && strcmp(it_fd->name, root->childs[2]->node_val) != 0)
        {
            printf("element: %s \n", it_fd->name);
            offset_num += get_size(it_fd->type);
            it_fd = it_fd->tail;
        }
        printf("offset num: %d\n", offset_num);
        printf("element over\n");
        make_ir(doublelink, IR_ASSIGN, offset, make_operand(OP_CONSTANT, offset_num, -1, NULL));
        make_ir(doublelink, IR_ADD, place, t1, offset);
        place->kind = OP_ADDRESS;
        // print_irlist(doublelink);
        // assert(0);
    }
    else if (childnum(root) == 4 && strcmp(n0->node_name, "Exp") == 0)
    { // Exp -> Exp LB Exp RB
        Operand t1 = translate_Exp(n0, new_temp(), false);
        assert(t1->kind == OP_ARRAY || t1->kind == OP_ADDRESS);
        Operand t2 = translate_Exp(n2, new_temp(), true);
        Operand offset = new_temp();
        int width = get_size(t1->type);
        if (t1->type->kind == STRUCTURE)
        {
            make_ir(doublelink, IR_MUL, offset, t2, make_operand(OP_CONSTANT, width, -1, NULL));
            place->kind = OP_ADDRESS;
            place->u.no_addr = addrNo++;
            int idx = t2->u.value;
            FieldList tmp_fd = t1->type->u.struct_pnt->type->u.struct_def;
            for (int j = 0; j < t1->u.value; j++)
                tmp_fd = tmp_fd->tail;
            // place->type = tmp_fd->type;
            place->type = t1->type;
            place->base_offset = (idx - 1) * width;
            Operand base = new_addr();
            // base := &addr
            make_ir(doublelink, IR_ADDR, base, t1);
            // place := base + offset
            make_ir(doublelink, IR_ADD, place, base, offset);
        }
        else
        {
            if (t2->kind == OP_CONSTANT)
            {
                offset->kind = OP_CONSTANT;
                offset->u.value = width * t2->u.value;
            }
            else // offset :=  t2 * width
                make_ir(doublelink, IR_MUL, offset, t2, make_operand(OP_CONSTANT, width, -1, NULL));
            printf("middle Exp LB Exp RB, operand kind:%d\n", place->kind);
            place->kind = OP_ADDRESS;
            place->u.no_addr = addrNo++;
            if (t1->kind == OP_ARRAY)
            { // Exp1-> ID
                if (offset->kind == OP_CONSTANT && offset->u.value == 0)
                {
                    make_ir(doublelink, IR_ADDR, place, t1);
                }
                else
                {
                    Operand base = new_addr();
                    // base := &addr
                    make_ir(doublelink, IR_ADDR, base, t1);
                    // place := base + offset
                    make_ir(doublelink, IR_ADD, place, base, offset);
                }
            }
            else if (t1->kind == OP_ADDRESS) // Exp1 -> Exp LB Exp RB
                make_ir(doublelink, IR_ADD, place, t1, offset);
            else
            {
                printf("hign dimension array or illegal\n");
                exit(-1);
            }
            place->type = NULL;
            place->size = 0;
            if (t1->type->kind == ARRAY)
            {
                place->type = t1->type->u.array.elem;
                place->size = t1->type->u.array.size;
            }
        }
    }
    else if (childnum(root) == 3 && strcmp(n1->node_name, "ASSIGNOP") == 0)
    { // Exp ASSIGNOP Exp
        Operand op_left = translate_Exp(n0, new_temp(), false);
        Operand op_right = translate_Exp(n2, new_temp(), false);
        printf("into assign,left kind: %d\n", op_left->kind);
        if (op_left->kind == OP_ADDRESS || op_left->kind == OP_ARRAY || op_left->kind == OP_STRUCTURE)
        {
            if (op_right->kind != OP_ADDRESS && op_right->kind != OP_ARRAY)
                make_ir(doublelink, IR_STAREQUAL, op_left, op_right);
        }
        else
        { // 左值为普通变量
            if (op_right->kind == OP_ADDRESS)
            {
                Operand tmp = new_temp();
                make_ir(doublelink, IR_EQUALSTAR, tmp, op_right);
                op_right = tmp;
            }
            make_ir(doublelink, IR_ASSIGN, op_left, op_right);
        }
        place->kind = op_right->kind;
        place->u = op_right->u;
        // make_ir(doublelink, IR_ASSIGN, place, op_right);
    }
    else if (childnum(root) == 3 && (strcmp(n1->node_name, "PLUS") == 0 || strcmp(n1->node_name, "MINUS") == 0 || strcmp(n1->node_name, "STAR") == 0 || strcmp(n1->node_name, "DIV") == 0))
    { /*
       * Exp -> Exp PLUS Exp
       * Exp -> Exp MINUS Exp
       * Exp -> Exp STAR Exp
       * Exp -> Exp DIV Exp
       */
        Operand t1 = translate_Exp(n0, new_temp(), true);
        Operand t2 = translate_Exp(n2, new_temp(), true);
        int ir_kind = -1;
        int val = 0;
        if (strcmp(n1->node_name, "PLUS") == 0)
        {
            ir_kind = IR_ADD;
            val = t1->u.value + t2->u.value;
        }
        else if (strcmp(n1->node_name, "MINUS") == 0)
        {
            ir_kind = IR_SUB;
            val = t1->u.value - t2->u.value;
        }
        else if (strcmp(n1->node_name, "STAR") == 0)
        {
            ir_kind = IR_MUL;
            val = t1->u.value * t2->u.value;
        }
        else if (strcmp(n1->node_name, "DIV") == 0)
        {
            ir_kind = IR_DIV;
            int val = my_divide(t1->u.value, t2->u.value);
        }
        make_ir(doublelink, ir_kind, place, t1, t2);
    }
    else if (childnum(root) == 4 && strcmp(n0->node_name, "ID") == 0)
    { // Exp -> ID LP Args RP
        printf("into write call ID LP ARGS RP\n");
        FieldList function = search_node(n0->node_val);
        if (strcmp(function->name, "write") == 0)
        {
            translate_Args(n2, true);
            // place := #0
            place->kind = OP_CONSTANT;
            place->u.value = 0;
        }
        else
        {
            translate_Args(n2, false);
            // place := CALL function.name
            Operand func_op = make_operand(OP_FUNCTION, -1, -1, function->name);
            make_ir(doublelink, IR_CALL, place, func_op);
        }
    }
    if (if_load == true)
    {
        if (place->kind != OP_ADDRESS)
            return place;
        Operand re_op = new_temp();
        make_ir(doublelink, IR_EQUALSTAR, re_op, place);
        return re_op;
    }
    else
        return place;
}
void translate_Args(Tnode root, bool write_flag)
{
    if (root == NULL)
        return;
    if (irdebug == 1)
        printf("Args,child number:%d", childnum(root));
    assert(childnum(root) == 1 || childnum(root) == 3);

    if (childnum(root) == 3)
    { // Args -> Exp COMMA Args
        assert(!write_flag);
        translate_Args(root->childs[2], write_flag);
    }
    Operand arg = translate_Exp(root->childs[0], new_temp(), true);
    printf("arg type: %d\n", arg->kind);
    if (arg->is_structure == true)
    {
        printf("structure asparameters\n");
    }
    if (write_flag)
    {
        printf("write arg\n");
        make_ir(doublelink, IR_WRITE, arg);
    }
    else
    {
        if (arg->kind == OP_ARRAY)
        {
            Operand tmp_op = new_addr();
            make_ir(doublelink, IR_ADDR, tmp_op, arg);
            arg = tmp_op;
        }
        else if (arg->kind == OP_ADDRESS)
        {
            if (arg->type->kind != BASIC) // 参数是高维数组
            {
                printf("hign dimension array as parameter\n");
                assert(0);
            }
        }
        else if (arg->kind == OP_STRUCTURE)
        {
        }
        make_ir(doublelink, IR_ARG, arg);
    }
}
void translate_Cond(Tnode root, Operand label_true, Operand label_false)
{
    if (root == NULL)
        return;
    assert(childnum(root) <= 4);
    Tnode first_child = root->childs[0];
    if (childnum(root) == 2 && strcmp(root->childs[0]->node_name, "NOT") == 0) // NOT Exp
        translate_Cond(root->childs[1], label_false, label_true);
    else if (childnum(root) == 3)
    {
        Tnode second_child = root->childs[1];
        Tnode third_child = root->childs[2];

        if (strcmp(second_child->node_name, "AND") == 0)
        {
            Operand label1 = new_label();
            translate_Cond(first_child, label1, label_false);
            make_ir(doublelink, IR_LABEL, label1);
            translate_Cond(third_child, label_true, label_false);
        }
        else if (strcmp(second_child->node_name, "OR") == 0)
        {
            Operand label1 = new_label();
            translate_Cond(first_child, label_true, label1);
            make_ir(doublelink, IR_LABEL, label1);
            translate_Cond(third_child, label_true, label_false);
        }
        else if (strcmp(second_child->node_name, "RELOP") == 0)
        {
            Operand t1 = translate_Exp(first_child, new_temp(), true);
            Operand t2 = translate_Exp(third_child, new_temp(), true);
            make_ir(doublelink, IR_IFGOTO, t1, t2, label_true, second_child->node_val);
            make_ir(doublelink, IR_GOTO, label_false);
        }
    }
    else
    {
        Operand t1 = translate_Exp(root, new_temp(), true);
        make_ir(doublelink, IR_IFGOTO, t1, make_operand(OP_CONSTANT, 0, -1, NULL), label_true, "!=");
        make_ir(doublelink, IR_GOTO, label_false);
    }
}
int my_min(int a, int b)
{
    int diff = a - b;
    int sign_a = (a >> 31) & 0x1;
    int sign_b = (b >> 31) & 0x1;
    int sign_diff = (diff >> 31) & 0x1;
    int sign_same = !(sign_a ^ sign_b);
    int sign = sign_same ? sign_diff : sign_a;
    return sign ? a : b;
}
