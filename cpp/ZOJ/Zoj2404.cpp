#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

// Hungarian algorithm for minimum cost assignment
int hungarian(const vector<vector<int>> &cost)
{
    int n = cost.size();
    vector<int> u(n + 1, 0), v(n + 1, 0), p(n + 1, 0), way(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(n + 1, INF);
        vector<bool> used(n + 1, false);
        do
        {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1 = 0;
            for (int j = 1; j <= n; j++)
            {
                if (!used[j])
                {
                    int cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j])
                    {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta)
                    {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= n; j++)
            {
                if (used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            }
            j0 = j1;
        } while (p[j0] != 0);
        do
        {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    return -v[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M && (N || M))
    {
        vector<string> grid(N);
        for (int i = 0; i < N; i++) cin >> grid[i];

        vector<pair<int, int>> men, houses;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == 'm') men.push_back({i, j});
                if (grid[i][j] == 'H') houses.push_back({i, j});
            }
        }

        int sz = men.size();
        vector<vector<int>> cost(sz, vector<int>(sz));
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                cost[i][j] = abs(men[i].first - houses[j].first)
                           + abs(men[i].second - houses[j].second);
            }
        }

        cout << hungarian(cost) << endl;
    }
    return 0;
}
