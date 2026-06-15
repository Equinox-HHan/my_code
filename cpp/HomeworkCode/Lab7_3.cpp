#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"enter a number:"<<endl;
	cin>>n;
	int arr[n][n];
	int num=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=0;
		}
	}
	for(int counter=0;counter<ceil(n-1);counter++)
	{
		for(int i=counter;i<n-counter;i++)
		{
			arr[counter][i]=num;
			num+=1;
		}
		for(int j=counter+1;j<n-1-counter;j++)
		{
			arr[j][n-1-counter]=num;
			num+=1;
		}
		for(int p=n-1-counter;p>counter;p--)
		{
			arr[n-1-counter][p]=num;
			num+=1;
		}
		for(int q=n-1-counter;q>counter;q--)
		{
			arr[q][counter]=num;
			num+=1;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]<10)
			{
				cout<<arr[i][j]<<"  ";
			}
			else
			{
				cout<<arr[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}
