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
        void solve()
        {
            int num=1;
            while(cin>>N&&N!=0)
            {
                getData();
                ans=prim();
            }
            cout<<"Case #:"<<num<<endl;
            cout<<"The minimal distance is:"<<ans<<endl;
            num+=1;
        }
        struct Edge
        {
            double weight;
            int towhere;
            Edge(double w,int t):
            weight(w),towhere(t){};
        };
        struct Point
        {
            double x,y;
            Point():x(0),y(0){}
            Point(double x,double y)
            {
                this->x=x;
                this->y=y;
            }
        };
        double ans;
        int N;
        vector<bool> is_mst;
        vector<Point> point;
        vector<vector<Edge>> graph;
        double getDistance(Point a,Point b)
        {
            double dis;
            dis=sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
            return dis;
        }
        void getData()
        {
            is_mst.assign(N,false);
            point.assign(N,Point());
            graph.assign(N,vector<Edge>());
            for(int i=0;i<N;i++)
            {
                cin>>point[i].x>>point[i].y;
            }
            for(int i=0;i<N;i++)
            {
                for(int j=i+1;j<N;j++)
                {
                    double distance=getDistance(point[i],point[j]);
                    graph[i].push_back(Edge(distance,j));
                    graph[j].push_back(Edge(distance,i));
                }
            }
        }
        double prim()
        {
            int total=0;
            double cost=0;
            priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
            pq.push({0.0,0});
            while(!pq.empty())
            {
                double w=pq.top().first;
                int u=pq.top().second;
                pq.pop();
                if(is_mst[u]==true)
                {
                    continue;
                }
                cost+=w;
                total+=1;
                is_mst[u]=true;
                if(total==N)
                {
                    break;
                }
                for(Edge &edge:graph[u])
                {
                    int p=edge.towhere;
                    double v=edge.weight;
                    if(is_mst[p]==false)
                    {
                        pq.push({v,p});
                    }
                }
            }
            return cost;
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