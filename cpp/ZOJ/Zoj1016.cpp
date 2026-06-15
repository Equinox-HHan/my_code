#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    string brackets; // 存储生成的括号字符串，如 "((()())"
    int wArray[25];  // 存储结果 W 序列

    // 核心修改1：从 P 序列正确还原括号字符串
    void transferP(vector<int> &pList) {
        brackets = "";
        int lastLeftCount = 0;
        for (int i = 0; i < pList.size(); i++) {
            int currentLeftCount = pList[i];
            // 补充新增的左括号
            for (int j = 0; j < currentLeftCount - lastLeftCount; j++) {
                brackets += '(';
            }
            // 放入当前的右括号
            brackets += ')';
            lastLeftCount = currentLeftCount;
        }
    }

    // 核心修改2：从括号字符串推导 W 序列
    void transferW(int n) {
        int wIndex = 0;
        // 遍历字符串，每当遇到右括号，向左寻找匹配的左括号
        for (int i = 0; i < brackets.length(); i++) {
            if (brackets[i] == ')') {
                int leftCount = 0;
                int rightCount = 1; // 当前这个右括号
                
                // 向左扫描寻找匹配的 '('
                for (int j = i - 1; j >= 0; j--) {
                    if (brackets[j] == ')') {
                        rightCount++;
                    } else if (brackets[j] == '(') {
                        leftCount++;
                        // 当左括号数量等于右括号数量时，说明找到了匹配的那一个
                        //核心在于左括号数量等于右括号
                        if (leftCount == rightCount) {
                            wArray[wIndex++] = leftCount;
                            break;
                        }
                    }
                }
            }
        }
    }

    void reset() {
        brackets = "";
        memset(wArray, 0, sizeof(wArray));
    }
};

int main() {
    int round;
    if (!(cin >> round)) return 0;
    Solution solution;
    while (round--) {
        int n;
        cin >> n;
        vector<int> pList;
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            pList.push_back(temp);
        }

        solution.reset();
        solution.transferP(pList);
        solution.transferW(n);

        for (int k = 0; k < n; k++) {
            cout << solution.wArray[k] << (k == n - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}