#include<bits/stdc++.h>
using namespace std;

//创建两个相同的类但不同的成员顺序
struct A
{
	int number1=1;
	double number2=0.1;//最大对齐值为结构成员数据中对齐值最大的：8bytes 
	char c='c';	
	short number3=2;
};
//sizeof(A)应该是24： 4+(4)+8+1+2+(5)=24
//其中带括号的表示需要补齐8bytes 

struct B
{
	int number1=1;
	char c='k';
	short number3=3;
	double number2=0.2;	
};
//sizeof（B）应该是16：4+2+1+（1）+8=16 
//显然只需要补齐1bytes，优化内存达到了33.3% 

struct C
{
	struct A;
	//内嵌的结构：结构体sizeof（C）应该为结构A的最大对齐值 
	short num1=0.05;
	int num2=20; 	
};

#pragma pack(1)
//以1为单位强行改变结构体的内存对齐
struct AA
{
	int number1=1;
	double number2=0.1;
	char c='c';	
	short number3=2;
};
//最终结果就是各自的对齐值总和：4+8+1+2=15 
#pragma pack()
//恢复原有的自动对齐
 
struct alignas(16) BB//整个结构体强制改变对齐 
{
	int number1=1;
	char c='k';
	short number3=3;
};
//结果应该为强制要求的16而不是自动填充的8 

int main()
{
	//显示两个不同排版顺序的类的sizeof 
	cout<<sizeof(A)<<" "<<sizeof(B)<<endl;
	
	A a;//创建一个A类的对象a和两个指针 
	int *pr1=&a.number1;
	double *pr2=&a.number2;
	//根据内存对齐原理，两个指针之间应该相差8而不是4 
	cout<<pr1<<" "<<pr2<<endl;
	 
	cout<<sizeof(C)<<endl;
	
	AA aa; cout<<sizeof(aa)<<endl;
	BB bb;cout<<sizeof(bb)<<endl;
	
	return 0;
}
