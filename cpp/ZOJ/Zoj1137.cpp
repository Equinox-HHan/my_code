#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

vector<int> adj[MAXN];
int color[MAXN];
int match[MAXN];
bool vis[MAXN];
int n;

bool dfs_color(int u, int c)
{
    color[u] = c;
    for (int v : adj[u])
    {
        if (color[v] == -1)
        {
            if (!dfs_color(v, 1 - c)) return false;
        }
        else if (color[v] == c)
        {
            return false;
        }
    }
    return true;
}

bool dfs_match(int u)
{
    for (int v : adj[u])
    {
        if (vis[v]) continue;
        vis[v] = true;
        if (match[v] == -1 || dfs_match(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            color[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            int id, cnt;
            char colon, lp, rp;
            cin >> id >> colon >> lp >> cnt >> rp;
            for (int j = 0; j < cnt; j++)
            {
                int v;
                cin >> v;
                adj[id].push_back(v);
                adj[v].push_back(id);
            }
        }

        bool bipartite = true;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs_color(i, 0))
                {
                    bipartite = false;
                    break;
                }
            }
        }

        if (!bipartite)
        {
            cout << 0 << endl;
            continue;
        }

        vector<int> left_side;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0) left_side.push_back(i);
        }

        memset(match, -1, sizeof(match));
        int matching = 0;
        for (int u : left_side)
        {
            memset(vis, 0, sizeof(vis));
            if (dfs_match(u)) matching++;
        }

        cout << n - matching << endl;
    }
    return 0;
}
