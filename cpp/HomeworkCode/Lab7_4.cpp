#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i=100;
	int *p=&i;
	int **pp=&p;
	
	cout<<"i"<<" : "<<i<<endl;
	cout<<"*p"<<" : "<<*p<<endl;
	cout<<endl;
	cout<<"p"<<" : "<<p<<endl;
	cout<<"&i"<<" : "<<&i<<endl;
	cout<<endl;
	cout<<"*pp"<<" : "<<*pp<<endl;//指针pp进行一次解析运算就是p的值 
	cout<<endl; 
	cout<<"pp"<<" : "<<pp<<endl;//pp是一个指向指针p的指针 
	cout<<"&p"<<" : "<<&p<<endl;//对p取地址结果就是指针pp指向的地址 
	
	return 0;
}
