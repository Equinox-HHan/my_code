#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        void solve()
        {
            func();
        }
    private:
        struct Info
        {
            int leng;
            int weight;
        }info;
        int n,T;
        int dp;//单个变量滚动表示加工到第i根木棍需要的总时长
        vector<Info> arr;//写入数据排序时使用
        vector<bool> visited;//打标签的数组
        void func()
        {
            cin>>T;
            while(T--)
            {
                while(cin>>n&&n!=0)
                {
                    getData();
                    DPGreedy();
                    cout<<dp<<endl;
                }
            }
        }
        void getData()
        {
            arr.assign(n,info);
            for(int i=0;i<n;i++)
            {
                cin>>arr[i].leng>>arr[i].weight;
            }
            sort(arr.begin(),arr.end(),[](const Info &a,const Info &b)
            {
                if(a.leng<b.leng)
                {
                    return true;//以长度递增排序
                }
                else
                {
                    return a.weight<b.weight;
                }
            });
        }
        void DPGreedy()
        {
            visited.assign(n,false);
            dp=0;
            for(int i=0;i<n;i++)
            {
                if(visited[i]=true)
                {
                    continue;
                }
                visited[i]=true;
                dp+=1;
                int w=arr[i].weight;
                for(int j=i+1;j<n;j++)
                {
                    if(!visited[j]&&arr[j].weight>=w)
                    {
                        visited[j]=true;
                        w=arr[j].weight;
                    }
                }
            }
        }
};