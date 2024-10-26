#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

struct sdata
{
	int rollno;
	int age;
	string name;
	string course;
};
struct snode
{
	sdata data;
	snode *next;
};
class llist
{
	public:
		snode *HEAD;
		int columnwidth;
		llist()
		{
			HEAD = nullptr;
			columnwidth = 0;
		}
		void input_list();
		void insert_toend(sdata data);
		void search(string data);
		void display_list();
		void printNodeAsRecord(snode *node, int columntocolor = -1);
		void findThickestColumn();
		void tableheader();
};

void llist::tableheader()
{
    for(int i = 0; i < ((columnwidth*4)+5); i++)
	{
	    cout<<"-";
	}
	cout<<"\n";
	cout<<"|"
	    <<setw(columnwidth)<<left<<"Name"<<"|"
		<<setw(columnwidth)<<left<<"Age"<<"|"
		<<setw(columnwidth)<<left<<"Course"<<"|"
		<<setw(columnwidth)<<left<<"Rollno"<<"|";
		cout<<"\n";
	for(int i = 0; i < ((columnwidth*4)+5); i++)
	{
	    cout<<"-";
	}
	cout<<"\n";
}
void llist::display_list()
{
	tableheader();
	snode *displaynode = HEAD;
	while(displaynode != nullptr)
	{
		printNodeAsRecord(displaynode);
		displaynode = displaynode->next;
	}
	cout<<"\n";
}
void llist::printNodeAsRecord(snode *node, int columntocolor)
{
    string searchcolor = "";
    cout<<"|";
    searchcolor = ((columntocolor == 0)?"\e[4;31m":"");
    cout<<searchcolor;
    cout<<setw(columnwidth)<<left<<node->data.name<<"\e[0m|";

    searchcolor = ((columntocolor == 1)?"\e[4;31m":"");
    cout<<searchcolor;
	cout<<setw(columnwidth)<<left<<node->data.age<<"\e[0m|";

	searchcolor = ((columntocolor == 2)?"\e[4;31m":"");
	cout<<searchcolor;
	cout<<setw(columnwidth)<<left<<node->data.course<<"\e[0m|";

	searchcolor = ((columntocolor == 3)?"\e[4;31m":"");
	cout<<searchcolor;
	cout<<setw(columnwidth)<<left<<node->data.rollno<<"\e[0m|";
	cout<<"\n";

	/*cout<<"|"
        <<setw(columnwidth)<<left<<node->data.name<<"\e[0m|"
<<setw(columnwidth)<<left<<node->data.age<<"\e[0m|"
<<setw(columnwidth)<<left<<node->data.course<<"\e[0m|"
<<setw(columnwidth)<<left<<node->data.rollno<<"\e[0m|";
cout<<"\n";*/
}
void llist::findThickestColumn()
{
	snode *current = HEAD;
	while(current != nullptr)
	{
		string age = to_string(current->data.age);
		string rollno = to_string(current->data.rollno);
		vector<string> content({current->data.name, current->data.course, age, rollno});

		for(int i = 0; i < content.size(); i++)
		{
			if(content[i].length() > columnwidth)
				columnwidth = content[i].length();
		}
		current = current->next;
	}
	if(columnwidth < 6)
	    columnwidth = 6;
}

void llist::insert_toend(sdata data)
{
	snode *newnode = new snode;
	newnode->data = data;
	newnode->next = nullptr;

	if(HEAD == nullptr)
	{
		HEAD = newnode;
		return;
	}
	snode *end = HEAD;
	while(end->next != nullptr)
		end = end->next;
	end->next = newnode;
}
void llist::input_list()
{
    int length = 0;
	cout<<"Enter number of students:\n";
	cin>>length;
    for(int i = 0; i < length; i++)
	{
		sdata data;
		system("clear");
		cout<<"Enter data of Student "<<i<<":\n";
		cout<<"Name: ";
		cin>>data.name;
		cout<<"Age: ";
		cin>>data.age;
		cout<<"Course: ";
		cin>>data.course;
		cout<<"Roll Number: ";
		cin>>data.rollno;
		insert_toend(data);
	}
	findThickestColumn();
}
void llist::search(string data)
{
    snode *current = HEAD;
	while(current != nullptr)
	{
	    string age = to_string(current->data.age);
		string rollno = to_string(current->data.rollno);
        vector<string> content({current->data.name, age, current->data.course, rollno});
        for(int i = 0; i < content.size(); i++)
		{
			if(content[i] == data)
				printNodeAsRecord(current, i);
		}
		current = current->next;
	}
}


int main()
{
	llist students;
	int option = 4;
	while(true)
	{
		system("clear");
		cout<<"Pick an operation:\n1) Insert\n2) Search\n3) Display\n4) Exit\n";
		cin>>option;
		system("clear");
		if(option == 1)
		{
		    students.input_list();
		}
		else if(option == 2)
		{
		    string data;
		    cout<<"Search: ";
			cin>>data;
			students.tableheader();
			students.search(data);
			cin.get();
			cin.get();
		}
		else if(option == 3)
		{
		    students.display_list();
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
