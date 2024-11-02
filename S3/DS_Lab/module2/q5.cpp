#include <iostream>
using namespace std;

class queue
{
	int front;
    int rear;
    int q[10];
	public:
    	queue()
		{
        	front = -1;
        	rear = -1;
    	}
    	void enqueue(int n)
		{
        	int item;
        	if ((front == 0 && rear == n - 1) || (front == rear + 1))
			{
            	cout << "Queue Full\n";
        	}
			else if (front == -1 && rear == -1)
			{
            	cout << "Enter element: ";
            	cin >> item;
            	front = 0;
            	rear = 0;
            	q[rear] = item;
            	display(n);
        	}
			else
			{
            	cout << "Enter element: ";
            	cin >> item;
            	rear = (rear + 1) % n;
            	q[rear] = item;
            	display(n);
        	}
    	}
    	void dequeue(int n)
		{
        	if (front == -1 && rear == -1)
			{
            	cout << "Queue Empty\n";
        	}
			else if (front == rear)
			{
            	cout << q[front] << " deleted\n";
            	front = -1;
            	rear = -1;
        	}
			else
			{
            	cout << q[front] << " deleted\n";
            	front = (front + 1) % n;
        	}
        	display(n);
    	}
    	void display(int n)
		{
        	int f = front, r = rear;
        	if (front == -1)
			{
            	cout << "Queue Empty\n";
        	}
			else if (front <= rear)
			{
            	cout << "Queue: ";
            	while (f <= r)
				{
                	cout << q[f] << " ";
                	f++;
            	}
        	}
			else
			{
            	cout << "Queue: ";
            	while (f < n)
				{
                	cout << q[f] << " ";
                	f++;
            	}
            	f = 0;
            	while (f <= r)
				{
                	cout << q[f] << " ";
                	f++;
            	}
        	}
        	cout << "\n";
    	}
};
int main()
{
    int n,c;
    queue que;
    cout << "Enter queue size: ";
    cin >> n;
    do
	{
        cout << "MENU\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> c;
        switch (c)
		{
        case 1:
            que.enqueue(n);
            break;
        case 2:
            que.dequeue(n);
            break;
        case 3:
            que.display(n);
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice\n";
    	}
    } while (c != 4);
    return 0;
}
