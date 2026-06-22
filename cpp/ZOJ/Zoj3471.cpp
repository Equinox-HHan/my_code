#include<bits/stdc++.h>
using namespace std;

int p[10][10];
int dp[1 << 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N && N)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> p[i][j];

        memset(dp, 0, sizeof(dp));
        int full = (1 << N) - 1;
        int ans = 0;

        for (int mask = full; mask >= 0; mask--)
        {
            int cnt = 0;
            int m = mask;
            while (m) { cnt++; m &= m - 1; }

            if (cnt == 1)
            {
                ans = max(ans, dp[mask]);
            }

            for (int i = 0; i < N; i++)
            {
                if (!(mask & (1 << i))) continue;
                for (int j = 0; j < N; j++)
                {
                    if (i == j || !(mask & (1 << j))) continue;
                    int nmask = mask ^ (1 << j);
                    dp[nmask] = max(dp[nmask], dp[mask] + p[i][j]);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
