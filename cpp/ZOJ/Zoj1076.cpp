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
        struct Info
        {
            int start;
            int over;
            int index;
        }info;
        int n;
        vector<Info> arr;
        vector<int> ans;
        void solve()
        {
            while(cin>>n&&n!=0)
            {
                arr.assign(n,info);
                getData();
                greedy();
                arr.clear();
                ans.clear();
            }
        }
        void getData()
        {
            for(int i=0;i<n;i++)
            {
                cin>>arr[i].start>>arr[i].over;
                arr[i].index=i+1;
            }
            sort(arr.begin(),arr.end(),[](const Info &a,const Info &b)
            {
                return a.over<b.over;
            });
        }
        void greedy()
        {
            int record=arr[0].over;
            ans.push_back(arr[0].index);
            for(int i=1;i<n;i++)
            {
                if(record<=arr[i].start)
                {   
                    record=arr[i].over;
                    ans.push_back(arr[i].index);
                }
                else
                {
                    continue;
                }
            }
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<endl;
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