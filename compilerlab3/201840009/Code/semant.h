#ifndef __SEMANT_H__
#define __SEMANT_H__
// #include "hashtab.h"
#include "node.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLESIZE 0x3fff
typedef struct Type_ *Type;
typedef struct FieldList_ *FieldList;
typedef struct HashNode_ *HashNode;
extern HashNode hashtable[TABLESIZE + 10];

struct Type_
{
    enum
    {
        BASIC,
        ARRAY,
        STRUCTURE,
        STRUCTDEF,
        FUNCTION
    } kind;
    union
    {
        int basic;
        struct
        {
            int size;
            Type elem;
        } array;
        struct
        {
            int params_num;
            FieldList params;
            Type return_tp;
        } function;
        FieldList struct_pnt;
        FieldList struct_def;
    } u;
};

struct FieldList_
{
    char *name;     // 域的名字
    Type type;      // 域的类型
    FieldList tail; // 下一个域
    int index;      // 编号
    bool is_param;  // 是不是参数
};

struct HashNode_
{
    FieldList data;
    HashNode link;
};
void Program(struct TN *root);
void ExtDefList(struct TN *root);
void ExtDef(struct TN *root);
void ExtDecList(struct TN *root, Type type);
Type Specifier(struct TN *root);
Type StructSpecifier(struct TN *root);
char *OptTagTag(struct TN *root);
char *Tag(struct TN *root);
FieldList VarDec(struct TN *root, Type type, FieldList field);
void FunDec(struct TN *root, Type type);
void VarList(struct TN *root, FieldList field);
FieldList ParamDec(struct TN *root);
void CompSt(struct TN *root, Type type);
void StmtList(struct TN *root, Type type);
void Stmt(struct TN *root, Type type);
void DefList(struct TN *root, FieldList field);
void Def(struct TN *root, FieldList field);
void DecList(struct TN *root, Type type, FieldList field);
void Dec(struct TN *root, Type type, FieldList field);
Type Exp(struct TN *root);
FieldList Args(struct TN *root);
bool type_match(Type a, Type b);
bool args_match(FieldList act_args, FieldList form_args);
unsigned int hash_pjw(char *name);
void insert_field_node(FieldList field);
FieldList search_node(char *name);
void error_msg(int err_type, int err_line, char *err_msg, char *err_elm);
FieldList make_fd(char *name, FieldList tail, Type type);
Type make_tp(int kind, bool if_defdone, int bas);
#endif