#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int to, cap, rev;
};

vector<Edge> g[MAXN];
int level[MAXN], iter[MAXN];

void add_edge(int from, int to, int cap)
{
    g[from].push_back({to, cap, (int)g[to].size()});
    g[to].push_back({from, 0, (int)g[from].size() - 1});
}

void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (auto &e : g[v])
        {
            if (e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs_dinic(int v, int t, int f)
{
    if (v == t) return f;
    for (int &i = iter[v]; i < (int)g[v].size(); i++)
    {
        Edge &e = g[v][i];
        if (e.cap > 0 && level[v] < level[e.to])
        {
            int d = dfs_dinic(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0;
    while (true)
    {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs_dinic(s, t, INF)) > 0) flow += f;
    }
}

int main()
{
    int n, np, nc, m;
    while (scanf("%d %d %d %d", &n, &np, &nc, &m) != EOF)
    {
        int S = n, T = n + 1;
        for (int i = 0; i <= T; i++) g[i].clear();

        for (int i = 0; i < m; i++)
        {
            int u, v, z;
            scanf(" (%d,%d)%d", &u, &v, &z);
            add_edge(u, v, z);
        }

        for (int i = 0; i < np; i++)
        {
            int u, z;
            scanf(" (%d)%d", &u, &z);
            add_edge(S, u, z);
        }

        for (int i = 0; i < nc; i++)
        {
            int u, z;
            scanf(" (%d)%d", &u, &z);
            add_edge(u, T, z);
        }

        printf("%d\n", max_flow(S, T));
    }
    return 0;
}
