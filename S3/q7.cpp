#include<iostream>
using namespace std;

int bsearch(int[],int,int);

int main()
{
    int a[50],item,n,i,index;
    cout<<"Enter the desired array size:\n";
    cin>>n;
    cout<<"Enter the array elements:\n";
    for(i=0; i<n; i++)
        cin>>a[i];

    cout<<"Enter the element to be searched:\n";
    cin>>item;

    index=bsearch(a,n,item);
    if(index== -1)
        cout<<"Search is unsuccesful\n";
    else
        cout<<"Item found at the index: "<<index<<", position: "<<index+1<<"\n";
    return 0;
}
int bsearch(int a[],int n, int item)
{
    int beg=0,last=n-1;
    while(beg<=last)
    {
        int mid=int((beg+last)/2);
        if(item==a[mid])
            return mid;

        else if(item < a[mid])
            last=mid-1;

        else
            beg=mid+1;

    }
    return -1;
}
