#include "semant.h"
int debugmode = 0;
int var_index = 0;
int arr_index = 0;
int fun_index = 0;
int struct_index = 0;
int structdef_index = 0;
extern int semant_err;
unsigned int hash_pjw(char *name)
{
    unsigned int val = 0, i;
    for (; *name; name++)
    {
        val = (val << 2) + *name;
        if (i = val & ~TABLESIZE)
            val = (val ^ (i >> 12)) & TABLESIZE;
    }
    return val;
}

void insert_field_node(FieldList field)
{
    unsigned int pos = hash_pjw(field->name);
    HashNode node = (HashNode)malloc(sizeof(struct HashNode_));
    node->data = field;
    node->link = hashtable[pos];
    hashtable[pos] = node;
    switch (field->type->kind)
    {
    case BASIC:
        field->index = var_index++;
        break;
    case ARRAY:
        field->index = arr_index++;
        break;
    case FUNCTION:
        field->index = fun_index++;
        break;
    case STRUCTURE:
        field->index = struct_index++;
        break;
    case STRUCTDEF:
        field->index = struct_index++;
        break;
    default:
        assert(0);
        break;
    }
}

FieldList search_node(char *name)
{
    unsigned int pos = hash_pjw(name);
    HashNode node = hashtable[pos];
    while (node != NULL)
    {
        if (strcmp(node->data->name, name) == 0)
        {
            return node->data;
        }
        node = node->link;
    }
    return NULL;
}
void insert_funcfield(char *func_name)
{
    // 返回值为INT
    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = BASIC;
    type->u.basic = 0;
    FieldList field = (FieldList)malloc(sizeof(struct FieldList_));
    field->tail = NULL;
    field->is_param = false;
    field->type = (Type)malloc(sizeof(struct Type_));
    field->type->kind = FUNCTION;
    field->type->u.function.params_num = 0;
    field->type->u.function.params = NULL;
    field->type->u.function.return_tp = type;
    field->name = (char *)malloc(strlen(func_name) + 10);
    if (strcmp("write", func_name) == 0)
    { // 函数参数为一个INT变量
        FieldList arg = (FieldList)malloc(sizeof(struct FieldList_));
        arg->name = "";
        arg->is_param = false;
        arg->tail = NULL;
        arg->type = type;
        field->type->u.function.params_num++;
        field->type->u.function.params = arg;
    }
    strcpy(field->name, func_name);
    insert_field_node(field);
}
void Program(struct TN *root)
{
    if (debugmode == 1)
        printf("into program\n");
    for (int i = 0; i <= TABLESIZE; i++)
    {
        hashtable[i] = NULL;
    }
    if (root == NULL)
        return;
    insert_funcfield("read");
    insert_funcfield("write");
    ExtDefList(root->childs[0]);
}
void ExtDefList(struct TN *root)
{
    if (debugmode == 1)
        printf("into ExtDefList\n");
    if (root == NULL)
        return;
    if (root->childs[0] != NULL && root->childs[1] != NULL)
    {
        ExtDef(root->childs[0]);
        ExtDefList(root->childs[1]);
    }
    if (root->childs[0] != NULL && root->childs[1] == NULL)
        ExtDef(root->childs[0]);
}
void ExtDef(struct TN *root)
{
    if (debugmode == 1)
        printf("into ExtDef\n");
    if (root == NULL)
        return;
    Type type = Specifier(root->childs[0]);
    if (root->childs[2] != NULL && root->childs[3] == NULL)
    {
        if (strcmp(root->childs[1]->node_name, "ExtDecList") == 0)
        {
            // ExtDef -> Specifier ExtDecList SEMI
            ExtDecList(root->childs[1], type);
        }
        else if (strcmp(root->childs[2]->node_name, "CompSt") == 0)
        {
            // ExtDef -> Specifier FunDec CompSt
            FunDec(root->childs[1], type);
            CompSt(root->childs[2], type);
        }
        else if (strcmp(root->childs[2]->node_name, "SEMI") == 0)
            FunDec(root->childs[1], type);
    }
}
void ExtDecList(struct TN *root, Type type)
{
    if (debugmode == 1)
        printf("into ExtDecList\n");
    if (root == NULL)
        return;
    if (root->childs[0] != NULL && root->childs[1] == NULL)
    {
        // ExtDecList -> VarDec
        VarDec(root->childs[0], type, NULL);
    }
    else if (root->childs[2] != NULL && root->childs[3] == NULL)
    {
        // ExtDecList -> VarDec COMMA ExtDecList
        VarDec(root->childs[0], type, NULL);
        ExtDecList(root->childs[2], type);
    }
}

