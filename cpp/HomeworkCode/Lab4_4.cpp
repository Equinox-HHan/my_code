#include<bits/stdc++.h>
using namespace std;

class NoDynamicMemeory//创建一个不涉及动态内存分配的类
{
    public:
        NoDynamicMemeory(int x=0,int y=0)//构造函数声明与实现
        {
            a=x;b=y;
            cout<<"NoDynamicMemeory constructor called."<<endl;
        }
        NoDynamicMemeory(const NoDynamicMemeory&parameter1)//不涉及动态内存与指针，使用潜复制构造函数
        {
            a=parameter1.a;
            b=parameter1.b;
            cout<<"NoDynamicMemeory copy constructor called."<<endl;
        }
        ~NoDynamicMemeory()//析构函数声明与实现
        {
            cout<<"NoDynamicMemeory destructor called."<<endl;
        }
        
        int setParameter(int x,int y)
        {
            a=x;b=y;
            cout<<"Parameters are set to "<<a<<" and "<<b<<"."<<endl;
            return a+b;
        }
        void printValue()//打印值的成员函数
        {
            cout<<"Values are "<<a<<" and "<<b<<"."<<endl;
        }
    
    private:
        int a,b;
};

class DynamicMemory//创建一个设计动态内存分配的类
{
    public:
        DynamicMemory(int value=0)//构造函数声明与实现
        {
            m_ptr=new int(value);
            cout<<"DynamicMemory constructor called."<<endl;
        }
        DynamicMemory(const DynamicMemory&argument1)//浅复制构造函数
        {
            m_ptr=argument1.m_ptr;
            m_ptr=nullptr;//将第一个指针设置为空指针避免出现野指针
            cout<<"DynamicMemory copy constructor called."<<endl;
        }
        DynamicMemory(const DynamicMemory&argument2)//深复制构造函数
        {
            m_ptr=new int(*argument2.m_ptr);
            cout<<"DynamicMemory move constructor called."<<endl;
        }
        DynamicMemory(DynamicMemory&&argument3)noexcept//移动构造函数
        {
            m_ptr=new int(*argument3.m_ptr);
            argument3.m_ptr=nullptr;//被移动对象可以被析构
            cout<<"DynamicMemory move constructor called."<<endl;
        }
        ~DynamicMemory()//析构函数声明与实现
        {
            delete m_ptr;
            cout<<"DynamicMemory destructor called."<<endl;
        }
        void setValue(int value)//设置值的成员函数并显示地址
        {
            *m_ptr=value;
            cout<<"Value is set to "<<*m_ptr<<"."<<endl;
            cout<<"Address of m_ptr is "<<m_ptr<<"."<<endl;
        }
        void printValue()//打印值的成员函数
        {
            cout<<"Value is "<<*m_ptr<<"."<<endl;
        }
       
    private:
        int* m_ptr;
};

int main()//主调函数
{
    NoDynamicMemeory number0(10,10),number2(17,21);//创建无动态内存类的对象number1和number2
    NoDynamicMemeory number1=number0;//调用拷贝构造函数
    number1.printValue();number2.printValue();//打印number2和number1,的值
    number0.setParameter(20,30);//设置number0的值为20和30
    cout<<number0.setParameter(20,30)<<endl;

    DynamicMemory number3(100);//创建动态内存类的对象number3
    DynamicMemory number4=number3;//调用copy构造函数
    number3.printValue();number4.printValue();//打印number3和number4的值
    number3.setValue(200);//设置number3的值为200
    DynamicMemory number5=std::move(number3);//调用move构造函数
    number3.setValue(0);
    number3.printValue();number5.printValue();//打印number4和number5的值
    system("pause");
    return 0;
}

