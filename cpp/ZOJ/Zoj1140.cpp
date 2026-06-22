#include<bits/stdc++.h>
using namespace std;

const int MAXN = 305;

vector<int> adj[MAXN];
int match[MAXN];
bool vis[MAXN];

bool dfs(int u)
{
    for (int v : adj[u])
    {
        if (vis[v]) continue;
        vis[v] = true;
        if (match[v] == -1 || dfs(match[v]))
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

    int T;
    cin >> T;
    while (T--)
    {
        int P, N;
        cin >> P >> N;
        for (int i = 1; i <= P; i++)
        {
            adj[i].clear();
            int cnt;
            cin >> cnt;
            for (int j = 0; j < cnt; j++)
            {
                int s;
                cin >> s;
                adj[i].push_back(s);
            }
        }

        memset(match, -1, sizeof(match));
        int matching = 0;
        for (int i = 1; i <= P; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (dfs(i)) matching++;
        }

        cout << (matching == P ? "YES" : "NO") << endl;
    }
    return 0;
}
