#include <stdio.h>
#include <stdlib.h>


typedef struct
{
	int maxSize;	//max size of queue
	int size;		//current size of queue
	int back;		//will index last element of queue
	int front;		//will index first element of queue
	int *list;		//will implement queue
}Queue;


void initialize(Queue *p, int x);
void push(Queue *p, int x);			//will push to top of queue
int  pop(Queue *p);					//will pop front element of queue
int  currentSize(Queue y);			//returns current size
int  front(Queue y);				//returns font of queue
void freeQueue(Queue *p);
int isempty(Queue y);
int isfull(Queue y);

int main(int argc, char ***argv)
{

	Queue myQueue;
	int n;
	int x;
	
	printf("Please input size of your Queue: ");
	scanf("%i",&n);
	
	initialize(&myQueue, n);
	
	do
	{
		printf("Please select one of the following\n");
		printf("1------------------------Push\n");
		printf("2------------------------Pop\n");
		printf("3------------------------front\n");
		printf("4------------------------isempty\n");
		printf("5------------------------isfull\n");
		printf("6------------------------current size\n");
		printf("-1-----------------------Exit\n");

		scanf("%i", &n);
		switch(n)
		{
			case 1:
				if(isfull(myQueue))
					printf("Cant insert into full queue\n");
				else
				{
					printf("Please enter integer to push: ");
					scanf("%i",&x);
					push(&myQueue,x);
				}
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
				if(isfull(myQueue))
				{
					printf("Stack is full\n");
				}
				else
				{
					printf("Stack is not full\n");
				}
				break;
			case 6:
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

void freeQueue(Queue *p)
{
	free(p->list);
}


void initialize(Queue *p, int x)
{
	p->maxSize = x;
	p->back	   = p->maxSize - 1;	
	p->front   = 0;
	p->size	   = 0;
	
	/*
		reason why back is initialized to maxSize -1
		is because when you insert first item, back will
		index will equal to 0
	*/

	p->list    = (int*) malloc(sizeof(int)*p->maxSize);
}

void push(Queue *p, int x)
{
	if(p->size == p->maxSize)
	{
		printf("Cant insert to a full queue\n");
	}
	else
	{	
		if(p->back == p->maxSize - 1) //considering circular queue special case
		{
			p->back          = 0;
			p->list[p->back] = x;
			(p->size)++;
		}
		else
		{
			p->back			 = p->back + 1;
			p->list[p->back] = x;
			(p->size)++;
		}	
	}
}

int pop(Queue *p)
{
	if(p->size == 0)
	{
		printf("Stack is Empty. Returning -1\n");
		return -1;
	}
	else
	{
		if(p->front == p->maxSize - 1) //considering circular queue special case
		{
			p->front = 0;
			(p->size)--;
			return p->list[p->maxSize - 1];
		}
		else
		{
			p->front = p->front + 1;
			(p->size)--;
			return p->list[p->front - 1];
		}
	}
}

int  currentSize(Queue y)
{
	return y.size;
}
int  front(Queue y)
{
	if(y.size == 0)
	{
		printf("Queue is empty... Returning -1\n");
		return -1;
	}		
	else
		return y.list[y.front];
}

int isempty(Queue y)
{
	if(y.size == 0)
		return 1;
	else
		return 0;
}

int isfull(Queue y)
{
	if(y.size == y.maxSize)
		return 1;
	else
		return 0;
}


