#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        void solve()
        {
            while(cin>>N)
            {
                getData();
                DPfunc();
                cout<<ans<<endl;
            }
        }
    private:
        int ans,N;
        int arr[100][100];
        void getData()
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    cin>>arr[i][j];
                }
            }
        }
        void DPfunc()
        {
            ans=INT_MIN;
            int zip[100];//压缩数组，确定上下两行然后压缩成一维数组
            for(int topRow=0;topRow<N;topRow++)
            {
                for(int bottom=topRow;bottom<N;bottom++)
                {
                    memset(zip,0,sizeof(zip));
                    for(int k=0;k<N;k++)//将每一列压缩
                    {
                        zip[k]+=arr[bottom][k];
                    }
                    int current_dp=0;
                    for(int k=0;k<N;k++)
                    {
                        if(current_dp>0)
                        {
                            current_dp+=zip[k];
                        }
                        else
                        {
                            current_dp=zip[k];
                        }
                    }
                    ans=max(ans,current_dp);
                }
            }
        }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    sol.solve();
    return 0;
}