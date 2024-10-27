#include<iostream>
using namespace std;

struct node
{
	node *prev;
	node *next;
	int data;
};
class dllist
{
	public:
		node *HEAD;
		node *TAIL;
		int length;
		dllist()
		{
		    length = 0;
			HEAD = nullptr;
			TAIL = nullptr;
		}

		void display_list_backward();
		void display_list_forward();
		void insert_toend(int data);
		void insert_to(int index, int data);
		void insert_tostart(int data);
		void delete_fromend();
		void delete_from(int index);
		void delete_fromstart();
};

void dllist::display_list_forward()
{
	node *displaynode = HEAD;
	while(displaynode != nullptr)
	{
		cout<<displaynode->data<<"\t";
		displaynode = displaynode->next;
	}
	cout<<"\n";
}
void dllist::display_list_backward()
{
	node *displaynode = TAIL;
	while(displaynode != nullptr)
	{
		cout<<displaynode->data<<"\t";
		displaynode = displaynode->prev;
	}
	cout<<"\n";
}

void dllist::insert_toend(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->prev = nullptr;
	newnode->next = nullptr;

	if(HEAD == nullptr)
	{
		HEAD = newnode;
		TAIL = HEAD;
		HEAD->next = HEAD;
		HEAD->prev = HEAD;
		length++;
		return;
	}
	TAIL->next = newnode;
	newnode->prev = TAIL;
	newnode->next = HEAD;
	TAIL = newnode;
	length++;
}
void dllist::insert_to(int index, int data)
{
    if(HEAD == nullptr)
	{
		cout<<"List empty, Inserting to end!\n";
		insert_toend(data);
		cin.get();
		cin.get();
		return;
	}
	if(index == 0)
	{
		insert_tostart(data);
		return;
	}
	if((index > (length - 1)) || (index < 0))
	{
		cout<<"Invalid index, inserting element to end of the list.\n";
		insert_toend(data);
		return;
	}
	node *newnode = new node;
	newnode->data = data;
	newnode->prev = nullptr;
	newnode->next = nullptr;

	node *target = HEAD;
	int i = 0;
	while(i < index)
	{
	    target = target->next;
	    i++;
	}
	newnode->prev = target->prev;
	newnode->next = target;
	target->prev->next = newnode;
	target->prev = newnode;
	length++;
}
void dllist::insert_tostart(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->prev = nullptr;
	newnode->next = nullptr;

	if(HEAD == nullptr)
	{
	    HEAD = newnode;
		TAIL = HEAD;
		HEAD->next = HEAD;
		HEAD->prev = HEAD;
		length++;
		return;
	}
	newnode->next = HEAD;
	newnode->prev = TAIL;
	HEAD->prev = newnode;
	TAIL->next = newnode;
	HEAD = newnode;
	length++;
}

void dllist::delete_fromend()
{
	if(HEAD == nullptr)
	{
		cout<<"Nothing to delete, List empty!\n";
		cin.get();
		cin.get();
		return;
	}
	if(HEAD->next == HEAD)
	{
		delete(HEAD);
		HEAD = nullptr;
		TAIL = HEAD;
		length--;
		return;
	}
	node *previous = TAIL->prev;
	previous->next = HEAD;
	HEAD->prev = previous;
	delete(TAIL);
	TAIL = previous;
	length--;
}
void dllist::delete_from(int index)
{
    if(HEAD == nullptr)
	{
		cout<<"Nothing to delete, List empty!\n";
		cin.get();
		cin.get();
		return;
	}
	if(index == 0)
	{
		delete_fromstart();
		return;
	}
	if((index > (length - 1)) || (index < 0))
	{
		cout<<"Invalid index, deleting element from end of the list.\n";
		delete_fromend();
		return;
	}
	node *target = HEAD;
	int i = 0;
	while(i < index)
	{
		target = target->next;
		i++;
	}
	node *previous = target->prev;
	node *next = target->next;
	previous->next = next;
	next->prev = previous;
	delete(target);
	length--;
}
void dllist::delete_fromstart()
{
	if(HEAD == nullptr)
	{
		cout<<"Nothing to delete, List empty!\n";
		cin.get();
		cin.get();
		return;
	}
	if(HEAD->next == HEAD)
	{
		delete(HEAD);
		HEAD = nullptr;
		TAIL = HEAD;
		length--;
		return;
	}
	node *next = HEAD->next;
	next->prev = TAIL;
	TAIL->next = next;
	delete(HEAD);
	HEAD = next;
	length--;
}


int main()
{
    dllist list;
    while(true)
    {
        system("clear");
        int operation = 4;
        cout<<"Choose operation:\n1) Insertion\n2) Deletion\n3) Display\n4) Exit\n";
        cin>>operation;
        system("clear");
        if(operation == 1)
        {
            int mode, data;
            cout<<"Enter data:\n";
            cin>>data;
            cout<<"Choose mode:\n1) Insert at front\n2) Insert to back\n3) Insert at an index\n";
            cin>>mode;
            if(mode == 1)
            {
                list.insert_tostart(data);
            }
            else if(mode == 2)
            {
                list.insert_toend(data);
            }
            else
            {
                int index = -1;
                cout<<"Enter index:\n";
                cin>>index;
                list.insert_to(index, data);
            }
        }
        else if(operation == 2)
        {
            int mode = 1;
            cout<<"Choose mode:\n1) Delete from start\n2) Delete from end\n3) Delete from an index\n";
            cin>>mode;
            if(mode == 1)
            {
                list.delete_fromstart();
            }
            else if(mode == 2)
            {
                list.delete_fromend();
            }
            else
            {
                int index = -1;
                cout<<"Enter index:\n";
                cin>>index;
                list.delete_from(index);
            }
        }
        else if(operation == 3)
        {
            int mode = 1;
            cout<<"Choose mode:\n1) Display from start to end\n2) Display from end to start\n";
            cin>>mode;
            if(mode == 1)
            {
                list.display_list_forward();
            }
            else
            {
                list.display_list_backward();
            }
            cin.get();
            cin.get();
        }
        else
        {
            break;
        }
    }
}
