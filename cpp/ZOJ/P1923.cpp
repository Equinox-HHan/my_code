#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        int first,last,ans;
        int n,k;
        const static int maxn=3000;
        int arr[maxn];
        Solution(){}
        void solve()
        {
            quickSelect(n,k);
        }
    private:
        void quickSelect(int n,int k)
        {
            srand((unsigned)time(NULL));
            int l=0,r=n-1;
            while(l<=r)
            {
                int index=l+rand()%(r-l+1);
                int x=arr[index];
                partation(l,r,x);
                if(k<first)
                {
                    r=first-1;
                }
                else if(k>last)
                {
                    l=last+1;
                }
                else
                {
                    ans=arr[k];
                    break;
                }
            }
            return;
        }
        void partation(int left,int right,int x)
        {
            first=left,last=right;
            int pos=left;
            while(pos<=last)
            {
                if(arr[pos]==x)
                {
                    pos+=1;
                }
                else if(arr[pos]<x)
                {
                    swap(arr[pos],arr[first]);
                    pos+=1,first+=1;
                }
                else
                {
                    swap(arr[pos],arr[last]);
                    last-=1;
                }
            }
            return;
        }
};
int main()
{
    Solution s;
    cin>>s.n>>s.k;
    for(int i=0;i<s.n;i++)
    {
        cin>>s.arr[i];
    }
    s.solve();
    cout<<s.ans;
    return 0;
}