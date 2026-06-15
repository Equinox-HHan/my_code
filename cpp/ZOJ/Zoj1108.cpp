#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    void solve()
    {
        getData();
        DPfunc();
        cout<<n<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }
    }
    private:
    struct Info
    {
        int index;
        int weight;
        int speed;
    };
    int N=0,n=1;
    int w,s;
    int dp[1000];//dp[i]表示选第i个数的最终答案n
    int pre[1000];//用于记录老大哥位置
    int best_end;
    vector<int> ans;
    Info arr[1000];
    void getData()
    {
        Info info;
        while(cin>>w>>s)
        {
            arr[N].index=N+1;
            cin>>arr[N].weight>>arr[N].speed;
        }
        sort(arr,arr+N,[](const Info &a,const Info &b)
        {
            if(a.weight!=b.weight)
            {
                return a.weight<b.weight;
            }
            else
            {
                return a.speed>b.speed;
            }
        });
    }
    //在体重升序情况下选取速度降序
    void DPfunc()
    {
        for(int i=0;i<N;i++)
        {
            dp[i]=1;
            pre[i]=-1;
        }
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j].weight<arr[i].weight&&arr[j].speed>arr[i].speed)
                {
                    if(dp[i]<dp[j]+1)
                    {
                        ans.push_back(arr[i].index);
                        dp[i]=dp[j]+1;
                        pre[i]=j;
                    }
                }
            }
            if(dp[i]>n)
            {
                n=dp[i];
                best_end=i;
            }
        }
    }
    void prepare()
    {
        int pos=best_end;
        while(pos!=-1)
        {
            ans.push_back(arr[pos].index);
            pos=pre[pos];
        }
        reverse(ans.begin(),ans.end());
    }
};
