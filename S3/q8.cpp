#include<iostream>
using namespace std;

void selection_sort(int [],int);

int main()
{

    int a[50],n;

    cout<<"enter the size of the array"<<endl;
    cin>>n;

    cout<<"enter the elements"<<endl;
    for(int i=0; i<n; i++)
        cin>>a[i];
    selection_sort(a, n);
    cout<<"the sorted array is"<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<"\t";
    cout<<"\n";
    return 0;
}

void selection_sort(int a[],int n)
{
    int min, temp, j;
    for(int i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n; j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;

    }
}