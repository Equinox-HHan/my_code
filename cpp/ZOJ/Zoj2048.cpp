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
        struct Edge
        {
            int index;
            int x,y;
        };
        struct Distance
        {
            double distance;
            int point1;
            int point2;
            Distance(double d,int a,int b)
            {
                distance=d;
                point1=a;
                point2=b;
            }
        };
        int testN;
        int n,m;
        vector<Edge> point;
        vector<Distance> dis;
        vector<int> boss;
        vector<pair<int,int>> ans;
        void solve()
        {
            cin>>testN;
            while(testN--)
            {
                prepare();
                kruskal();
                for(auto &e:ans)
                {
                    cout<<e.first<<" "<<e.second<<endl;
                }
                ans.clear();
                point.clear();
                dis.clear();
            }
        }
        void prepare()
        {
            cin>>n;
            point.assign(n,Edge());
            auto discount=[](const Edge &a,const Edge &b)->double
            {
                return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
            };
            for(int i=0;i<n;i++)
            {
                cin>>point[i].x>>point[i].y;
                point[i].index=i+1;
            }
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    double distance=discount(point[i],point[j]);
                    dis.push_back(Distance(distance,i,j));
                }
            }
            sort(dis.begin(),dis.end(),[](const Distance &a,const Distance &b)
            {   
                return a.distance<b.distance;
            });
        }
        void kruskal()
        {      
            boss.assign(n+1,0);
            for(int i=1;i<=n;i++)
            {
                boss[i]=i;
            }
            cin>>m;
            for(int i=0;i<m;i++)
            {
                int u,v;
                cin>>u>>v;
                int rootu=findboss(u);
                int rootv=findboss(v);
                boss[rootu]=rootv;
            }
            pair<int,int> p;
            for(int i=0;i<dis.size();i++)
            {
                int u=point[dis[i].point1].index;
                int v=point[dis[i].point2].index;
                int ru=findboss(u);
                int rv=findboss(v);
                if(ru!=rv)
                {
                    boss[ru]=rv;
                    p.first=u;
                    p.second=v;
                    ans.push_back(p);
                }
                else
                {
                    continue;
                }
            }
        }
        int findboss(int x)
        {
            if(boss[x]==x)
            {
                return x;
            }
            else
            {
                return boss[x]=findboss(boss[x]);
            }
        }
};