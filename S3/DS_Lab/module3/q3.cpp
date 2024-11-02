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
		void sort();
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

void llist::sort()
{
	//The naming primary and secondary was chosen, because:
	//In an analogical argument, the entities that are compared
	//are called analogues. The entity that is being compared
	//is called primary analogue and the entity that a primary
	//is compared to is called secondary analogue.
	node *primary = HEAD;
	while(primary->next != nullptr)
	{
		node *secondary = primary->next;
		while(secondary->next != nullptr)
		{
			if(primary->data > secondary->data)
			{
				int tdata = primary->data;
				primary->data = secondary->data;
				secondary->data = tdata;
			}
			secondary = secondary->next;
		}
		if(primary->data > secondary->data)
		{
			int tdata = primary->data;
			primary->data = secondary->data;
			secondary->data = tdata;
		}
		primary = primary->next;
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
	cout<<"Sorted elements:\n";
	list.sort();
	list.display_list();
	return 0;
}
