#include<bits/stdc++.h>
using namespace std;
const int maxN=3005;
int dp[maxN][maxN];
int parent[maxN][maxN];
int arr[maxN];
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        unordered_map<int,int> Hashmap;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int max_len=0;
        int end_i=-1,end_j=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j>i;j++)
            {
                dp[j][i]=2;
                int target=arr[j]-arr[i];
                if(Hashmap.count(target))
                {
                    int k=Hashmap[target];
                    if(k<j)
                    {
                        dp[j][i]=dp[k][j]+1;
                        parent[j][i]=k;
                    }
                }
                if(dp[j][i]>max_len)
                {
                    max_len=dp[j][i];
                    end_j=j;
                    end_i=i;
                }
            }
            Hashmap[arr[i]]=i;
        }
        if(max_len<3)
        {
            cout<<(n>=2?2:n)<<endl;
        }
        else
        {
            vector<int> res;
            cout<<max_len<<endl;
            int cur_i=end_i,cur_j=end_j;
            while(res.size()<max_len)
            {
                res.push_back(arr[cur_i]);
                if(res.size()==max_len)
                {
                    break;
                }
                int tempK=parent[cur_j][cur_i];
                cur_i=cur_j;
                cur_j=tempK;
            }
            reverse(res.begin(),res.end());
            for(int i=0;i<res.size();i++)
            {
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}