Type Specifier(struct TN *root)
{
    if (debugmode == 1)
        printf("into Specifier\n");
    if (root == NULL)
        return NULL;
    Type type = NULL;
    if (strcmp(root->childs[0]->node_name, "TYPE") == 0)
    {
        type = make_tp(BASIC, false, 0);
        if (strcmp(root->childs[0]->node_val, "int") == 0)
            type->u.basic = 0;
        else if (strcmp(root->childs[0]->node_val, "float") == 0)
            type->u.basic = 1;
    }
    else if (strcmp(root->childs[0]->node_name, "StructSpecifier") == 0)
    {
        // Specifier -> StructSpecifier
        type = StructSpecifier(root->childs[0]);
    }
    return type;
}
Type StructSpecifier(struct TN *root)
{
    if (debugmode == 1)
        printf("into StructSpecifier\n");
    if (root == NULL)
        return NULL;
    Type type = NULL;
    FieldList field = NULL;
    if (root->childs[4] != NULL && root->childs[5] == NULL)
    {
        // StructSpecifier -> STRUCT OptTag LC DefList RC
        char *child_name = OptTagTag(root->childs[1]);
        if (child_name != NULL)
        {
            if (search_node(child_name) != NULL)
            {
                error_msg(16, root->node_line, "Duplicated name", child_name);
                return NULL;
            }
        }
        Type tmp = make_tp(STRUCTDEF, false, 0);
        tmp->u.struct_def = NULL;
        field = make_fd(child_name, NULL, tmp);
        field->is_param = false;
        if (child_name != NULL)
            insert_field_node(field);
        DefList(root->childs[3], field);
    }
    else if (root->childs[1] != NULL && root->childs[2] == NULL)
    {
        // StructSpecifier -> STRUCT TAG
        char *tag = OptTagTag(root->childs[1]);
        field = search_node(tag);
        if (field == NULL || (field->type->kind != STRUCTURE && field->type->kind != STRUCTDEF))
        {
            error_msg(17, root->node_line, "Undefined structure", tag);
            return NULL;
        }
    }
    type = make_tp(STRUCTURE, false, 0);
    type->u.struct_pnt = field;
    return type;
}
char *OptTagTag(struct TN *root)
{
    if (debugmode == 1)
        printf("into OptTag\n");
    if (root == NULL)
        return NULL;
    // OptTag -> ID
    return root->childs[0]->node_val;
}
char *Tag(struct TN *root)
{
    if (debugmode == 1)
        printf("into Tag\n");
    if (root == NULL)
        return NULL;
    // Tag -> ID
    return root->childs[0]->node_val;
}

