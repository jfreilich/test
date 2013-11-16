#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node* left;
	struct node* right;
	int val;
}node_t;

struct node *root1;
struct node *root2;

int check(node_t* a, node_t* b);
int insert(node_t** tree, int val);

int main(){
	//root1=(node_t*)malloc(sizeof(node_t));
//	root2=(node_t*)malloc(sizeof(node_t));
	root1=0;
	root2=0;
	insert(&root1,10);
	insert(&root2,10);
	printf("%d\t%d\n",root1->val,root2->val);
	insert(root2,25);
	int i=0;
	for (i;i<20;i++){
		insert(&root1,i);
		insert(&root2,i);
	}
	int d=check(root1, root2);
	printf("%d\n",d);
	return d;
}

int insert(node_t** tree, int val){
	if (*tree){
		if ((*tree)->val<val){
			if((*tree)->left){
				insert(&((*tree)->left),val);
			}
			else{
				node_t *node=(node_t *)malloc(sizeof(node_t));
				node->val=val;
				node->left=0;
				node->right=0;
				(*tree)->left=node;
			}
		}
		else if((*tree)->val>val){
			if((*tree)->right){
					insert(&((*tree)->right),val);
				}
				else{
					node_t *node=(node_t *)malloc(sizeof(node_t));
					node->val=val;
					node->left=0;
					node->right=0;
					(*tree)->right=node;
				}
		}
		return 0;
	}
	else{
		(*tree)=(node_t*)malloc(sizeof(node_t));
		(*tree)->val=val;
		(*tree)->left=0;
		(*tree)->right=0;
		return -1;
	}
}

int check(node_t* a, node_t* b){
	int n1=!!a;
	int n2=!!b;
	if (n1&n2){
		return check(a->left,b->left)|check(a->right,b->right);
	}
	else if(n1|n2){
		return 1;
	}
	else{
		return 0;
	}
}