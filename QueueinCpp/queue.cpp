#include <iostream>

using namespace std;


class Queue
{
	private:
		int maxSize;						//max size of queue
		int size;							//curent size of queue
		int back;							//will index last element of queue
		int front;							//will index first element of queue
		int *list;							//will implement queue;

	public:
		Queue();							//default constructor
		Queue(int x);						//constructor with one parameter
		~Queue();							//destructor
		Queue(const Queue& a);  			//copy constructor
		Queue& operator=(const Queue& a);	//overloading the = operator	

		void push(int x);
		int  pop(void);	
		int  currentSize(void);
		int  fronts(void);
		int  isempty(void);
		int  isfull(void);
};


int main(int argc, char **argv)
{
	int n;
	int x;
	
	cout<<"Please input size of your Queue: ";
	cin>>n;
	
	Queue myQueue(n);
	
	do
	{
		cout<<"Please select one of the following\n";
		cout<<"1------------------------Push\n";
		cout<<"2------------------------Pop\n";
		cout<<"3------------------------fronts\n";
		cout<<"4------------------------isempty\n";
		cout<<"5------------------------isfull\n";
		cout<<"6------------------------current size\n";
		cout<<"-1-----------------------Exit\n";

		cin>>n;
		switch(n)
		{
			case 1:
				if(myQueue.isfull())
					cout<<"Cant insert into full queue\n";
				else
				{
					cout<<"Please enter integer to push: ";
					cin>>x;
					myQueue.push(x);
				}
				break;
			case 2:
				myQueue.pop();
				break;
			case 3:
				if(myQueue.isempty())
					cout<<"Queue is empty...\n";
				else					
					cout<<"front element of queue is: "<<myQueue.fronts()<<endl;
				break;
			case 4:
				if(myQueue.isempty())
				{
					cout<<"Stack is empty\n";
				}
				else
				{
					cout<<"Stack is not empty\n";
				}
				break;
			case 5:
				if(myQueue.isfull())
				{
					cout<<"Stack is full\n";
				}
				else
				{
					cout<<"Stack is not full\n";
				}
				break;
			case 6:
				cout<<"Current size of Queue is: "<<myQueue.currentSize()<<endl;
				break;
			default:
				cout<<"Exiting......\n";
				n = -1;
				break;
		}
	}while(n != -1);

	return 0;
}


Queue& Queue::operator=(const Queue& a)
{
	if(this != &a)
	{
		delete [] list;
		maxSize = a.maxSize;
		back	= a.back;
		front	= a.front;
		size	= a.size;
		list 	= new int [maxSize];

		for(int i = 0; i<maxSize;i++)
			list[i] = a.list[i];
	}
	return *this;
}

Queue::Queue(const Queue& a)
{
	maxSize = a.maxSize;
	back	= a.back;
	front	= a.front;
	size	= a.size;

	list 	=	new int[maxSize];
	//so i am copying every element of queue
	//regardless of valid range in queue
	for(int i = 0; i<maxSize; i++)
		list[i] = a.list[i];
}

Queue::Queue()
{
	maxSize = 50;
	back	= maxSize - 1;
	front	= 0;
	size	= 0;

	list	= new int[maxSize];
}

Queue::Queue(int x)
{
	maxSize = x;
	back	= maxSize - 1;
	front	= 0;
	size	= 0;

	list	= new int[maxSize];
}

Queue::~Queue()
{
	delete [] list;
}


void Queue::push(int x)
{
	if(size == maxSize)
	{
		cout<<"Cant insert to a full queue\n";
	}
	else
	{	
		if(back == (maxSize - 1) ) //considering circular queue special case
		{
			back		= 0;
			list[back]	= x;
			size++;
		}
		else
		{
			back		= back + 1;
			list[back] 	= x;
			size++;
		}	
	}
}

int Queue::pop(void)
{
	if(size == 0)
	{
		cout<<"Stack is Empty. Returning -1\n";
		return -1;
	}
	else
	{
		if(front == maxSize - 1) //considering circular queue special case
		{
			front = 0;
			size--;
			return list[maxSize - 1];
		}
		else
		{
			front = front + 1;
			size--;
			return list[front - 1];
		}
	}	
}

int Queue::currentSize(void)
{
	return size;
}


int  Queue::fronts(void)
{
	if(size == 0)
	{
		cout<<"Queue is empty... Returning -1\n";
		return -1;
	}		
	else
		return list[front];
}

int Queue::isempty(void)
{
	if(size == 0)
		return 1;
	else
		return 0;
}

int Queue::isfull(void)
{
	if(size == maxSize)
		return 1;
	else
		return 0;
}