FieldList VarDec(struct TN *root, Type type, FieldList field)
{
    if (debugmode == 1)
        printf("into VarDec\n");
    if (root == NULL)
        return NULL;
    FieldList var_field = NULL;
    if (root->childs[0] != NULL && root->childs[1] == NULL)
    { // VarDec -> ID
        char *child_val = root->childs[0]->node_val;
        var_field = make_fd(child_val, NULL, type);
        var_field->is_param = false;
        if (field != NULL && field->type->kind == STRUCTDEF)
        {
            FieldList flag = NULL;
            if (field == NULL || field->type->kind != STRUCTDEF)
                flag = NULL;
            else
            {
                flag = field->type->u.struct_def;
                while (flag != NULL)
                {
                    if (strcmp(flag->name, root->childs[0]->node_val) == 0)
                    {
                        break;
                    }
                    else
                        flag = flag->tail;
                }
            }
            if (flag != NULL)
            {
                error_msg(15, root->node_line, "Redefined field", child_val);
                var_field = NULL;
            }
        }
        else if (search_node(child_val) != NULL)
            error_msg(3, root->node_line, "Redefined variable", child_val);
        else
            insert_field_node(var_field);
    }
    else if (root->childs[3] != NULL && root->childs[4] == NULL)
    {
        // VarDec -> VarDec LB INT RB
        Type array_type = make_tp(ARRAY, false, 0);
        array_type->u.array.size = atoi(root->childs[2]->node_val);
        array_type->u.array.elem = type;
        return VarDec(root->childs[0], array_type, field);
    }
    return var_field;
}
void FunDec(struct TN *root, Type type)
{
    if (debugmode == 1)
        printf("into FunDec\n");
    if (root == NULL)
        return;
    char *child_val = root->childs[0]->node_val;
    FieldList prefield = search_node(child_val);
    FieldList field = NULL;
    if (prefield != NULL && prefield->type->kind == FUNCTION)
    {
        error_msg(4, root->node_line, "Redefined function", child_val);
    }
    else
    {
        Type cur = make_tp(FUNCTION, false, 0);
        cur->u.function.params_num = 0;
        cur->u.function.params = NULL;
        cur->u.function.return_tp = type;
        field = make_fd(child_val, NULL, cur);
        field->is_param = false;
        insert_field_node(field);
    }
    // if (root->childs[2]!=NULL&&root->childs[3]==NULL)
    // { // FunDec -> ID LP RP
    // }
    if (root->childs[3] != NULL && root->childs[4] == NULL)
    { // FunDec -> ID LP VarList RP
        VarList(root->childs[2], field);
    }
}
void VarList(struct TN *root, FieldList field)
{
    if (debugmode == 1)
        printf("into VarList\n");
    if (root == NULL)
        return;
    if (root->childs[0] != NULL && root->childs[1] == NULL)
    {
        // VarList -> ParamDec
        FieldList arg_field = ParamDec(root->childs[0]);
        if (field == NULL || arg_field == NULL)
            return;
        field->type->u.function.params_num++;
        arg_field->is_param = true;
        FieldList temp_field = field->type->u.function.params;
        if (field->type->u.function.params == NULL)
            field->type->u.function.params = arg_field;
        else
        {
            while (temp_field->tail != NULL)
                temp_field = temp_field->tail;
            temp_field->tail = arg_field;
        }
    }
    else if (root->childs[2] != NULL && root->childs[3] == NULL)
    {
        // VarList -> ParamDec COMMA VarList
        FieldList arg_field = ParamDec(root->childs[0]);
        if (field == NULL || arg_field == NULL)
            return;
        field->type->u.function.params_num++;
        arg_field->is_param = true;
        FieldList temp_field = field->type->u.function.params;
        if (field->type->u.function.params == NULL)
            field->type->u.function.params = arg_field;
        else
        {
            while (temp_field->tail != NULL)
                temp_field = temp_field->tail;
            temp_field->tail = arg_field;
        }
        VarList(root->childs[2], field);
    }
}
FieldList ParamDec(struct TN *root)
{
    if (debugmode == 1)
        printf("into ParamDec\n");
    if (root == NULL)
        return NULL;
    // ParamDec -> Specifier VarDec
    Type type = Specifier(root->childs[0]);
    if (type != NULL)
        return VarDec(root->childs[1], type, NULL);
    else
        return NULL;
}

