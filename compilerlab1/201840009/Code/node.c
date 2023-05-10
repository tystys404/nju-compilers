#include"node.h"
struct TN* add_node(char* name, int num,...)
{
    // printf("into add node\n");
    struct TN* cur=(struct TN*)malloc(sizeof(struct TN));
    struct TN* tmp=(struct TN*)malloc(sizeof(struct TN));
    va_list list;
    va_start(list,num);
    tmp=va_arg(list,struct TN*);
    cur->node_line=tmp->node_line;
    cur->if_token=false;
	cur->node_name=malloc((strlen(name) + 1) * sizeof(char));
	cur->node_val=malloc(10 * sizeof(char));
    strcpy(cur->node_name,name);
    strcpy(cur->node_val,"");
    cur->node_child=tmp;
	int cnt=num-1;
    while(cnt--)
    {
		tmp->node_next=va_arg(list,struct TN*);
        if(tmp->node_next!=NULL)
        {
            tmp=tmp->node_next;
        }
    }
    return cur;
}
void print_tree(struct TN* root,int depth)
{
    if(root==NULL) return;
    for(int i=0;i<depth;i++) printf("  ");
    printf("%s",root->node_name);
    if(root->if_token==false) printf(" (%d)",root->node_line);
    else if(strcmp(root->node_name,"ID")==0||strcmp(root->node_name,"TYPE")==0||strcmp(root->node_name,"INT")==0) printf(": %s",root->node_val);
    else if(strcmp(root->node_name,"FLOAT")==0)  printf(": %lf",atof(root->node_val));
    printf("\n");
	print_tree(root->node_child,depth+1);
	print_tree(root->node_next,depth);
}