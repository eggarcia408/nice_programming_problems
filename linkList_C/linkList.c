#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int info;
    struct NODE *next;   
}NODE;



void initializer(NODE **p);             //initializer
int  isEmpty(NODE *p);                  //checking if link list is empy
void insert(int data, NODE **p);        //inserting data
void display(NODE *p);                  //Display Data of Link List
void delete(NODE **p, int data);        //delete node
void displayListInReverse(NODE *p);		//will display linke list in reverse
void destructor(NODE **p);				//will delete all the NODES from the link list

int main(int argc, char **argv)
{
    int option;
    NODE *root; //wil ALWAYS be pointer to first NODE
    

    initializer(&root);

    do
    {
        printf("Please enter on of the options below\n");
        printf("1   ----------- Insert an Integer\n");
        printf("2   ----------- Delete an Integer\n");
        printf("3   ----------- Display  Link List\n");
        printf("4   ----------- Check if it's Empty\n");
		printf("5   ----------- Display Link List in Reverse\n\n");
        scanf("%i",&option);

        switch(option)
        {
            case 1:
                printf("What integer do you wan to insert?\n");
                scanf("%i",&option);
                insert(option, &root);
                break;

            case 2:
                printf("Please Enter integer you want to delete\n");
                scanf("%i",&option);
                delete(&root,option);
                break;

            case 3:
                display(root); //this function checks if its empty
                break;

            case 4:
                if(isEmpty(root)==1)
                    printf("Link List is Empty!\n");
                else
                    printf("Link List is Not Empty!\n");
                break;
			case 5:
				if(isEmpty(root)==1)
					printf("Link List is Empty\n");
				else
					displayListInReverse(root);
				break;

            default:
                printf("Invalid Option\n");                
        }

        printf("Please Enter integer 1 to repeat again Otherwise Enter 0\n");
        scanf("%i",&option);
        printf("\n\n");
    }
    while(option == 1);

	printf("Deleting Entire link list...\n");
	if(root==NULL)
		printf("Link List is Empty!\n");
	else
		destructor(&root);

	//verifying that link list is empty
	if(isEmpty(root) == 1)
		printf("Link List deleted succesfully\n");
	else
		printf("Link List did not delete properly\n");

    return 0;
}

void initializer(NODE **p)
{
    *p = NULL;
}

//for below function, you check if the list is emty in main
void displayListInReverse(NODE *p)
{
	NODE *iter	=	p;	//will be used to iterate through the link list

	if(iter == NULL)  							//Base Case
		return;
	else										//General Case
	{
		displayListInReverse(iter->next);
		printf("%i\n", iter->info);
	}

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

void insert(int data, NODE **p)
{
        NODE *newNode;
        newNode         = (NODE *) malloc(sizeof(NODE));
       
        if(*p == NULL)
        {
            newNode->next   = NULL;
            newNode->info   = data;
            *p              = newNode; 
        }
        else
        {
            NODE *current;
            current = *p;   //make current pointer point to the first node(not
                            //the root node)
            while(current->next != NULL)
            {
                current = current->next;
            }
            newNode->next   = NULL;
            newNode->info   = data;

            current->next   = newNode;
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
