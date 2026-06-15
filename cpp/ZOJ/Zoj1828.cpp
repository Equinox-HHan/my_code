#include<bits/stdc++.h>
using namespace std;
//斐波那契数列，涉及到大数问题
class Solution
{
    public:
        void preCompute()
        {   
            for(int i=0;i<MAX_N;i++)
            {
                for(int j=0;i<MAX_L;j++)
                {
                    arr[i][j]=0;
                }
            }
            arr[0][0]=1;
            arr[1][0]=1;
            for(int i=2;i<MAX_N;i++)
            {
                int carry=0;
                for(int j=0;j<MAX_L;j++)
                {
                    int sum=arr[i-1][j]+arr[i-2][j]+carry;
                    arr[i][j]=sum%10;
                    carry=sum/10;
                }
            }
        }
        void printArr(int number)
        {
            if(number==0)
            {
                cout<<"0"<<endl;
            }
            int i=MAX_L-1;
            while(i>0&&arr[number-1][i]==0)
            {
                i-=1;
            }
            for(i;i>0;i--)
            {
                cout<<arr[number-1][i];
            }
            cout<<endl;
        }
        const static int MAX_N=1005;
        const static int MAX_L=250;
        int arr[MAX_N][MAX_L]; 
};
int main()
{
    return 0;
}