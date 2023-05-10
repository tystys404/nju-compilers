#ifndef _NODE_H_
#define _NODE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
typedef int BOOL;
#define true 1
#define false 0

struct TN
{
    int node_line;
    BOOL if_token;
    char* node_name;
    char* node_val;
    struct TN* node_child;
    struct TN* node_next;
};
extern struct TN *tree_root;
extern int yylineno;
struct TN* add_node(char* name, int num,...);
void print_tree(struct TN* root,int depth);
#endif