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

void list_concatenate(llist *l1, llist *l2)
{
	node *l1end = l1->HEAD;
	while(l1end->next != nullptr)
	{
		l1end = l1end->next;
	}
	l1end->next = l2->HEAD;
}


int main()
{
	llist list1, list2;
	int length = 0;
	cout<<"Enter number of elements of 1st list:\n";
	cin>>length;
	int data;
	cout<<"Enter the elements of first list:\n";
	for(int i = 0; i < length; i++)
	{
		cin>>data;
		list1.insert_toend(data);
	}
	cout<<"Enter number of elements of 2nd list:\n";
	cin>>length;
	cout<<"Enter the elements of second list:\n";
	for(int i = 0; i < length; i++)
	{
		cin>>data;
		list2.insert_toend(data);
	}
	list_concatenate(&list1, &list2);
	cout<<"Concatenated list:\n";
	list1.display_list();
	return 0;
}
