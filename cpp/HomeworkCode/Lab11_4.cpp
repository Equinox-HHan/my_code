#include<bits/stdc++.h>
using namespace std;
template<class T,const int SIZE=50>
class Stack
{
    public:
        Stack();
        T pop();
        void push(const T& item);
        void clear();
        const T& peek() const;
        bool isEmpty() const;
        bool isFull() const;
    private:
        T list[SIZE];
        int top;
};
template<class T,const int SIZE>
Stack<T,SIZE>::Stack()
{
    top=-1;
}
template<class T,const int SIZE>
T Stack<T,SIZE>::pop()
{
    assert(!isEmpty());
    return list[top--];
}
template<class T,const int SIZE>
void Stack<T,SIZE>::push(const T& item)
{
    assert(!isFull());
    list[++top]=item;
}
template<class T,const int SIZE>
const T& Stack<T,SIZE>::peek() const
{
    assert(!isEmpty());
    return list[top];
}
template<class T,const int SIZE>
bool Stack<T,SIZE>::isEmpty() const
{
    return top==-1;
}
template<class T,const int SIZE>
bool Stack<T,SIZE>::isFull() const
{
    return top==SIZE-1;
}
class Calculate
{
    public:
        void run();
    private:
        Stack<double> num;
        Stack<char> sym;
        bool getData(double &number1,double &number2,char &ope);
        void compute();
};
bool Calculate::getData(double &number1,double &number2,char &ope)
{
    if(num.isEmpty())
    {
        cerr<<"Error"<<endl;
        return false;
    }
    number2=num.pop();
    if(sym.isEmpty())
    {
        cerr<<"Error"<<endl;
        return false;
    }
    ope=sym.pop();
    if(num.isEmpty())
    {
        cerr<<"Error"<<endl;
        return false;
    }
    number1=num.pop();
    return true;
}
void Calculate::compute()
{
    double num1,num2;
    char oper;
    bool result=getData(num1,num2,oper);
    if(result)
    {
        switch(oper)
        {
            case '+':
                num.push(num1+num2);
                break;
            case '-':
                num.push(num1-num2);
                break;
            case '*':
                num.push(num1*num2);
                break;
            case '/':
                if(abs(num2)<1e-9)
                {
                    cerr<<"Error"<<endl;
                    break;
                }
                else
                {
                    num.push(num1/num2);
                    break;
                }
            case '^':
                num.push(pow(num1,num2));
                break;
        }
    } 
}
void Calculate::run()
{
    double number1,number2;
    char op,pre,input;
    bool isFirstTime=true;
    while(input!='Q'&&input!='q')
    {
        if(isFirstTime)
        {
            cout<<"Please Enter (Q/q to quit)"<<endl;
        }
        cin>>input;
        if(input=='Q'||input=='q')
        {
            break;
        }
        cout<<"------Enter------"<<endl;
        cin>>number1;
        num.push(number1);
        isFirstTime=false;
    }
    cin>>op;
    if(op=='=')
    {
        while(!sym.isEmpty())
        {
            compute();
        }
        cout<<num.pop()<<endl;
        num.clear();
        sym.clear();
        isFirstTime=true;
    }
    else if(op=='^')
    {
        sym.push(op);
        cin>>number2;
        num.push(number2);
        compute();
    }
    else if(!sym.isEmpty())
    {
        pre=sym.peek();
        if(op=='+'||op=='-'||pre=='*'||pre=='/')
        {
            compute();
        }
        sym.push(op);
        cin>>number2;
        num.push(number2);
    }
    else if(!isFirstTime)
    {
        sym.push(op);
        cin>>number2;
        num.push(number2);
    }
}
int main()
{
    Calculate c;
    c.run();
    return 0;
}