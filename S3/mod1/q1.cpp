#include<iostream>
#include<cstdlib>
using namespace std;

class dynamic_array
{
	public:
		int *arr;
		int length;
		dynamic_array()
		{
			allocate(0);
		}
		dynamic_array(int cols)
		{
			allocate(cols);
		}
		void allocate(int cols)
		{
			arr = (int*) malloc(cols*sizeof(int));
			length = cols;
		}
		void display()
		{
			for(int i = 0; i < length; i++)
			{
				cout<<*(arr+i)<<"\t";
			}
		}
		
		void push_back(int data)
		{
			int *temp = arr;
			allocate(length+1);
			for(int i = 0; i < (length-1); i++)
			{
				*(arr+i) = *(temp+i);
			}
			*(arr+(length-1)) = data;
			free(temp);
		}
		
		void insert(int data, int index)
		{
			int *temp = arr;
			allocate(length+1);
			for(int i = 0; i < index; i++)
			{
				*(arr+i) = *(temp+i);
			}
			*(arr+index) = data;
			for(int i = (index+1); i < length; i++)
			{
				*(arr+i) = *(temp+(i-1));
			}
			free(temp);
		}
		void remove(int index)
		{
			int *temp = arr;
			allocate(length-1);
			for(int i = 0; i < index; i++)
			{
				*(arr+i) = *(temp+i);
			}
			for(int i = (index+1); i < length; i++)
			{
				*(arr+(i-1)) = *(temp+i);
			}
			free(temp);
		}
};

int main()
{
	dynamic_array arrobj;
	
	bool keeprunning = true;
	while(keeprunning == true)
	{
		//system("cls");
		cout<<"Select option:\n1) Insert\n2) Delete\n3) Display\n";
		int option = 0;
		cin>>option;
		if(option == 1)
		{
			cout<<"Enter element to enter:\n";
			int element, insertindex;
			cin>>element;
			cout<<"Enter index:";
			cin>>insertindex;
			if(insertindex>arrobj.length)
			{
				cout<<"Invalid index, pushing back to end!\n";
				insertindex = arrobj.length;
			}
			arrobj.insert(element, insertindex);	
		}
		else if(option == 2)
		{
			cout<<"Enter index to delete:\n";
			int deleteindex;
			cin>>deleteindex;
			arrobj.remove(deleteindex);
		}			
		else if(option == 3)
		{
			arrobj.display();
		}
		else
		{
			cout<<"Invalid option selected!\n";
		}
		
		cout<<"\nDo you want to keep running?\n";
		char keepconfirmation;
		cin>>keepconfirmation;
		if((keepconfirmation == 'y') || (keepconfirmation == 'Y'))
		{
			keeprunning = true;
		}
		else
		{
			keeprunning = false;
		}
	}
	
	return 0;
}
