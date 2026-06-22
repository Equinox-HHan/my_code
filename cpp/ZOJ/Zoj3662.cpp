#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    while (cin >> N >> M >> K)
    {
        vector<int> divs;
        for (int i = 1; i <= M; i++)
        {
            if (M % i == 0) divs.push_back(i);
        }
        int D = divs.size();

        unordered_map<int, int> idx;
        for (int i = 0; i < D; i++)
        {
            idx[divs[i]] = i;
        }

        // Precompute LCM table
        vector<vector<int>> lcm_tab(D, vector<int>(D, -1));
        for (int i = 0; i < D; i++)
        {
            for (int j = 0; j < D; j++)
            {
                int l = lcm(divs[i], divs[j]);
                if (l <= M && M % l == 0)
                    lcm_tab[i][j] = idx[l];
            }
        }

        vector<vector<int>> dp(N + 1, vector<int>(D, 0));
        dp[0][idx[1]] = 1;

        for (int k = 0; k < K; k++)
        {
            vector<vector<int>> ndp(N + 1, vector<int>(D, 0));
            for (int sum = 0; sum <= N; sum++)
            {
                for (int l = 0; l < D; l++)
                {
                    int cur = dp[sum][l];
                    if (cur == 0) continue;
                    for (int d = 0; d < D; d++)
                    {
                        int nsum = sum + divs[d];
                        if (nsum > N) continue;
                        int nl = lcm_tab[l][d];
                        if (nl == -1) continue;
                        ndp[nsum][nl] = (ndp[nsum][nl] + cur) % MOD;
                    }
                }
            }
            dp = move(ndp);
        }

        cout << dp[N][idx[M]] << endl;
    }
    return 0;
}
