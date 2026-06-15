#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<int>> dp_next;
    int w1, w2, w3, s1, s2, s3, d1, d2, d3;
    int c1, c2, c3, d0;
    int number; // 商队的总数量
    int XY[500][2]; // 单个商队能携带的最大重量和尺寸
    long long max_def; // 记录最终答案

public:
    // 核心调用接口，返回 false 表示读取到 n=0，结束程序
    bool solve() {
        if (!getData()) return false;
        initDP();
        DPfunc();
        getSum();
        cout << max_def << endl;
        return true;
    }

private:
    // 数据读取函数
    bool getData() {
        if (!(cin >> number) || number == 0) return false;
        
        cin >> w1 >> s1 >> d1;
        cin >> w2 >> s2 >> d2;
        cin >> w3 >> s3 >> d3;
        cin >> c1 >> c2 >> c3 >> d0;
        
        for (int i = 0; i < number; i++) {
            cin >> XY[i][0] >> XY[i][1];
        }
        return true;
    }

    // DP 初始化（因为可能有多组测试数据，每次都要重新初始化）
    void initDP() {
        // 大小设为 501，避免越界
        dp.assign(501, vector<int>(501, -1));
        max_def = 0;
        dp[0][0] = 0; // 核心：什么都不拿也是一种合法状态
    }

    // DP 核心函数
    void DPfunc() {
        for (int i = 0; i < number; i++) {
            int max_w = XY[i][0];
            int max_s = XY[i][1];
            
            // 每次使用前，把 dp_next 刷成全新的全 -1 状态
            dp_next.assign(501, vector<int>(501, -1));

            // dh, da 是当前这辆车携带的数量
            for (int dh = 0; dh <= 500 && dh * w1 <= max_w && dh * s1 <= max_s; dh++) {
                for (int da = 0; dh + da <= 500 && dh * w1 + da * w2 <= max_w && dh * s1 + da * s2 <= max_s; da++) {
                    
                    // 贪心：算出当前车最多还能装多少靴子（补上 /s3）
                    int max_b = min((max_w - dh * w1 - da * w2) / w3, 
                                    (max_s - dh * s1 - da * s2) / s3);
                    if (max_b < 0) continue;

                    // 遍历历史状态 (h, a)
                    for (int h = 0; h <= 500 - dh; h++) {
                        for (int a = 0; a <= 500 - da; a++) {
                            // 只有历史状态存在时才允许转移
                            if (dp[h][a] != -1) {
                                dp_next[h + dh][a + da] = max(dp_next[h + dh][a + da], dp[h][a] + max_b);
                            }
                        }
                    }
                }
            }
            // 滚动覆盖
            dp = dp_next;
        }
    }

    // 计算最高防御力
    void getSum() {
        // 必须双重循环遍历整张 DP 表
        for (int h = 0; h <= 500; h++) {
            for (int a = 0; a <= 500; a++) {
                int b = dp[h][a]; // 提取出对应的靴子最大数量
                if (b == -1) continue; // 如果该组合不可达，跳过

                int max_k = 500;
                if (c1 == 0 && c2 == 0 && c3 == 0) {
                    max_k = 0;
                } else {
                    if (c1 > 0) max_k = min(max_k, h / c1);
                    if (c2 > 0) max_k = min(max_k, a / c2);
                    if (c3 > 0) max_k = min(max_k, b / c3);
                }

                // 枚举组装 k 套
                for (int k = 0; k <= max_k; k++) {
                    long long current_d = (long long)k * d0 +
                                          (long long)(h - k * c1) * d1 +
                                          (long long)(a - k * c2) * d2 +
                                          (long long)(b - k * c3) * d3;
                    max_def = max(max_def, current_d);
                }
            }
        }
    }
};

int main() {
    // 提升 cin / cout 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    // 循环处理多组数据，直到遇到 n = 0 返回 false 为止
    while (sol.solve()) {
        // Do nothing, solve() has done everything.
    }
    return 0;
}