void CompSt(struct TN *root, Type type)
{
    if (debugmode == 1)
        printf("into CompSt\n");
    if (root == NULL)
        return;
    // CompSt -> LC DefList StmtList RC
    if (root->childs[1] != NULL && strcmp(root->childs[1]->node_name, "DefList") == 0)
    {
        DefList(root->childs[1], NULL);
        if (root->childs[2] != NULL && strcmp(root->childs[2]->node_name, "StmtList") == 0)
            StmtList(root->childs[2], type);
    }
    else
    {
        DefList(root->childs[1], NULL);
        StmtList(root->childs[2], type);
    }
}
void StmtList(struct TN *root, Type type)
{
    if (debugmode == 1)
        printf("into StmtList\n");
    if (root == NULL)
        return;
    // StmtList -> Stmt StmtList
    if (root->childs[0] != NULL)
    {
        Stmt(root->childs[0], type);
        if (root->childs[1] != NULL)
            StmtList(root->childs[1], type);
    }
}
void Stmt(struct TN *root, Type type)
{
    if (debugmode == 1)
        printf("into Stmt\n");
    if (root == NULL)
        return;
    if (root->childs[0] != NULL && root->childs[1] == NULL)
    {
        // Stmt -> CompSt
        CompSt(root->childs[0], type);
    }
    else if (root->childs[1] != NULL && root->childs[2] == NULL)
    {
        // Stmt -> Exp SEMI
        Exp(root->childs[0]);
    }
    else if (root->childs[2] != NULL && root->childs[3] == NULL)
    {
        // Stmt -> RETURN Exp SEMI
        Type return_type = Exp(root->childs[1]);
        if (return_type != NULL && type_match(return_type, type) == 0)
            error_msg(8, root->node_line, "Type mismatched for return", NULL);
    }
    else if (root->childs[4] != NULL && root->childs[5] == NULL)
    {
        // Stmt -> IF LP Exp RP Stmt
        // Stmt -> WHILE LP Exp RP Stmt
        Type condition_type = Exp(root->childs[2]);
        if (condition_type != NULL)
        {
            if (condition_type->kind != BASIC)
                error_msg(7, root->node_line, "Non-int type cannot used as a condition", NULL);
            else if (condition_type->u.basic != 0)
                error_msg(7, root->node_line, "Non-int type cannot used as a condition", NULL);
        }
        Stmt(root->childs[4], type);
    }
    else if (root->childs[6] != NULL && root->childs[7] == NULL)
    {
        // Stmt -> IF LP Exp RP Stmt ELSE Stmt
        Type condition_type = Exp(root->childs[2]);
        if (condition_type != NULL)
        {
            if (condition_type->kind != BASIC)
                error_msg(7, root->node_line, "Non-int type cannot used as a condition", NULL);
            else if (condition_type->u.basic != 0)
                error_msg(7, root->node_line, "Non-int type cannot used as a condition", NULL);
        }
        Stmt(root->childs[4], type);
        Stmt(root->childs[6], type);
    }
}

void DefList(struct TN *root, FieldList field)
{
    if (debugmode == 1)
        printf("into DefList\n");
    if (root == NULL)
        return;
    // DefList -> Def DefList
    if (root->childs[0] != NULL)
    {
        Def(root->childs[0], field);
        if (root->childs[1] != NULL)
            DefList(root->childs[1], field);
    }
}
void Def(struct TN *root, FieldList field)
{
    if (debugmode == 1)
        printf("into Def\n");
    if (root == NULL)
        return;
    // Def -> Specifier DecList SEMI
    Type type = Specifier(root->childs[0]);
    if (type != NULL)
        DecList(root->childs[1], type, field);
}
void DecList(struct TN *root, Type type, FieldList field)
{
    if (debugmode == 1)
        printf("into DecList\n");
    if (root == NULL)
        return;
    if (root->childs[0] != NULL && root->childs[1] == NULL)
    {
        // DecList -> Dec
        Dec(root->childs[0], type, field);
    }
    else if (root->childs[2] != NULL && root->childs[3] == NULL)
    {
        // DecList -> Dec COMMA DecList
        Dec(root->childs[0], type, field);
        DecList(root->childs[2], type, field);
    }
}
void Dec(struct TN *root, Type type, FieldList field)
{
    if (root == NULL)
        return;
    if (root->childs[0] != NULL && root->childs[1] == NULL)
    {
        // Dec -> VarDec
        if (field != NULL && field->type->kind == STRUCTDEF)
        {
            // add_struct_member(root->childs[0], type, field);
            FieldList child_fd = VarDec(root->childs[0], type, field);
            child_fd->is_param = false;
            FieldList cur_fd = field->type->u.struct_def;
            if (child_fd != NULL)
            {
                if (field->type->u.struct_def == NULL)
                    field->type->u.struct_def = child_fd;
                else
                {
                    while (cur_fd->tail != NULL)
                        cur_fd = cur_fd->tail;
                    cur_fd->tail = child_fd;
                }
            }
        }
        else
            VarDec(root->childs[0], type, field);
    }
    else if (root->childs[2] != NULL && root->childs[3] == NULL)
    {
        // VarDec ASSIGNOP Exp
        if (field != NULL && field->type->kind == STRUCTDEF)
        {
            FieldList child_fd = VarDec(root->childs[0], type, field);
            child_fd->is_param = false;
            FieldList cur_fd = field->type->u.struct_def;
            if (child_fd != NULL)
            {
                if (field->type->u.struct_def == NULL)
                {
                    field->type->u.struct_def = child_fd;
                }
                else
                {
                    while (cur_fd->tail != NULL)
                        cur_fd = cur_fd->tail;
                    cur_fd->tail = child_fd;
                }
            }
            error_msg(15, root->node_line, "Initialized struct field in definition", NULL);
            return;
        }
        FieldList var_dec = VarDec(root->childs[0], type, field);
        Type assign_type = Exp(root->childs[2]);
        if (var_dec != NULL && type_match(var_dec->type, assign_type) == 0)
            error_msg(5, root->node_line, "Type mismatched for assignment", NULL);
    }
}

