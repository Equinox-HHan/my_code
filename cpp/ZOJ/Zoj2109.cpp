#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        double func()
        {
            return ans;
        }
    private:
        struct Info//表示第i个房间的内容
        {
            int javabeans;
            int catfood;
            double proportion;
        }info; 
        int M,N;
        double ans=0;
        vector<Info> arr;
        void solve()
        {
            while(cin>>M>>N&&M!=-1&&N!=-1)
            {
                arr.assign(N,info);
                getData();
                greedy();
                arr.clear(); 
            }
        }
        void getData()
        {
            for(int i=0;i<N;i++)
            {
                cin>>arr[i].javabeans>>arr[i].catfood;
                arr[i].proportion=((double)arr[i].javabeans/(double)arr[i].catfood);
            }
            sort(arr.begin(),arr.end(),[](const Info &a,const Info &b)
                {
                    return a.proportion>b.proportion;
                });
        }
        void greedy()
        {   
            int count=0;
            for(count;count<N;count++)
            {
                if(M<=0)
                {
                    break;
                }   
                if(M>arr[count].catfood)
                {
                    M-=arr[count].catfood;
                    ans+=arr[count].javabeans;
                }
                else
                {
                    ans+=M*arr[count].javabeans;
                    M=0;
                    break;
                }
            }
            return;
        }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    cout<<sol.func()<<endl;
    return 0;
}