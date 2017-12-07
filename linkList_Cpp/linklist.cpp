#include <iostream>

using namespace std;


struct NODE
{
    int info;
    NODE *next;
};

class LinkList
{
    public:
        LinkList();             //constructor
        ~LinkList();            //destructor
        LinkList(const LinkList& a);    //copy constructor

        LinkList& operator =(const LinkList& right_side); //overloading = operator

        bool isEmpty() const;   //checking if link list is emtpy or not
        void insert(int data);  //inserting into link list
        void display();         //displaying contents of link list
        void delInt(int data);  //deleting an integer from link list
        int list_size();        //return size of link list
    private:
        NODE *first;            //will point to first node of link list
        int size;               //will determine size of link list
};


int main(int argc, char **argv)
{
    LinkList myList;
    int option;

    do
    {
        cout<<"Please enter on of the options below\n";
        cout<<"1   ----------- Insert an Integer\n";
        cout<<"2   ----------- Delete an Integer\n";
        cout<<"3   ----------- Display  Link List\n";
        cout<<"4   ----------- Check if it's Empty\n";
        cout<<"5   ----------- Show Size if Link List\n";
        cin>>option;

        switch(option)
        {
            case 1:
                cout<<"What integer do you want to insert?\n";
                cin>>option;
                myList.insert(option);
                break;

            case 2:
                cout<<"Please Enter integer you want to delete\n";
                cin>>option;                
                myList.delInt(option);
                break;

            case 3:
                myList.display();
                break;

            case 4:
                if(myList.isEmpty())
                    cout<<"Link List is Empty!!!\n";
                else
                    cout<<"Link List is not empty\n";
                break;

            case 5:
                cout<<"The size of the Link List is "<<myList.list_size()<<endl;
                break;
            default:
                break;
        }

        cout<<"Please Enter integer 1 to repeat again Otherwise Enter 0\n";
        cin>>option;
        cout<<"\n\n";
    }
    while(option == 1);
    //testing copy constructor
    LinkList otherList(myList);

    otherList.display();
    cout<<endl;
    otherList.insert(9);
    cout<<endl;
    otherList.display();
    cout<<endl;
    myList.display();
    ////////
    
    //testing overloading = operator
    LinkList x = otherList;

    x.display();
    cout<<endl;
    x.insert(-3);
    x.display();
    otherList.display();
    //
    return 0;
}

LinkList::LinkList()
{
    first   =   NULL;
    size    =   0;
}
LinkList::~LinkList()
{
    NODE *del = first;

    while(first != NULL)
    {
        first = del->next;
        delete del;
        del = first;
    }
    size = 0;
}

LinkList::LinkList(const LinkList& a)
{
    size = a.size;
    
    if(a.isEmpty())
    {
        first = NULL;
    }
    else
    {
        NODE *iterator = a.first;

        NODE *trailer = NULL; //this will be behind the newNode pointer
        NODE *newNode;

        //Below is to copy first node
        newNode         = new NODE;
        newNode->next   = NULL;
        newNode->info   = iterator->info;
        first           = newNode;
        trailer         = newNode;
        iterator        = iterator->next;
        ////

        while(iterator != NULL)
        {
            newNode         = new NODE;
            newNode->next   = NULL;
            newNode->info   = iterator->info;
            trailer->next   = newNode;
            trailer         = newNode;
            iterator        = iterator->next;
        }
        

    }

}

void LinkList::insert(int data)
{
    //Must consider below when inserting new node:
    // if node you inserting is first node
    // if node you inserting is not first node

    NODE *newNode = new NODE;
    newNode->next = NULL;
    newNode->info = data;

    if(first == NULL && size == 0)  // if node you inserting is first node
    {
        first = newNode;
    }
    else    //if node you inserting nis not first node
    {
        NODE *current = first;
        
        while(current->next != NULL)
        {
            current = current->next;
        }
        
        current->next = newNode;
    }
    size++;
}

bool LinkList::isEmpty() const
{
    if(first == NULL)
        return true;
    else
        return false;
}

void LinkList::delInt(int data)
{
    /*when deleting a node, you have to worry about below:
        1.If list is empty
        2.If list is not empty and node to be deleted is first node
            2A. The node is the first and only node
            2B. The node is the first and not the only node
        3.If node to be deleted is not the first node but somewhere in list
            3A. If node being deleted is last node
            3B. If node being deleted is not last node
    */

    if(isEmpty())   //1.
        cout<<"List is empty!!\n";
    else    
    {
        NODE *del     = first;
        NODE *trailer = NULL;
        size--;

        while(del != NULL)
        {
            if(del->info == data)
            {
                size--;
                break;
            }
            trailer = del;
            del = del->next;
        }

        if(first == del) //2
        {
            if(del->next == NULL) //2A
            {
                first = NULL;
                delete del;
            }
            else//2B
            {
                first = del->next;
                delete del;
            }
        }
        else //3
        {
            if(del == NULL) //if data is not in link list
                cout<<"Data Not Found!!!!\n";
            else
            {
                if(del->next == NULL) //3A
                {
                    trailer->next = NULL;
                    delete del;
                }
                else //3B
                {
                    trailer->next = del->next;
                    delete del;
                }
            }
        }
    }
}


void LinkList::display()
{
    if(isEmpty())    
        cout<<"Link List is EMpty\n";
    else
    {
        NODE *traverse = first;
        while(traverse != NULL)
        {
            cout<<traverse->info<<endl;
            traverse = traverse->next;
        }
    }
}

int LinkList::list_size()
{
    return size;
}

LinkList& LinkList::operator =(const LinkList& right_side)
{
    if(this != &right_side)
    {
        size = right_side.size;

        if(right_side.isEmpty())
        {
            first = NULL;
        }
        else
        {
			//dealocating everything from left operand
			NODE *del = first;
			while(first != NULL)
			{
				first = del->next;
				delete del;
				del = first;
			}
			//
			
            NODE *iterator = right_side.first;
    
            NODE *trailer = NULL; //this will be behind the newNode pointer
            NODE *newNode;
    
            //Below is to copy first node
            newNode         = new NODE;
            newNode->next   = NULL;
            newNode->info   = iterator->info;
            first           = newNode;
            trailer         = newNode;
            iterator        = iterator->next;
            ////
    
            while(iterator != NULL)
            {
                newNode         = new NODE;
                newNode->next   = NULL;
                newNode->info   = iterator->info;
                trailer->next   = newNode;
                trailer         = newNode;
                iterator        = iterator->next;
            }
            
        }
    }
}
