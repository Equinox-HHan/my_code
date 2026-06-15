#include<bits/stdc++.h>
using namespace std;
int MaxDivisor(int x,int y)
{
    int MinNumber=min(x,y);
    int MaxNumber=max(x,y);
    for(int i=MinNumber;i>=1;i--)
    {
        if(MinNumber%i==0&&MaxNumber%i==0)
        return i;
    }
    return;
}
int MinMutiply(int x,int y)
{
    int MinNumber=min(x,y);
    int MaxNumber=max(x,y);
    for(int j=MaxNumber;j<=MinNumber*MaxNumber;j++)
    {
        if(j%MaxNumber==0&&j%MinNumber==0)
        {
            return j;
        }
    }
    return;
}
#include <iostream>
using namespace std;

// 辗转相除法求最大公约数（递归版本）
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 辗转相除法求最大公约数（迭代版本）
int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 求最小公倍数
int lcm(int a, int b) {
    // 先除后乘防止整数溢出
    return a / gcd(a, b) * b;
}
int main()
{
    //调用以上的函数
    return 0;
}