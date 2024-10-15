#include<iostream>
using namespace std;

void quicksort(int a[],int,int);

int main()
{
    int ar[30],n;
    cout<<"Enter the size of the array:\n";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0; i<n; i++)
        cin>>ar[i];

    quicksort(ar,0,n-1);
    cout<<"The sorted array is:\n";
    for(int i=0; i<n; i++)
        cout<<ar[i]<<"\t";

    cout<<"\n";
    return 0;
}
void quicksort(int x[],int lb,int ub)
{
    int left, right, mid, temp;
    if(ub>lb)
    {
        left=lb;
        right=ub;
        mid=x[lb];
        while(left<right)
        {
            while(x[left]<=mid)
                left++;
            while(x[right]>mid)
                right--;
            if(left>right)
                break;
            temp=x[left];
            x[left]=x[right];
            x[right]=temp;
        }
        x[lb]=x[right];
        x[right]=mid;
        quicksort(x, lb, right);
        quicksort(x, left, ub);
    }
}
