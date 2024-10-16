#include<iostream>
using namespace std;

int linear (int[],int,int);
int main()
{
    int n,i,data,index;

    cout<<"Enter the number of elements:\n";
    cin>>n;
    int a[n];
    cout<<"Enter elements:\n";
    for(i=0; i<n; i++)
        cin>>a[i];
    //system("clear");
    cout<<"Enter element to be searched:\n";
    cin>>data;
    //system("clear");
    cout<<"Given array is:\n";
    for(i=0; i<n; i++)
        cout<<a[i]<<"\t";
    cout<<"\n";
    cout<<"Element to be searched is: "<<data<<"\n\n";
    index = linear(a,n,data);
    if(index==-1)
    {
        cout<<"Search is unsuccesful\n"<<data<<" is not found\n";
    }
    else
    {
        cout<<"Search is succesful\n"<<data<<" found at index: "<<index<<"\n";
    }
    return 0;
}

int linear (int a[],int n, int data)
{
    int i=0;
    while(i<n)
    {
        if (a[i]==data)
            return i;
        i++;
    }
    return -1;
}
