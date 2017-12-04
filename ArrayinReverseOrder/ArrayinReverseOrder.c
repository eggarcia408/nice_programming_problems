#include <stdio.h>
#include <stdlib.h>


//// All these functions are for the link list//////
typedef struct NODE
{
    int info;
    struct NODE *next;   
}NODE;



void initializer(NODE **p);             //initializer
int  isEmpty(NODE *p);                  //checking if link list is empy
void insert(int data, NODE **p);      //inserting data from an array in reverse order
void display(NODE *p);                  //Display Data of Link List
void delete(NODE **p, int data);        //delete node
void destructor(NODE **p);				//will delete all the NODES from the link list
/////////////////////////////////////////////////////////////////

void addToArray(int **p, unsigned int size_p);	//add elements to the array
void printArray(int *p, int size_p);

int main(int argc, char **argv)
{
    NODE *root; 			//wil ALWAYS be pointer to first NODE
    initializer(&root);
	unsigned int size;
	int *myArray;
	int i;
	
	printf("Please enter size of your array: ");
	scanf("%u",&size);

	myArray = (unsigned int*) malloc(sizeof(unsigned int) * size);

	addToArray(&myArray, size);
	printArray(myArray, size);

	//adding things to link lis from array in reverse order so that
	//I can print elements in link list in reverse order
	
	for (i = 0; i<size; i++)
	{
		insert(myArray[i], &root);
	}
	printf("Elements in array in reverse order\n");
	display(root);
    return 0;
}


void printArray(int *p, int size_p)
{
	int i;
	
	for(i = 0; i<size_p; i++)
		printf("%i\n",p[i]);
}

void addToArray(int **p, unsigned int size_p)
{

	int i;

	for(i = 0; i< size_p; i++)
	{
		printf("Enter element #%i: ", i+1);
		scanf("%i", &(*p)[i]);
	}
}


/////All the functions below are for the link list/////////////////

void initializer(NODE **p)
{
    *p = NULL;
}

void destructor(NODE **p)
{
	NODE *delNode; //will be used to delete the node	

	while(*p!=NULL)
	{
		delNode	=	*p;
		*p		=	(*p)->next;
		free(delNode);
	}

	//keep in mind that after the above while loop
	//finishes, the root will point to NULL
	//So no need to initialize root no NULL after loop completes
}

int isEmpty(NODE *p)
{
    if(p == NULL)
        return 1;
    else
        return 0;
}

//keep in mind this insert function adds elements in reverse order
void insert(int data, NODE **p)
{
	NODE *node;
	node = (NODE*)malloc(sizeof(NODE));
	node->info = data;

    if(*p==NULL)    //if the link list is empty
	{
		*p=node;
		(*p)->next=NULL;
	}
	else
	{
		node->next = *p;
		*p = node;
	}
}

void display(NODE *p)
{
    int count = 0;
    if(isEmpty(p) != 1) //Link List is not Empty
    {
        while(p != NULL)
        {
            count++;
            printf("Node #%i: %i\n", count, p->info);
            p = p->next;
        }
    }
    else
    {
        printf("List is Empty!!!\n");
    }
}

void delete(NODE **p,int data)
{
    if(isEmpty(*p) == 1)  //if link list is empty
    {
        printf("Link List is Empty\n");
    }
    else
    {
        NODE *del;
        NODE *trailer;    
        
        //del will start pointing to first node
        //trailer will start pointing to NULL
        del     =   *p;
        trailer =    NULL;

        while(del != NULL)
        {
            if(del->info == data)
                break;
            trailer = del;
            del     = del->next;
        }
        if(*p == del) //node to be deleted is first node
        {
            if(del->next == NULL)//if node to be deleted is first node and only node
            {
                *p = NULL; //will make list empty by maiing root equal to NULL
                free(del); 
            }
            else//if node to be deleted is first node and not only node
            {
                *p = del->next;
                free(del);
            }
        }
        else
        {
            if(del == NULL) //data not found
            {
                printf("Data not Found!!!\n");
            }
            else
            {
                if(del->next ==  NULL) //deleting last node
                {
                    trailer->next = NULL;
                    free(del);
                }
                else    //deleting node thats not first or last
                {
                    trailer->next = del->next;
                    free(del);
                }
            }
        }
    }
}
