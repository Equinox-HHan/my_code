#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter a number as N"<<endl;
    int N;
    cin>>N;
    cout<<"please enter N's income"<<endl;
    int a[10]={0};
    int sum=0;
    int x;
    int i;
    for(i=0;i<N;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    x=sum/N;
    cout<<"the average is "<<x<<endl;
    sort(a,a+N);
    if (N%2==0)
    {
        int middle;
        int A,B;
        A=a[N/2];B=a[N/2-1];
        middle=(A+B)/2;
        cout<<"the middle number is: "<<middle<<endl;
    }
    else
    {
        cout<<"the middle number is: "<<a[(N-1)/2]<<endl; 
    }   
   return 0;
}
 