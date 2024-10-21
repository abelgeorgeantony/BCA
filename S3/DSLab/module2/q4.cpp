#include<iostream>
using namespace std;

class queue
{
	int front;
	int rear;
	int q[10];
	public:
		queue()
		{
			front=-1;
			rear=-1;
		}
		void enqueue(int n)
		{
			int item;
			if(rear==n-1)
			{
				cout<<"Queue Full\n";
			}
			else if(front==-1 && rear==-1)
			{
				cout<<"Enter element: ";
				cin>>item;
				front=0;
				rear=0;
				q[rear]=item;
				display();
			}
			else
			{
				cout<<"Enter element: ";
				cin>>item;
				rear++;
				q[rear]=item;
				display();
			}
		}
		void dequeue()
		{
			if(front==-1 || front>rear)
			{
				cout<<"Queue Empty\n";
			}
			else
			{
				int num=q[front];
				front++;
				cout<<num<<" deleted\n";
				display();
			}
		}
		void display()
		{
			if(front==-1 || front>rear)
			{
				cout<<"Queue Empty\n";
			}
			else
			{
				cout<<"Queue: ";
				for(int i=front;i<=rear;i++)
				{
					cout<<q[i]<<" ";
				}
				cout<<"\n";
			}
		}
};

int main()
{
	int n,c;
	queue que;
	cout<<"Enter queue size: ";
	cin>>n;
	do
	{
		cout<<"MENU\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
		cout<<"Enter your choice: ";
		cin>>c;
		switch(c)
		{
			case 1:
				que.enqueue(n);
				break;
			case 2:
				que.dequeue();
				break;
			case 3:
				que.display();
				break;
			case 4:
				break;
			default:
				cout<<"Invalid choice\n";
		}
	}
	while(c!=4);
	return 0;
}

