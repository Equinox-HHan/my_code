#include<bits/stdc++.h>
using namespace std;
//¿­Èö¼ÓÃÜ·¨ 
char func_lock(int number,char c)
{
	c=(c-'a'+number)%26+'a';
	return c;
}
char func_unlock(int number,char c)
{
	c=(c-'a'-number+26)%26+'a';
	return c; 
}

int main()
{
	int N,number;
	cout<<"enter 2 numbers"<<endl;
	cin>>N>>number;
	char arr[N][2];
	cout<<"#---------#"<<endl;
	for(int i=0;i<N;i++)
	{
		cin>>arr[i][0];	
		arr[i][1]=func_lock(number,arr[i][0]);
		cout<<arr[i][1]<<" ";
	}
	cout<<endl;
	cout<<"#---------#"<<endl; 
	cout<<"Go back"<<endl;
	int counter=0;
	for(int i=0;i<N;i++)
	{
		char num=func_unlock(number,arr[i][1]);
		cout<<num<<" "; 
		if(num==arr[i][0])
		{
			counter+=1;
		}
	}
	cout<<endl;
	if(counter==N)
	{
		cout<<"Correct"<<endl;
	}
	else
	{
		cout<<"Wrong"<<endl;
	}
	return 0;
}
