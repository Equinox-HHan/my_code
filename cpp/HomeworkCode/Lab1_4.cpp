#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,N,j;
    int x;
    int digit[10]={0};

    cout<<"Enter a number: "<<endl;
    cin>>N;
    cout<<"numbers"<<endl;
    while(N--)
    {   cin>>x;
        if(x)
        {
            
            while(x)
            {
                digit[x%10]++;
                x/=10;
            }
        }
        else
        {
            digit[x]++;
        }
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<digit[i];j++)
        {
            cout<<i<<endl;
        }
        if(digit[i])
        {
            cout<<endl;
        }
    }
    return 0;
}


   
      





