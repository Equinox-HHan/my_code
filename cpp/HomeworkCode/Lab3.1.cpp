#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=5; int b=3; int c=1;
    for(int i=0;i<=20;i++)
    {
        int sum1=100-a*i;
        int n1=0;int n2=0;
        for(n1;n1<=sum1/b;n1++)
        {
            int sum2;
            sum2=sum1-b*n1;
            for(n2;n2<=sum2/c;n2++)
            {
                if((100-sum1-sum2)%c==0)
                {
                    cout<<i<<" "<<n1<<" "<<n2<<endl;
                }
            }
        }
    }
    return 0;
}