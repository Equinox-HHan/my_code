#include<bits/stdc++.h>
using namespace std;

const int MAXN = 405;

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

void solve_block()
{
    int n, m, k;
    cin >> n;

    vector<string> rec_types(n);
    unordered_map<string, int> type_id;
    int tid = 0;

    auto get_id = [&](const string &s) {
        if (!type_id.count(s)) type_id[s] = tid++;
        return type_id[s];
    };

    for (int i = 0; i < n; i++)
    {
        cin >> rec_types[i];
        get_id(rec_types[i]);
    }

    cin >> m;
    vector<int> device_plug(m);
    for (int i = 0; i < m; i++)
    {
        string name, plug;
        cin >> name >> plug;
        device_plug[i] = get_id(plug);
    }

    cin >> k;
    int T = tid;
    vector<vector<bool>> reach(T, vector<bool>(T, false));
    for (int i = 0; i < T; i++) reach[i][i] = true;

    for (int i = 0; i < k; i++)
    {
        string rec_type, plug_type;
        cin >> rec_type >> plug_type;
        int r = get_id(rec_type);
        int p = get_id(plug_type);
        reach[p][r] = true;
    }

    for (int mid = 0; mid < T; mid++)
        for (int i = 0; i < T; i++)
            for (int j = 0; j < T; j++)
                if (reach[i][mid] && reach[mid][j])
                    reach[i][j] = true;

    for (int i = 0; i < m; i++)
    {
        adj[i].clear();
        int plug = device_plug[i];
        for (int j = 0; j < n; j++)
        {
            int rec = type_id[rec_types[j]];
            if (reach[plug][rec])
            {
                adj[i].push_back(j);
            }
        }
    }

    memset(match, -1, sizeof(match));
    int matching = 0;
    for (int i = 0; i < m; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) matching++;
    }

    cout << m - matching << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    // Skip blank line after N
    string dummy;
    getline(cin, dummy);

    for (int block = 0; block < N; block++)
    {
        // Skip blank lines between blocks
        while (cin.peek() == '\n' || cin.peek() == '\r') cin.get();

        solve_block();

        // Output blank line between blocks (but not after the last)
        if (block < N - 1) cout << endl;
    }

    return 0;
}
