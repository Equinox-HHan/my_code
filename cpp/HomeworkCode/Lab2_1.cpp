#include<bits/stdc++.h>
using namespace std;
int main()
{
    clock_t begin=clock();
    int a[10]={0};
    int b[5]={0};
    int y,k,n,m=0;
    bool flag=true;
    for(int x=12345;x<=98765;x++)
    {
        m=x;
        n=0;
        flag=true;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        while(m>0)
        {
            k=m%10;
            if(a[k]>0)
            {
                flag=false;
                break;
            }
            else
            {
                a[k]=1;
                b[n++]=k;
                m=m/10;
            }
        }
        if(!flag)
            continue;
        y=0;
        for(int j=0;j<n;j++)
        {
            if(b[j]>0)
            y=y*10+b[j];
        }
        for(int j=1;j<10;j++)
        {
            if (x*j==y)
            cout<<x<<"*"<<j<<"="<<y<<endl;
        }
    }
    clock_t end=clock();
    double duration=static_cast<double>(end-begin)/CLOCKS_PER_SEC;
    cout<<"zhixingshijian(sec)"<<duration<<endl;
    return 0;
}

        