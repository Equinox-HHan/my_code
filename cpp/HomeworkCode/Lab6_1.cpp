#include<bits/stdc++.h>
using namespace std;

int a=1;//文件作用域-全局变量

class Test
{
	public:
		Test();
		static void showNumber()
		{
			cout<<a<<" : static"<<endl;	//静态局域变量 
			a+=1;
		}
		~Test();
		
	private:
		static int a;	
};
int Test::a=4;//类的静态变量外部初始化 
int fun(int b)//函数内作用域 
{
	int a=0;//局部作用域 
	a=b;
	return a;
}
int main()
{
	cout<<fun(0)<<endl;
	cout<<a<<endl;
	a+=1;//对文件夹作用域操作 
	cout<<a<<endl;
	cout<<fun(3)<<endl;
	Test::showNumber();
	Test::showNumber();
	return 0;	
} 
 
