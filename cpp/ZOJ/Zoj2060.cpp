#include <iostream>
#include <cstdio> // 使用 scanf/printf 会更快，或者给 cin 提速

using namespace std;

int main() {
    // 提速 cin/cout 的性能
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // 边读入边判断边输出，不需要 vector
    while (cin >> n) {
        // 注意：ZOJ 2060 要求的是小写 yes/no
        if (n % 4 == 2) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}