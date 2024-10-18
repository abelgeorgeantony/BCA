#include<iostream>
using namespace std;

int main()
{
    int a[5][5],b[5][5],c[5][5],row,col,i,j;
    cout<<"Enter the matrix size(rows then cols):\n";
    cin>>row>>col;

    cout<<"Enter the matrix A:\n";
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Enter the matrix B:\n";
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            cin>>b[i][j];
        }
    }
    cout<<"\n";
    cout<<"Sparse matrix of A:\n";
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(a[i][j]!=0)
            {
                cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
            }
        }
    }
    cout<<"Sparse Matrix of B:\n";
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(b[i][j]!=0)
            {
                cout<<i<<" "<<j<<" "<<b[i][j]<<"\n";
            }
        }
    }
    cout<<"Sum of two sparse matrix:\n";
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(a[i][j]!=0 || b[i][j]!=0)
            {
                c[i][j]=a[i][j]+b[i][j];
                cout<<i<<" "<<j<<" "<<c[i][j]<<"\n";
            }
        }
    }
    return 0;
}
