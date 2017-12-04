#include <stdio.h>
#include <stdlib.h>

//this program will implement a binary tree data struture with simple functions



//creating node data type that will be represent each node in my binary tree
typedef struct NODE
{
	int value;
	struct NODE *left;
	struct NODE *right;
}NODE;


void postOrderTraversal(NODE *p);


void insert(NODE **root_p, int value_p);

int main (int argc, char**argv)
{
	NODE *root = NULL;
	
	int value;	
	char cont;
	
	//inserting integers into binary tree
	do
	{
		printf("What value do you want to enter in the binary tree\n");
		scanf("%i",&value);	
		printf("Value entered is: %i\n",value);
		insert(&root,value);
		printf("Insert another value? y/n  ");
		scanf(" %c", &cont);

	}while(cont != 'n');
	
	printf("\n\n------Outputting Binary Tree--------\n");
	postOrderTraversal(root);	

	return 0;
}



//below is to insert each integer according to binary search tree condition (Root node>Left node and Root node<=Right node)
void insert(NODE **root_p, int value_p)
{
	//checking possible cases when inserting to binary search tree

	//if binary tree is empty	
	if(*root_p == NULL)
	{
		printf("Entered NULL inserting\n");
		(*root_p) 			= (NODE*)malloc(sizeof(NODE));
		(*root_p)->value 	= value_p;
		(*root_p)->left		= NULL;
		(*root_p)->right	= NULL;
	}
	else //this  means that the binary tree is nto empty
	{
		if((*root_p)->vaulue > value_p) //im checking if value of root is greater then value being inserted
		{
			insert(&((*root_p)->left),value_p);
		}
		else //this else statement means that *root_p->value <= value_p
		{
			insert(&((*root_p)->right),value_p);
		}
	}
}


	/*this will display result in post order traversal
	  post order traversal is:  1. Traverse Left subtree
								2. Traverse Right subtree								
								3. Visit Node(Print node value) 
	*/
void postOrderTraversal(NODE *p)
{
	if(p != NULL)	
	{
		postOrderTraversal(p->left);
		postOrderTraversal(p->right);
		printf("%i\n",p->value);
	}

}



