#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	struct Node *next;
	int value;
}Node;


typedef struct
{
	Node *front;			//will point to front element of queue
	Node *back;				//will pint to last element of queue
	int  size;				//current size of queue
}Queue;

void initialize(Queue *p);
void push(Queue *p, int x);			//will push to top of queue
int  pop(Queue *p);					//will pop front element of queue
int  currentSize(Queue y);			//returns current size
int  front(Queue y);				//returns font of queue
void freeQueue(Queue *p);
int  isempty(Queue y);



int main(int argc, char **argv)
{
	Queue myQueue;
	int n;
	int x;
	
	printf("Initilaizing Queue...\n");	
	initialize(&myQueue);
	
	do
	{
		printf("Please select one of the following\n");
		printf("1------------------------Push\n");
		printf("2------------------------Pop\n");
		printf("3------------------------front\n");
		printf("4------------------------isempty\n");
		printf("5------------------------current size\n");
		printf("-1-----------------------Exit\n");

		scanf("%i", &n);
		switch(n)
		{
			case 1:
					printf("Please enter integer to push: ");
					scanf("%i",&x);
					push(&myQueue,x);
				
				break;
			case 2:
				pop(&myQueue);
				break;
			case 3:
				if(isempty(myQueue))
					printf("Queue is empty...\n");
				else					
					printf("front element of queue is: %i\n",front(myQueue));
				break;
			case 4:
				if(isempty(myQueue))
				{
					printf("Stack is empty\n");
				}
				else
				{
					printf("Stack is not empty\n");
				}
				break;
			case 5:
				printf("Current size of Queue is: %i\n", currentSize(myQueue));
				break;
			default:
				printf("Exiting......\n");
				n = -1;
				break;
		}
	}while(n != -1);

    freeQueue(&myQueue);
	return 0;
}


void initialize(Queue *p)
{
	p->front	= NULL;
	p->back 	= NULL;
	p->size		= 0;
}

void push(Queue *p, int x)
{
	Node *new 			= (Node*)	malloc(sizeof(Node));
	new->value 			= x;
	new->next			= NULL;	

	if(p->front == NULL) //if Queue is empty
	{	
		p->front = new;
		p->back  = new;
	}
	else
	{
		p->back->next	= new;
		p->back			= new;
	}	
	(p->size)++;
}

int  pop(Queue *p)
{
	if(p->front == NULL)
	{
		printf("Queue is empty. Returning -1\n");
		return -1;
	}
	else
	{
		int x;
		Node *del = p->front;
		p->front  = del->next;
		(p->size)--;
		x 		  = del->value;
		free(del);
		return x;
	}
}

int currentSize(Queue y)
{
	return y.size;
}



int  front(Queue y)
{
	return	y.front->value;
}
void freeQueue(Queue *p)
{

		Node *del; 
		while(p->front !=NULL)
		{
			del 	  = p->front;
			p->front  = del->next;
		}
		p->size = 0;
}
int  isempty(Queue y)
{
	if(y.front == NULL)
		return 1;
	else
		return 0;
}

