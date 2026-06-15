#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num) 
{
    int i;
    for(i=2;i<=num/2;i++)
    {
        if(num%i==0)
        return false;
    }
    return true;
}
bool verifyGoldbach(int n)
{
    if (n % 2 != 0 || n <= 2) return false;
    for (int a=1; a<=n; a++) 
    {
        int b=n-a;
        if (isPrime(a) && isPrime(b)) 
        {
            cout << n <<" = "<<a<<" + "<< b << endl;
            return true;
        }
    }
}
int main() 
{
    cout << "验证 100 以内的哥德巴赫猜想：" << endl;
    for (int n = 4; n <= 100; n += 2) 
    {
        verifyGoldbach(n);
    }
    return 0;
}
//函数具有一般性，是某一类的抽象
//main中的调用函数，是对类的具象，对对象的执行