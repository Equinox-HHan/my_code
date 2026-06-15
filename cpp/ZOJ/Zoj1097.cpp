#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

// 题目给出 n <= 50，数组开到 100 足够安全
vector<int> adj[101];
int deg[101];
set<int> nodes;
int pos;
string line;

// 辅助函数：从字符串当前位置提取数字
int getNum() {
    int res = 0;
    while (pos < (int)line.size() && isdigit(line[pos])) {
        res = res * 10 + (line[pos] - '0');
        pos++;
    }
    return res;
}

// 递归解析树结构并建立邻接表
int parseTree() {
    while (pos < (int)line.size() && line[pos] != '(') pos++;
    pos++; // 跳过 '('
    
    // 跳过空格
    while (pos < (int)line.size() && isspace(line[pos])) pos++;
    
    int u = getNum();
    nodes.insert(u);
    
    while (true) {
        while (pos < (int)line.size() && isspace(line[pos])) pos++;
        if (pos >= (int)line.size()) break;
        
        if (line[pos] == '(') {
            // 递归解析子树
            int v = parseTree();
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        } else if (line[pos] == ')') {
            pos++; // 结束当前节点的处理
            break;
        }
    }
    return u;
}

void solve() {
    if (nodes.empty()) return;
    
    int n = nodes.size();
    int maxNode = 0;
    for (int x : nodes) if (x > maxNode) maxNode = x;

    vector<int> result;
    // 使用临时度数数组进行模拟移除
    vector<int> currentDeg(101, 0);
    for(int x : nodes) currentDeg[x] = deg[x];

    // 本题要求生成 n-1 个数字
    for (int i = 0; i < n - 1; ++i) {
        int leaf = -1;
        // 1. 寻找当前编号最小的叶子节点 (度数为1)
        for (int j = 1; j <= maxNode; ++j) {
            if (currentDeg[j] == 1) {
                leaf = j;
                break;
            }
        }
        
        if (leaf == -1) break;

        // 2. 找到该叶子的唯一邻居
        int neighbor = -1;
        for (int nbr : adj[leaf]) {
            if (currentDeg[nbr] > 0) {
                neighbor = nbr;
                break;
            }
        }
        
        // 3. 记录邻居并更新度数
        result.push_back(neighbor);
        currentDeg[leaf] = 0;
        currentDeg[neighbor]--;
    }

    // 格式化输出
    for (int i = 0; i < (int)result.size(); ++i) {
        cout << result[i] << (i == (int)result.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    // 快速 I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        line = "";
        string temp;
        int balance = 0;
        bool started = false;
        
        // 读取直到括号匹配完整（处理跨行输入）
        while (getline(cin, temp)) {
            line += " " + temp;
            for (char c : temp) {
                if (c == '(') {
                    balance++;
                    started = true;
                } else if (c == ')') {
                    balance--;
                }
            }
            if (started && balance <= 0) break;
        }
        
        if (!started) break; // EOF
        
        // 重置数据
        for (int i = 0; i < 101; ++i) adj[i].clear();
        for (int i = 0; i < 101; ++i) deg[i] = 0;
        nodes.clear();
        pos = 0;
        
        parseTree();
        solve();
    }
    return 0;
}