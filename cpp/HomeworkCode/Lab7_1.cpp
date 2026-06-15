#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr1[12];
	int arr2[3][4];
	int num=1;
	
	for(int i=0;i<12;i++)
	{
		arr1[i]=i+1;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			arr2[i][j]=num;
			num+=1;
		}
	}
	
	for(const int &element:arr1)
	{
		cout<<&element<<" : "<<element<<endl; 
	}
	cout<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<&arr2[i][j]<<" : "<<arr2[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
