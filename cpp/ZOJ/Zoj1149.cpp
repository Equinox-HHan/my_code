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
        int sum,target;
        bool ans;
        int marbles[7];
        void solve()
        {
            int casenum=1;
            sum=0;
            while(true)
            {
                for(int i=1;i<7;i++)
                {
                    cin>>marbles[i];
                    sum+=i*marbles[i];
                }
                if(sum==0)
                {
                    break;
                }
                cout<<"Collection #"<<casenum++<<":"<<endl;
                if(sum%2!=0)
                {
                    cout<<"Can't be devided"<<endl;
                    cout<<endl;
                    continue;
                }
                target=sum/2;
                DPfunc();
                if(ans==false)
                {
                    cout<<"Can't be devided"<<endl;
                }
                else
                {
                    cout<<"Can be devided"<<endl;
                }
                cout<<endl;
            }
        }
        void DPfunc()
        {
            vector<bool> dp(target+1,false);
            dp[0]=true;
            for(int i=1;i<7;i++)
            {
                if(marbles[i]==0)
                {
                    continue;
                }
                vector<int> use(target+1,0);
                for(int j=i;j<=target;j++)
                {
                    if(!dp[j]&&dp[j-i]&&use[j-i]<marbles[i])
                    {
                        dp[j]=true;
                        use[j]=use[j-i]+1;
                    }
                }
            }
            ans=dp[target];
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