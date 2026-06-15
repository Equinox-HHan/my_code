#include<bits/stdc++.h>
using namespace std;

int func1(int n)
{
	if(n==0)
	{
		return n;		
	}
	return n+func1(n-1);			
} 

int func2(int n)
{
	if(n==1)
	{
		return n;
	}
	return n*func2(n-1);
}

typedef int (*funcPointer)(int n);
void Function(int n,funcPointer func)
{
	int result=func(n);
	cout<<"----Answer is:"<<result<<endl;
}

int main()
{
	cout<<"Enter a number"<<endl;
	int n;cin>>n;
	Function(n,func1);
	Function(n,func2);
	return 0;
}
