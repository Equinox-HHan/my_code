#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        void func()
        {
            solve();
        }
    private:
        int n,k,ans;
        int pos[205];
        int dp[35][205];
        int cost[205][205];
        int path[35][205];
        void solve()
        {
            while(true)
            {
                int chain=1;
                cin>>n>>k;
                if(n==0&&k==0)
                {
                    break;
                }
                for(int i=1;i<=n;i++)
                {
                    cin>>pos[i];
                }
                initCost();
                Dpfunc();
                cout<<"Chain "<<chain++<<endl;
                cout<<"Total distance sum="<<ans<<endl;
                printPath();
            }
        }
        void initCost()
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i;j<=n;j++)
                {
                    int mid=(i+j)/2;
                    int sum=0;
                    for(int x=i;x<=j;x++)
                    {
                        sum+=abs(pos[x]-pos[mid]);
                    }
                    cost[i][j]=sum;
                }
            }
        }
        void Dpfunc()
        {
            for(int i=1;i<=k;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    dp[i][j]=10000;
                }
            }
            for(int j=1;j<=n;j++)
            {
                dp[1][j]=cost[1][j];
                path[1][j]=0;
            }
            for(int i=2;i<=k;i++)
            {
                for(int j=i;j<=n;j++)
                {
                    for(int m=i-1;m<j;m++)
                    {
                        int cur_cost=dp[i-1][m]+cost[m+1][j];
                        if(cur_cost<dp[i][j])
                        {
                            path[i][j]=m;
                            dp[i][j]=cur_cost;
                        }
                    }
                }
            }
            ans=dp[k][n];
        }
        void printPath()
        {
            vector<int> start;
            vector<int> end;
            int last=n;
            for(int p=k;p>0;p--)
            {
                int m=path[p][last];
                start[p]=m+1;
                end[p]=last;
                last=m;
            }
            for(int i=1;i<=k;i++)
            {
                int startpos=start[i];
                int endpos=end[i];
                int middle=(startpos+endpos)/2 ;
                cout<<middle<<endl;
            }
        }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    sol.func();
    return 0;
}