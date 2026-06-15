#include<bits/stdc++.h>
using namespace std;
//基于归并排序的逆序对问题
class Solution
{
    public:
        int ans;
        static const int MNUM=500;
        int arr[MNUM];
        int help[MNUM];
        void devide(int left,int right)
        {
            if(left==right)
            {
                return;
            }
            int middle=left+((right-left)>>1);
            devide(left,middle);
            devide(middle+1,right);
            merge(left,right,middle);
        }
    private:
        void merge(int left,int right,int middle)
        {
            int leftPoint=left;
            int rightPoint=middle+1;
            int pos=left;
            while(leftPoint<=middle&&rightPoint<=right)
            {
                if(arr[leftPoint]<=arr[rightPoint])
                {
                    help[pos++]=arr[leftPoint++];
                }
                else
                {
                    help[pos++]=arr[rightPoint++];
                    ans+=(middle-leftPoint+1);
                }
            }
            while(leftPoint<=middle)
            {
                help[pos++]=arr[leftPoint++];
            }
            while(rightPoint<=right)
            {
                help[pos++]=arr[rightPoint++];
            }
            for(int i=left;i<=right;i++)
            {
                arr[i]=help[i];
            }
        }
};