#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        string A="^__^",B="T.T";
        long long arr[90];
        long long n,k;
        Solution()
        {
            arr[1]=4,arr[2]=3;
            for(int i=3;i<90;i++)
            {
                arr[i]=arr[i-1]+arr[i-2];
            }
            func(n,k);
        }
    private:
        char func(int n,int k)
        {
            while(n>90)
            {
                n-=2;
            }
            return binarySearch(n,k);
        }
        char binarySearch(int n,int k)
        {
            if(n==1)
            {
                return A[k-1];
            }
            if(n==2)
            {
                return B[k-1];
            }
            long long left_len=arr[n-1];
            if(k<=left_len)
            {
                binarySearch(n-1,k);
            }
            else
            {
                binarySearch(n-2,k-left_len);
            }
        }
};