#include<bits/stdc++.h>
using namespace std;
const int MAXN=1025;
int arr[MAXN][MAXN];
int number=1;
void func(int dr,int dc,int tr,int tc,int s)
{
    if(s==1)
    {
        return;
    }
    int n=number++;
    s=s/2;
    if(dr<tr+s&&dc<tc+s)
    {
        func(dr,dc,tr,tc,s);
    }
    else
    {
        arr[tr+s-1][tc+s-1]=n;
        func(tr+s-1,tc+s-1,tr,tc,s);
    }
    if(dr<tr+s&&dc>=tc+s)
    {
        func(dr,dc,tr,tc+s,s);
    }
    else
    {
        arr[tr+s-1][tc+s]=n;
        func(tr+s-1,tc+s,tr,tc+s,s);
    }
    if(dr>=tr+s&&dc<tc+s)
    {
        func(dr,dc,tr+s,tc,s);
    }
    else
    {
        arr[tr+s][tc+s-1]=n;
        func(tr+s,tc+s-1,tr+s,tc,s);
    }
    if(dr>=tr+s&&dc>=tc+s)
    {
        func(dr,dc,tr+s,tc+s,s);
    }
    else
    {
        arr[tr+s][tc+s]=n;
        func(tr+s,tc+s,tr+s,tc+s,s);
    }
}
int main()
{
    int k;
    cin>>k;
    int dr,dc;
    cin>>dr>>dc;
    func(dr,dc,0,0,pow(2,k));
    for(int i=0;i<pow(2,k);i++)
    {
        for(int j=0;j<pow(2,k);j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;                             
}


