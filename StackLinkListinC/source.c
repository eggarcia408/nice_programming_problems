#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int value;
	struct Node *next;
}Node;

typedef struct
{
	int size;
	Node *top; //will point to the top of the stack

}Stack;



void initializeStack(Stack *p);
void push(Stack *p, int x);
int  pop(Stack *p);
int  top(Stack x);
int  isempty(Stack x;);
int  size(Stack x);
void freestack(Stack *p);


int main(int argc, char **argv)
{
	Stack myStack;
	int n;
	int x;
	
	printf("Intializinf Stack...\n");
	initializeStack(&myStack);
	
	do
	{
		printf("Please select one of the following\n");
		printf("1------------------------Push\n");
		printf("2------------------------Pop\n");
		printf("3------------------------Top\n");
		printf("4------------------------isempty\n");
		printf("5------------------------size\n");
		printf("-1-----------------------Exit\n");

		scanf("%i", &n);
		switch(n)
		{
			case 1:
				printf("Please enter integer to push: ");
				scanf("%i",&x);
				push(&myStack,x);
				break;
			case 2:
				pop(&myStack);
				break;
			case 3:
				if(isempty(myStack))
					printf("Stack is empty...\n");
				else
					printf("Top element of stack is: %i\n",top(myStack));
				break;
			case 4:
				if(isempty(myStack))
				{
					printf("Stack is empty\n");
				}
				else
				{
					printf("Stack is not empty\n");
				}
				break;
			case 5:
				printf("Size of Stack is %i\n",size(myStack));
				break;
			default:
				printf("Exiting......\n");
				n = -1;
				break;
		}
	}while(n != -1);

    freestack(&myStack);
	return 0;
}

void initializeStack(Stack *p)
{
	p->size 	= 0;
	p->top	 	= NULL;
}

int size(Stack x)
{
	return x.size;
}

void push(Stack *p, int x)
{
	Node *new 	= (Node*)malloc(sizeof(Node));
	new->value	= x;
	new->next	= p->top;
	p->top		= new;
	(p->size)++;
	//so above will work if the stack is empty or not
	/*
		So how this works is you keep shifting elemnts to the "right"
		when you add to your stack
		top will point to top of stack
	*/
}

int  pop(Stack *p)
{
	int val;
	if(p->top == NULL)	
	{
		printf("Stack is empty. Returning -1\n");
		return -1;
	}
	else
	{
		Node *del;
		del			=	p->top;
		p->top   	=	del->next;
		val			=	del->value;
		free(del);
		(p->size)--;
		return val;
	}
}

int isempty(Stack x)
{
	if(x.top == NULL)
		return 1;
	else
		return 0;
}

int top(Stack x)
{
	return x.top->value;
}

void freestack(Stack *p)
{
	Node *del;
	while(p->top != NULL)
	{
		del			=	p->top;
		p->top   	=	del->next;
		free(del);
	}
	p->size = 0;
}





