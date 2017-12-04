#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct
{
	int top;        //will be used to indicate size and index of top of stack
	int maxSize;	//maxSize of stack
	int *list;		//this pointer will implement the stack
}Stack;

void initializeStack(Stack *p, int Msize);
void  push(Stack *p, int x);
int  pop(Stack *p);
int  top(Stack x);
void freestack(Stack *p);

int main(int argc, char **argv)
{
	Stack myStack;
	int n;
	int x;
	
	printf("Please input size of your stack: ");
	scanf("%i",&n);
	
	initializeStack(&myStack, n);
	
	do
	{
		printf("Please select one of the following\n");
		printf("1------------------------Push\n");
		printf("2------------------------Pop\n");
		printf("3------------------------Top\n");
		printf("4------------------------isempty\n");
		printf("5------------------------isfull\n");
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
				if(isfull(myStack))
				{
					printf("Stack is full\n");
				}
				else
				{
					printf("Stack is not full\n");
				}
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

void push(Stack *p, int x)
{
	if((p->top + 1) == p->maxSize)
	{
		printf("Cant insert to a full stack\n");
	}
	else
	{
		p->top = p->top + 1;
		p->list[p->top] = x;
	}
}

void freestack(Stack *p)
{
	free(p->list);
}

int top(Stack x)
{
	if(x.top<0)  //if stack is empty, return -1, which will be p->top
	{
		printf("Cant top from empty stack\n");
		return x.top;
	}
	else
	{
		return x.list[x.top];
	}
}

int pop(Stack *p)
{
	if(p->top<0 )   //if stack is empty, return -1, which will be p->top
	{
		printf("Cant pop from empty stack\n");
		return p->top;
	}
	else
	{
		p->top = p->top-1; 			//deleting
		return p->list[p->top+1];
	}	
	
}

int isfull(Stack x)
{
	if(x.top+1 == x.maxSize)
		return 1;
	else
		return 0;
}

int isempty(Stack x)
{
	if(x.top<0)
		return 1;
	else
		return 0;
}

void initializeStack(Stack *p, int Msize)
{
	p->top = -1; //so size + 1 is uses for the 
	p->maxSize = Msize;
	
	p->list = (int*) malloc(sizeof(int)*Msize);
}
