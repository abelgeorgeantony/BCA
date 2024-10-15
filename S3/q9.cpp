#include<iostream>
using namespace std;

void insertion_sort(int [],int);

int main()
{
    int a[50],n;
    cout<<"Enter the size of the array:\n";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0; i<n; i++)
        cin>>a[i];

    insertion_sort(a,n);

    cout<<"The sorted array is:\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<"\t";
    cout<<"\n";
    return 0;
}

void insertion_sort(int a[],int n)
{
    int j,key;
    for(int i=1; i<n; i++)
    {
        j=i;
        while(j>0 && a[j-1]>a[j])
        {
            key=a[j];
            a[j]=a[j-1];
            a[j-1]=key;
            j--;
        }
    }
}
