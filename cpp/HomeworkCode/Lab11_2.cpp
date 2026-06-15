#include<bits/stdc++.h>
using namespace std;
template<typename A>
A func(A f1,A f2)
{
    if(f1>f2)
    {
        return f1;
    }
    else
    {
        return f2;
    }
}
int main()
{
    int number1=3,number2=4;
    cout<<func(number1,number2)<<endl;
    double num1=6.66,num2=10.2117;
    cout<<func(num1,num2)<<endl;
    string str1="123456",str2="666666";
    cout<<func(str1,str2)<<endl;
    return 0;
}