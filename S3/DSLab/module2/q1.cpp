#include<iostream>
using namespace std;

int stack[10], n, top=-1;
void display()
{
    if(top>=0)
    {
        cout<<"Stack: \n";
        for(int i=top; i>=0; i--)
        {
            cout<<stack[i]<<" ";
        }
        cout<<"\n";
    }
    else
    {
        cout<<"Stack is empty";
    }
}
void push()
{
    int val;
    if(top>=n-1)
    {
        cout<<"Stack Overflow\n";
    }
    else
    {
        cout<<"Enter value to be pushed: ";
        cin>>val;
        top++;
        stack[top]=val;
        display();
    }
}
void pop()
{
    if(top<=-1)
    {
        cout<<"Stack Underflow\n";
    }
    else
    {
        cout<<"The popped element is "<< stack[top] <<"\n";
        top--;
        display();
    }
}
int main()
{
    int ch, val;
    cout<<"Enter stack size: ";
    cin>>n;
    do
    {
        cout<<"\nMENU\n----\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            cout<<"Invalid Choice\n";
        }
    } while(ch!=4);
    return 0;
}

