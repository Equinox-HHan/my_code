#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> all_paths;  // 存储所有路径

void dfs(int current_energy, vector<int>& path) {
    // 如果当前能量为1，不再分裂，保存当前路径
    if (current_energy == 1) {
        all_paths.push_back(path);
        return;
    }
    
    // 对于当前能量，第一个子体可以取1到current_energy/2（包含）
    for (int first_child = 1; first_child <= current_energy / 2; first_child++) {
        // 将第一个子体加入路径
        path.push_back(first_child);
        // 继续分裂第一个子体（因为它可能还大于1）
        dfs(first_child, path);
        // 回溯
        path.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> path;
    path.push_back(n);  // 路径起始是初始能量
    
    dfs(n, path);
    
    // 输出所有繁殖路径
    for (int i = 0; i < all_paths.size(); i++) {
        // 按格式输出：10 -> x -> y -> ... -> 1
        for (int j = 0; j < all_paths[i].size(); j++) {
            cout << all_paths[i][j];
            if (j < all_paths[i].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
