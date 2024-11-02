#include<iostream>
using namespace std;

int main()
{
	int rows = 0, cols = 0;
	cout<<"Enter number of rows:\n";
	cin>>rows;
	cout<<"Enter number of cols:\n";
	cin>>cols;
	int matrix[rows][cols];
	cout<<"Enter elements:\n";
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cin>>matrix[i][j];
		}
		cout<<"\n";
	}
	cout<<"Transpose of matrix:\n";
	for(int i = 0; i < cols; i++)
	{
		for(int j = 0; j < rows; j++)
		{
			cout<<matrix[j][i];
		}
		cout<<"\n";
	}
}
