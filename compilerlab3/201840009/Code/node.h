#ifndef _NODE_H_
#define _NODE_H_
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct TN
{
    int node_line;      
    char node_name[20]; 
    char node_val[100]; 
    int tokenFlag;      
    int datatype;
    int child_num;
    union
    { 
        unsigned val_int;
        float val_float;
        char var_ID[50];
    } data;
    struct TN* childs[10];
};
void print_tree(struct TN* mynode, int depth);                          
struct TN* newNode(const char *name, int datatype, const char *val);    
struct TN* add_node(const char *name, int line, int node_num, ...); 
#endif