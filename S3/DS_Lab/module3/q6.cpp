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
		void find(int data);
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

void llist::find(int data)
{
	node *current = HEAD;
	bool elementfound = false;
	int i = 0;
	while(current->next != nullptr)
	{
		if(current->data == data)
		{
			cout<<"Element "<<data<<" found at index: "<<i<<"\n";
			return;
		}
		current = current->next;
		i++;
	}
	if(current->data == data)
	{
		cout<<"Element "<<data<<" found at index: "<<i<<"\n";
	}
	else
	{
		cout<<"Element doesn't exist in the list!\n";
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
	cout<<"Enter an element to search for:\n";
	cin>>data;
	list.find(data);
	return 0;
}
