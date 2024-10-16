#include<iostream>
using namespace std;

void printpoly(int poly[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		cout<<poly[i];
		if(i != 0)
		{
			cout<<"x^"<<i;
		}
		if(i != n-1)
		{
			cout<<" + ";
		}
	}
}

void add(int a[], int b[], int m, int n)
{
	int size, i;
	int sum[10];
	if(m>=n)
	{
		size=m;
	}
	else
	{
		size=n;
	}
	for(i = 0; i < m; i++)
	{
		sum[i] = a[i];
	}
	for(i = 0; i< m; i++)
	{
		sum[i]+=b[i];
	}
	cout<<"Sum of polynomial:\n";
	printpoly(sum, size);
}

int main()
{
	int m, n, i;
	cout<<"Enter the size of the first polynomial:\n";
	cin>>m;
	int a[m];
	cout<<"Enter the first polynomial:\n";
	for(i = 0; i < m; i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the size of the second polynomial:\n";
	cin>>n;
	int b[n];
	cout<<"Enter the second polynomial:\n";
	for(i = 0; i < n; i++)
	{
		cin>>b[i];
	}
	system("cls");
	cout<<"First polynomial:\n";
	printpoly(a, m);
	cout<<"\nSecond polynomial:\n";
	printpoly(b, n);
	cout<<"\n";
	add(a, b, m, n);
	return 0;
}
