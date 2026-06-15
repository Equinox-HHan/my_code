#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

// 这里定义 bitset 大小。ZOJ 这题如果 E 最大 1e8，需要用 bitset 数组或者动态位图优化。
// 这里给出 100005 是为了展示算法逻辑，实际可能需要手写动态 bitset 压位。
const int MAX_E = 100005; 
bitset<MAX_E> dp;

struct Choice {
    int opt1, opt2;
};

void solve() {
    int T;
    if (!(cin >> T)) return;
    
    while (T--) {
        int S;
        cin >> S;
        vector<int> freq(S);
        for (int i = 0; i < S; i++) {
            cin >> freq[i];
        }
        int E;
        cin >> E;
        
        // 1. 模拟哈夫曼树，获取所有二选一的选项
        vector<Choice> choices;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int f : freq) pq.push(f);
        
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            choices.push_back({a, b});
            pq.push(a + b);
        }
        
        // 2. 判断 E 是不是太离谱了（如果 E 超过了我们能表示的最大范围，肯定不可能）
        if (E >= MAX_E) {
            cout << "No\n";
            continue;
        }
        
        // 3. 用 bitset 开始跑 DP
        dp.reset(); // 清空所有开关
        dp[0] = 1;  // 点亮第 0 号
        
        for (const auto& c : choices) {
            // 平移并合并！
            dp = (dp << c.opt1) | (dp << c.opt2);
        }
        
        // 4. 查答案
        if (dp[E] == 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
