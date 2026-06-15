#include<bits/stdc++.h>
using namespace std;
//29,31都是素数
//最大公约数肯定是小于12
int CommonDivisor(int divisor)
{   
    int d,m,date,month;
    for(int i=1;i<=31;i++)
    {
        d=i*divisor;
        if(1<=d&&31>=d)
        {
            date=d;
        }
    }
    for(int i=1;i<=12;i++)
    {
        m=i*divisor;
        if(1<=m&&31>=m)
        {
            month=m;
        }
    }
return date,month;
}
int CommonMutiple(int mutiple)
{
int d1,m1,date1,month1;
    for(int j=1;j<=31;j++)
    {
        d1=mutiple/j;
        if(1<=d1&&31>=d1)
        {
            date1=d1;
        }
    }
    for(int j=1;j<=12;j++)
    {
        m1=mutiple/j;
        if(1<=m1&&31>=m1)
        {
            month1=m1;
        }
    }
return date1,month1;
}
int mian()
{   int date,month;
    CommonDivisor(3);
    cout<<date<<month<<endl;
    return 0;
}