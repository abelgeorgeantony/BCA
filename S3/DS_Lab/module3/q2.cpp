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
		int length;
		node *HEAD;
		llist()
		{
			length = 0;
			HEAD = nullptr;
		}
		void insert_at(int index, int data);
		void insert_toend(int data);
		void delete_from(int index);
		void delete_fromend();
		void display_list();
};

void llist::display_list()
{
	if(HEAD == nullptr)
	{
		cout<<"The list is empty!\n";
		return;
	}
	node *displaynode = HEAD;
	while(displaynode->next != nullptr)
	{
		cout<<displaynode->data<<"\t";
		displaynode = displaynode->next;
	}
	cout<<displaynode->data<<"\n";
	//cout<<"Length: "<<length<<"\n";
}

void llist::insert_at(int index, int data)
{
	if((index > (length-1)) || (index < 0))
	{
		cout<<"Invalid index, Inserting to end of list.\n";
		insert_toend(data);
		return;
	}
	if(index == 0)
	{
		node *newnode = new node;
		newnode->data = data;
		newnode->next = HEAD;
		HEAD = newnode;
		length++;
		return;
	}

	node *preceding = HEAD;
	int i = 0;
	while(i < (index-1))
	{
		preceding = preceding->next;
		i++;
	}
	node *trailing = preceding->next;

	node *newnode = new node;
	newnode->data = data;
	newnode->next = trailing;
	preceding->next = newnode;

	length++;
}
void llist::insert_toend(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->next = nullptr;
	
	if(HEAD == nullptr)
	{
		HEAD = newnode;
		length++;
		return;
	}
	node *end = HEAD;
	while(end->next != nullptr)
		end = end->next;
	end->next = newnode;
	length++;
}

void llist::delete_from(int index)
{
	if(HEAD == nullptr)
	{
		cout<<"Nothing to delete, List empty.!\n";
		cin.get();
		cin.get();
		return;
	}
	if(index == 0)
	{
		if(HEAD->next == nullptr)
		{
			delete(HEAD);
			HEAD = nullptr;
		}
		else
		{
			node *temp = HEAD;
			HEAD = HEAD->next;
			delete(temp);
		}
		length--;
		return;
	}
	if((index > (length - 1)) || (index < 0))
	{
		cout<<"Invalid index, deleting element from end of the list.\n";
		delete_fromend();
		return;
	}
	node *target = HEAD;
	node *preceding;
	int i = 0;
	while(i < index)
	{
		preceding = target;
		target = target->next;
		i++;
	}
	preceding->next = target->next;
	delete(target);
	length--;
}
void llist::delete_fromend()
{
	if(HEAD == nullptr)
	{
		cout<<"Nothing to delete, List empty!\n";
		cin.get();
		cin.get();
		return;
	}
	if(HEAD->next == nullptr)
	{
		delete(HEAD);
		HEAD = nullptr;
		length--;
		return;
	}
	node *end = HEAD;
	node *preceding;
	while(end->next != nullptr)
	{
		preceding = end;
		end = end->next;
	}
	preceding->next = nullptr;
	delete(end);
	length--;
}



int main()
{
	int option = 4;
	llist list;
	while(true)
	{
		system("clear");
		cout<<"Pick an operation:\n1) Insert\n2) Delete\n3) Display\n4) Exit\n";
		cin>>option;
		system("clear");
		if(option == 1)
		{
			int insertchoice, data, index;
			cout<<"Select insert mode:\n1) Insert to last.\n2) Insert at an index.\n";
			cin>>insertchoice;
			system("clear");
			if(insertchoice == 2)
			{
				cout<<"Enter index:\n";
				cin>>index;
				cout<<"Enter data:\n";
				cin>>data;
				list.insert_at(index, data);
			}
			else
			{
				cout<<"Enter data:\n";
				cin>>data;
				list.insert_toend(data);
			}
		}
		else if(option == 2)
		{
			int deletechoice, index;
			cout<<"Select delete mode:\n1) Delete from the end of the list.\n2) Delete from an index.\n";
			cin>>deletechoice;
			system("clear");
			if(deletechoice == 2)
			{
				cout<<"Enter index:\n";
				cin>>index;
				list.delete_from(index);
			}
			else
			{
				list.delete_fromend();
			}
		}
		else if(option == 3)
		{
			list.display_list();
			cout<<"Press any key to continue.\n";
			cin.get();
			cin.get();
		}
		else
		{
			break;
		}
	}
	return 0;
}
