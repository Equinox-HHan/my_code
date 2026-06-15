#include<bits/stdc++.h>
using namespace std;
void fib2()
{
    int A[20]; A[0]=A[1]=1;
    cout<<"1"<<"1"<<endl;
    for(int i=2;i<20;i++)
    {
        A[i]=A[i-2]+A[i-1];
        cout<<A[i]<<endl;
    }
    return;
}

int fib1(int n)
{
    if (n<=1)
    {
        return n;
    }
    else
    {
        return fib1(n-1)+fib1(n-2);
    }

}
int main()
{
    fib2();
    fib1(21);
    for(int j=0;j<=20;j++)
    {
        cout<<fib1(j)<<endl;
    }   
    
    return 0;
}