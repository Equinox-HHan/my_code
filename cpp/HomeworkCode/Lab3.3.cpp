#include<bits/stdc++.h>
using namespace std;
int peach=1;
void fun1()
{
    int i=10;int a=1;
    while(i--)
    {
        a=(a+1)*2;
    }
    cout<<a<<endl;
    return;
}
int fun2(int n)
{
   if(n!=0)
   {
        peach=(peach+1)*2;
        n--;
        fun2(n--);
   }
   return peach;
}
int main()
{
    
    cout<<fun2(10)<<endl;
    fun1();
    return 0;
}