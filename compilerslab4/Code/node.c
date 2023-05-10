#include "node.h"
void print_tree(struct TN *mynode, int depth)
{
    if (mynode == NULL)
        return;
    for (int i = 0; i < depth; i++)
        printf("  ");
    printf("%s", mynode->node_name);
    if (mynode->tokenFlag)
    {
        int flag = mynode->tokenFlag;
        if (flag == 0)
            printf(": %u", mynode->data.val_int);
        else if (flag == 1)
            printf(": %.6f", mynode->data.val_float);
        else if (flag == 2)
            printf(": %s", mynode->data.var_ID);
        else if (flag == 3)
            printf(": %s", mynode->data.var_ID);
    }
    else
    {
        printf(" (%d)", mynode->node_line);
    }
    printf("\n");
    if (mynode->tokenFlag == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            if (mynode->childs[i] != NULL)
                print_tree(mynode->childs[i], depth + 1);
        }
    }
}
struct TN *newNode(const char *name, int datatype, const char *val)
{
    struct TN *mynode = (struct TN *)malloc(sizeof(struct TN));
    mynode->tokenFlag = 1;
    mynode->datatype = datatype;
    strcpy(mynode->node_name, name);
    if (val)
        strcpy(mynode->node_val, val);
    int tmp = mynode->datatype;
    if (tmp == 0)
    {
        mynode->data.val_int = atoi(mynode->node_val);
    }
    else if (tmp == 1)
    {
        sscanf(val, "%f", &mynode->data.val_float);
    }
    else if (tmp == 2 || tmp == 3)
    {
        strcpy(mynode->data.var_ID, val);
    }
    return mynode;
}
struct TN *add_node(const char *name, int line, int node_num, ...)
{
    struct TN *mynode = (struct TN *)malloc(sizeof(struct TN));
    for (int i = 0; i < 10; i++)
    {
        mynode->childs[i] = NULL;
    }
    mynode->node_line = line;
    mynode->tokenFlag = 0;
    mynode->child_num = node_num;
    strcpy(mynode->node_name, name);
    va_list valist;
    va_start(valist, node_num);
    for (int i = 0; i < node_num; i++)
    {
        mynode->childs[i] = va_arg(valist, struct TN *);
    }
    va_end(valist);
    return mynode;
}
