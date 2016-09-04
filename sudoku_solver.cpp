#include<iostream>
using namespace std;
bool blank(int m[9][9],int &row, int &col)
{
	for(row=0;row<9;row++)
		for(col=0;col<9;col++)
			if(m[row][col]==0) return true;
	return false;
}
bool checkrow(int m[9][9], int row, int n)
{
	for(int col=0;col<9;col++)
	{
		if(m[row][col]==n)
			return false;
	}
	return true;
}
bool checkcol(int m[9][9], int col, int n)
{
	for(int row=0;row<9;row++)
		if(m[row][col]==n)
			return false;
	return true;
}
bool checkbox(int m[9][9], int row, int col, int n)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(m[i+row][j+col]==n)
				return false;
		}
	}
	return true;
}
bool safe(int m[9][9], int row, int col, int n)
{
	return ((checkrow(m,row,n)) && (checkcol(m,col,n)) && (checkbox(m,row-row%3,col-col%3,n)));
}
bool solve(int m[9][9])
{
	int row,col;
	if(!blank(m,row,col))
		return true;
	for(int i=1;i<=9;i++)
	{
		if(safe(m,row,col,i))
		{
			m[row][col]=i;
			if(solve(m))
				return true;
			m[row][col]=0;
		}
	}
	return false;
}
int main()
{
	int m[9][9],i,j;
	for( i=0;i<9;i++)
		for( j=0;j<9;j++)
			cin>>m[i][j];
	if(solve(m))
	{
		cout<<"Problem Solved....\n";
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				cout<<m[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else
		cout<<"Sorry, I could not solve the problem.";
	return 0;
}