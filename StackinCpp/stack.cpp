#include <iostream>

using namespace std;


class Stack
{
	private:
		int top;		//index tof top of stack
		int maxSize;	//maxSize of your stack
		int *list;		//will be your stack
	
	public:
		void push(int x);
		int pop(void);			//will pop and return top of stack
		int tops(void);			//will return top of stack(not pop)
		bool isempty(void);
		bool isfull(void);

		Stack();			   //default constructor
		Stack(int x);  		   //constructor with int parameter
		~Stack();			   //destructor
		Stack(const Stack& a);  //copy constructor
		Stack& operator =(const Stack& a); //overloading = operator
		
};

void testing(Stack x); //will be used to test copy constructor

int main()
{
	int n;
	int x;
	
	cout<<"Please input size of your stack: ";
	cin>>n;

	Stack myStack(n);
		
	do
	{
		cout<<"Please select one of the following\n";
		cout<<"1------------------------Push\n";
		cout<<"2------------------------Pop\n";
		cout<<"3------------------------Top\n";
		cout<<"4------------------------isempty\n";
		cout<<"5------------------------isfull\n";
		cout<<"-1-----------------------Exit\n";

		cin>>n;
		switch(n)
		{
			case 1:
				cout<<"Please enter integer to push: ";
				cin>>x;
				myStack.push(x);
				break;
			case 2:
				myStack.pop();
				break;
			case 3:
				cout<<"Top element of stack is: "<<myStack.tops()<<endl;
				break;
			case 4:
				if(myStack.isempty())
				{
					cout<<"Stack is empty\n";
				}
				else
				{
					cout<<"Stack is not empty\n";
				}
				break;
			case 5:
				if(myStack.isfull())
				{
					cout<<"Stack is full\n";
				}
				else
				{
					cout<<"Stack is not full\n";
				}
				break;

			default:
				cout<<"Exiting......\n";
				n = -1;
				break;
		}
	}while(n != -1);

	
	return 0;
}


void testing(Stack x)
{
	cout<<"In testing function\n";
}

Stack& Stack::operator=(const Stack& a)
{
	if(this != &a)
	{
		delete []list;
		top      = a.top;
		maxSize  = a.maxSize;
	
		list = new int [maxSize];

		for(int i = 0; i<maxSize; i++)
		{
			list[i] = a.list[i];
		}
	}
	return *this;
}


Stack::Stack(const Stack& a)
{
	top      = a.top;
	maxSize  = a.maxSize;
	
	list = new int [maxSize];

	for(int i = 0; i<maxSize; i++)
	{
		list[i] = a.list[i];
	}
}


void Stack::push(int x)
{
	if((top+1) == maxSize)
	{
		cout<<"Can insert to a full stack\n";
	}
	else
	{
		top = top + 1;
		list[top] = x;
	}
}

Stack::~Stack()
{
	delete []list;
}

int Stack::tops(void)
{
	if(top<0) //if staack is empty return -1, which will be the value of top
	{
		cout<<"Cant top from empty stack\n";
		return top;
	}
	else
	{
		return list[top];
	}
}

int Stack::pop(void)
{
	if(top<0) //if staack is empty return -1, which will be the value of top
	{
		cout<<"Cant pop from empty stack\n";
	}
	else
	{
		top = top - 1;
		return list[top+1];
	}
}

bool Stack::isfull(void)
{

	if((top + 1) == maxSize)
		return true;
	else
		return false;
}

bool Stack::isempty(void)
{
	if(top<0)
		return true;
	else
		return false;
}

Stack::Stack()
{
	top     = -1;
	maxSize = 100;
	list 	= new int[maxSize];
}

Stack::Stack(int x)
{
	top		 = -1;
	maxSize  = x;
	list	 = new int[maxSize];
}






