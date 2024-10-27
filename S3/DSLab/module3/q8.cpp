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
	while(displaynode->next != HEAD)
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
		newnode->next = HEAD;
		return;
	}
	node *end = HEAD;
	while(end->next != HEAD)
		end = end->next;
	end->next = newnode;
	newnode->next = HEAD;
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
	cout<<"Entered elements:\n";
	list.display_list();
	return 0;
}
