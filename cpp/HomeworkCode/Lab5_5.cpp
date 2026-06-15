#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"please enter some numbers"<<endl;
	int k;
	char number[10000];
	cin>>k;
	int arr[10]={0};
	for(int i=0;i<k;i++)
	{
		cin>>number;
		for(int j=0;j<strlen(number);j++)
		{
			int digit=number[j]-'0';
			arr[digit]++;
		}	
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=arr[i];j++)
		{
			cout<<i;
		}
	}

	cout<<endl;
	return 0;
}
