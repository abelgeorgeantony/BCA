#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
class llist
{
	public:
		node *HEAD;
		llist()
		{
			HEAD = nullptr;
		}
		void insert_toend(int data);
		void swap(int index1, int index2);
		void display_list();
};

void llist::display_list()
{
	node *displaynode = HEAD;
	while(displaynode->next != nullptr)
	{
		cout<<displaynode->data<<"\t";
		displaynode = displaynode->next;
	}
	cout<<displaynode->data<<"\n";
}

void llist::insert_toend(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->next = nullptr;
	
	if(HEAD == nullptr)
	{
		HEAD = newnode;
		return;
	}
	node *end = HEAD;
	while(end->next != nullptr)
		end = end->next;
	end->next = newnode;
}

void llist::swap(int index1, int index2)
{
	node *n1 = nullptr;
	node *n2 = nullptr;
	int i = 0;
	node *current = HEAD;
	while(current->next != nullptr)
	{
		if(i == index1)
			n1 = current;
		if(i == index2)
			n2 = current;
		if((n1 != nullptr)&&(n2 != nullptr))
			break;

		current = current->next;
		i++;
	}
	if((i == index1) && (n1 == nullptr))
		n1 = current;
	else if((i == index2) && (n2 == nullptr))
		n2 = current;

	if((n1 != nullptr) && (n2 != nullptr))
	{
		int temp = n1->data;
		n1->data = n2->data;
		n2->data = temp;
	}
	else
	{
		cout<<"Couldn't swap!\n";
	}
}


int main()
{
	int length = 0;
	cout<<"Enter number of elements:\n";
	cin>>length;

	llist list;
	int data;
	cout<<"Enter the elements:\n";
	for(int i = 0; i < length; i++)
	{
		cin>>data;
		list.insert_toend(data);
	}
	system("clear");
	cout<<"Entered elements:\n";
	list.display_list();

	int index1, index2;
	cout<<"Enter the indices of 2 elements to swap:\n";
	cin>>index1>>index2;
	list.swap(index1, index2);
	cout<<"After swapping:\n";
	list.display_list();
	return 0;
}
