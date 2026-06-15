#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

bool isLeapYear(int year) 
{
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

int main() {
    cout<<"enter the numbers"<<endl;
    int x, y, z;
    cin >> x >> y >> z;
    
    if (y % x != 0) {
        cout << "-" << endl;
        return false;
    }
    
    int k = y / x; //k=a*b
    vector<pair<int, int>> solutions;
    
    for (int a = 1; a * a <= k; a++) {
        if (k % a == 0) {
            int b = k / a;
            if (__gcd(a, b) == 1) {
                // 第一种顺序
                int month1 = x * a;
                int day1 = x * b;
                if (month1 >= 1 && month1 <= 12 && day1 >= 1 && day1 <= daysInMonth(month1, z)) {
                    solutions.push_back({month1, day1});
                }
                // 第二种顺序
                if (a != b) {
                    int month2 = x * b;
                    int day2 = x * a;
                    if (month2 >= 1 && month2 <= 12 && day2 >= 1 && day2 <= daysInMonth(month2, z)) {
                        solutions.push_back({month2, day2});
                    }
                }
            }
        }
    }
    
    // 去重（其实不会重复，因为a,b不同，但交换可能重复吗？交换后月份不同或日期不同）
    // 直接按数量判断即可
    if (solutions.empty()) {
        cout << "-" << endl;
    } else if (solutions.size() > 1) {
        cout << "+" << endl;
    } else {
        cout << z << "/" 
             << setw(2) << setfill('0') << solutions[0].first << "/" 
             << setw(2) << setfill('0') << solutions[0].second << endl;
    }
    
    return 0;
}