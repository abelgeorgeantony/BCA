#include<iostream>
using namespace std;
int main()
{
	int sparseMatrix[5][6] = 
	{
		{0, 0, 0, 0, 9, 0},
		{0, 8, 0, 0, 0, 0},
		{4, 0, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 5},
		{0, 0, 2, 0, 0, 0}
	};
	
	int size = 0;
	for(int row = 0; row < 5; row++)
	{
		for(int col = 0; col < 6; col++)
		{
			if(sparseMatrix[row][col] != 0)
			{
				size++;
			}
		}
	}
	
	int resultMatrix[3][size];
	int k = 0;
	for(int row = 0; row < 5; row++)
	{
		for(int col = 0; col < 6; col++)
		{
			if(sparseMatrix[row][col] != 0)
			{
				resultMatrix[0][k] = row;
				resultMatrix[1][k] = col;
				resultMatrix[2][k] = sparseMatrix[row][col];
				k++;
			}
		}
	}
	
	cout<<"Triplet Representation:\n";
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < size; col++)
		{
			cout<<resultMatrix[row][col]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
