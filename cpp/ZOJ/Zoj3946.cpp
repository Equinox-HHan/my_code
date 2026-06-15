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
            while(cin>>N>>M&&(N!=0||M!=0))
            {
                TIME=0,COST=0;
                getData();
                Dijkstra();
                cout<<TIME<<" "<<COST<<endl;
            }
        }
        struct Edge
        {
            int to,time,cost;
            Edge(int n,int d,int c)
            {
                this->to=n;
                this->time=d;
                this->cost=c;
            }
        };
        long long TIME,COST;
        int N,M;
        vector<vector<Edge>> graph;
        void getData()
        {
            graph.assign(N,vector<Edge>());
            for(int i=0;i<M;i++)
            {
                int x,y,d,c;
                cin>>x>>y>>d>>c;
                graph[x].push_back(Edge(y,d,c));
                graph[y].push_back(Edge(x,d,c));
            }
        }
        void Dijkstra()
        {
            vector<int> time_to_start(N,INT_MAX);
            vector<int> min_cost(N,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,0});
            time_to_start[0]=0;
            min_cost[0]=0;
            while(!pq.empty())
            {
                int time=pq.top().first;
                int u=pq.top().second;
                pq.pop();
                if(time>time_to_start[u])
                {
                    continue;
                }
                for(Edge &edge:graph[u])
                {
                    int p=edge.to;
                    int t=edge.time;
                    int c=edge.cost;
                    if(t+time_to_start[u]<time_to_start[p])
                    {
                        time_to_start[p]=t+time_to_start[u];
                        pq.push({time_to_start[p],p});
                        min_cost[p]=c+min_cost[u];
                    }
                    else if(t+time_to_start[u]==time_to_start[p]&&min_cost[p]>c)
                    {
                        min_cost[p]=c;
                    }
                }
            }
            for(int i=0;i<N;i++)
            {
                TIME+=time_to_start[i];
                COST+=min_cost[i];
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