Type Exp(struct TN *root)
{
    if (debugmode == 1)
        printf("into Exp\n");
    if (root == NULL)
        return NULL;
    Type type = NULL;
    FieldList result = NULL;
    if (root->childs[0] != NULL && root->childs[1] == NULL)
    {
        if (strcmp(root->childs[0]->node_name, "ID") == 0)
        {
            // Exp -> ID
            result = search_node(root->childs[0]->node_val);
            if (result == NULL || result->type->kind == STRUCTDEF || result->type->kind == FUNCTION)
                error_msg(1, root->node_line, "Undefined variable", root->childs[0]->node_val);
            else
                type = result->type;
        }
        else
        {
            type = make_tp(BASIC, false, 0);
            if (root->childs[0]->datatype == 0) // Exp -> INT
                type->u.basic = 0;
            else if (root->childs[0]->datatype == 1) // Exp -> FLOAT
                type->u.basic = 1;
        }
    }
    else if (root->childs[1] != NULL && root->childs[2] == NULL)
    {
        if (strcmp(root->childs[0]->node_name, "MINUS") == 0) //  Exp -> MINUS Exp
            type = Exp(root->childs[1]);
        else if (strcmp(root->childs[0]->node_name, "NOT") == 0) //  Exp -> NOT Exp
        {
            type = Exp(root->childs[1]);
            if (type != NULL && (type->kind != BASIC || type->u.basic != 0))
                error_msg(7, root->node_line, "Non-int type cannot perform logical operations", NULL);
            type = make_tp(BASIC, false, 0);
        }
    }
    else if (root->childs[2] != NULL && root->childs[3] == NULL)
    {
        if (strcmp(root->childs[0]->node_name, "LP") == 0)
        {
            // Exp -> LP Exp RP
            type = Exp(root->childs[1]);
        }
        else if (strcmp(root->childs[1]->node_name, "DOT") == 0)
        {
            // Exp -> Exp DOT ID
            Type type1 = Exp(root->childs[0]);
            if (type1 != NULL && type1->kind != STRUCTURE)
            {
                error_msg(13, root->node_line, "Illegal use of", ".");
            }
            else if (type1 != NULL && type1->kind == STRUCTURE)
            {
                char *child_name = root->childs[2]->node_val;
                FieldList child_node = NULL;
                if (type1->u.struct_pnt == NULL || type1->u.struct_pnt->type->kind != 3)
                {
                    child_node = NULL;
                }
                else
                {
                    child_node = type1->u.struct_pnt->type->u.struct_def;
                    while (child_node != NULL)
                    {
                        if (strcmp(child_node->name, child_name) == 0)
                            break;
                        else
                            child_node = child_node->tail;
                    }
                }
                if (child_node == NULL)
                {
                    error_msg(14, root->node_line, "Non-existent field", child_name);
                }
                else
                {
                    type = child_node->type;
                }
            }
        }
        else if (strcmp(root->childs[0]->node_name, "ID") == 0)
        {
            // Exp -> ID LP RP
            result = search_node(root->childs[0]->node_val);
            if (result == NULL)
            {
                error_msg(2, root->node_line, "Undefined function", root->childs[0]->node_val);
            }
            else if (result->type->kind != FUNCTION)
            {
                error_msg(11, root->node_line, "Not a function", root->childs[0]->node_val);
            }
            else if (args_match(NULL, result->type->u.function.params) == 0)
            {
                error_msg(9, root->node_line, "Function is not applicable for arguments", root->childs[0]->node_val);
            }
            if (result != NULL && result->type->kind == FUNCTION)
            {
                type = result->type->u.function.return_tp;
            }
        }
        else if (strcmp(root->childs[1]->node_name, "ASSIGNOP") == 0)
        {
            // Exp ASSIGNOP Exp
            struct TN *node_exp = root->childs[0];
            type = Exp(node_exp);
            Type type_right = Exp(root->childs[2]);
            if (type != NULL)
            {
                int flag = 0;
                if (node_exp->childs[0] != NULL && node_exp->childs[1] == NULL && strcmp(node_exp->childs[0]->node_name, "ID") == 0)
                    flag = flag + 1;
                else if (node_exp->childs[2] != NULL && node_exp->childs[3] == NULL && strcmp(node_exp->childs[1]->node_name, "DOT") == 0)
                    flag = flag + 1;
                else if (node_exp->childs[3] != NULL && node_exp->childs[4] == NULL && strcmp(node_exp->childs[0]->node_name, "Exp") == 0)
                    flag = flag + 1;
                if (flag == 0)
                    error_msg(6, root->node_line, "The left-hand side of an assignment must be a variable", NULL);
            }
            if (type_match(type, type_right) == 0)
            {
                error_msg(5, root->node_line, "Type mismatched for assignment", NULL);
            }
        }
        else
        {
            // Exp -> Exp AND Exp
            // Exp -> Exp OR Exp
            // Exp -> Exp RELOP Exp
            // Exp -> Exp PLUS Exp
            // Exp -> Exp MINUS Exp
            // Exp -> Exp STAR Exp
            // Exp -> Exp DIV Exp
            type = Exp(root->childs[0]);
            Type type_right = Exp(root->childs[2]);
            if (type_match(type, type_right) == 0)
            {
                error_msg(7, root->node_line, "Type mismatched", NULL);
            }
            else if (strcmp(root->childs[1]->node_name, "AND") == 0 || strcmp(root->childs[1]->node_name, "OR") == 0)
            {
                if (type != NULL && (type->kind != BASIC || type->u.basic != 0))
                    error_msg(7, root->node_line, "Non-int type doing logical operations", NULL);
                type = make_tp(BASIC, false, 0);
            }
            else if (strcmp(root->childs[1]->node_name, "RELOP") == 0)
                type = make_tp(BASIC, false, 0);
        }
    }
    else if (root->childs[3] != NULL && root->childs[4] == NULL)
    {
        if (strcmp(root->childs[0]->node_name, "Exp") == 0)
        { // Exp -> Exp LB Exp RB
            Type type1 = Exp(root->childs[0]);
            if (type1 != NULL)
            {
                if (type1->kind != ARRAY)
                {
                    error_msg(10, root->node_line, "Not an array", NULL);
                }
                else
                {
                    type = type1->u.array.elem;
                }
            }
            Type type2 = Exp(root->childs[2]);
            if (type2 != NULL)
            {
                if (type2->kind != BASIC)
                    error_msg(12, root->node_line, "Not an integer", NULL);
                else if (type2->u.basic != 0)
                    error_msg(12, root->node_line, "Not an integer", NULL);
            }
        }
        else if (strcmp(root->childs[0]->node_name, "ID") == 0)
        { // Exp -> ID LP Args RP
            result = search_node(root->childs[0]->node_val);
            if (result == NULL)
            {
                error_msg(2, root->node_line, "Undefined function", root->childs[0]->node_val);
            }
            else if (result->type->kind != FUNCTION)
            {
                error_msg(11, root->node_line, "Not a function", root->childs[0]->node_val);
            }
            else
            {
                if (args_match(Args(root->childs[2]), result->type->u.function.params) == 0)
                    error_msg(9, root->node_line, "Function is not applicable for arguments", root->childs[0]->node_val);
            }
            if (result != NULL && result->type->kind == FUNCTION)
                type = result->type->u.function.return_tp;
        }
    }
    return type;
}
FieldList Args(struct TN *root)
{
    if (root == NULL)
        return NULL;
    Type args_type = Exp(root->childs[0]);
    if (args_type == NULL)
        return NULL;
    FieldList args = make_fd("arg", NULL, args_type);
    args->is_param = false;
    // if (root->childs[0]!=NULL&&root->childs[1]==NULL)
    // { // Args -> Exp
    // }
    if (root->childs[2] != NULL && root->childs[3] == NULL)
    {
        // Args -> Exp COMMA Args
        args->tail = Args(root->childs[2]);
    }
    return args;
}
bool type_match(Type tp1, Type tp2)
{
    if (tp1 == NULL || tp2 == NULL)
        return false;
    if (tp1 == tp2)
        return true;
    if (tp1->kind != tp2->kind)
        return false;
    FieldList tp1_def = tp1->u.struct_def;
    FieldList tp2_def = tp2->u.struct_def;
    if (tp1->kind == 0)
        return tp1->u.basic == tp2->u.basic;
    else if (tp1->kind == 1)
        return type_match(tp1->u.array.elem, tp2->u.array.elem);
    else if (tp1->kind == 2)
        return type_match(tp1->u.struct_pnt->type, tp2->u.struct_pnt->type);
    else if (tp1->kind == 3)
    {
        while (tp1_def != NULL || tp2_def != NULL)
        {
            if (tp1_def == NULL || tp2_def == NULL)
                return false;
            if (type_match(tp1_def->type, tp2_def->type) == 0)
                return false;
            tp1_def = tp1_def->tail;
            tp2_def = tp2_def->tail;
        }
    }
    return true;
}
bool args_match(FieldList args1, FieldList args2)
{
    if (args1 == NULL && args2 == NULL)
        return true;
    if (args1 == NULL || args2 == NULL)
        return false;
    while (args1 != NULL || args2 != NULL)
    {
        if (args1 == NULL || args2 == NULL)
            return false;
        if (type_match(args1->type, args2->type) == 0)
            return false;
        args1 = args1->tail;
        args2 = args2->tail;
    }
    return true;
}
FieldList make_fd(char *name, FieldList tail, Type type)
{
    FieldList cur_fd = (FieldList)malloc(sizeof(struct FieldList_));
    cur_fd->name = name;
    cur_fd->tail = tail;
    cur_fd->type = type;
    return cur_fd;
}
Type make_tp(int kind, bool if_defdone, int bas)
{
    Type cur = (Type)malloc(sizeof(struct Type_));
    cur->kind = kind;
    cur->u.basic = bas;
    return cur;
}
void error_msg(int err_type, int err_line, char *err_msg, char *err_elm)
{
    semant_err = semant_err + 1;
    if (err_type != 11 && err_type != 12 && err_type != 10 && err_type != 9)
    {
        printf("Error type %d at Line %d: %s", err_type, err_line, err_msg);
        if (err_elm != NULL)
        {
            printf(" \"%s\"", err_elm);
        }
        printf(".\n");
    }
    else if (err_type == 11)
    {
        printf("Error type %d at Line %d: \"%s\" is not a function", err_type, err_line, err_elm);
        printf(".\n");
    }
    else if (err_type == 12)
    {
        printf("Error type %d at Line %d: \"%s\" is not an integer", err_type, err_line, err_elm);
        printf(".\n");
    }
    else if (err_type == 10)
    {
        printf("Error type %d at Line %d: \"%s\" is not an array", err_type, err_line, err_elm);
        printf(".\n");
    }
    else if (err_type == 9)
    {
        printf("Error type %d at Line %d: Function \"%s\" is not applicable for arguments", err_type, err_line, err_elm);
        printf(".\n");
    }
}