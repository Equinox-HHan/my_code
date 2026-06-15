#include <iostream>
using namespace std;

bool hasDuplicateDigits(int num) {
    int digits[10] = {0};
    
    // ABCDE 是5位数，检查5位数字
    for (int i = 0; i < 5; i++) {
        int digit = num % 10;
        if (digits[digit] > 0) return true;
        digits[digit]++;
        num /= 10;
    }
    return false;
}

bool isValidNumber(int num) {
    // 检查是否是5位数且各位数字不重复
    if (num < 10000 || num > 99999) return false;
    return !hasDuplicateDigits(num);
}

int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    cout << "寻找符合 ABCDE * ? = EDCBA 的算式：" << endl;
    cout << "其中ABCDE是各位数字都不相同的5位数" << endl << endl;
    
    bool found = false;
    
    for (int abcde = 10000; abcde <= 99999; abcde++) {
        if (!isValidNumber(abcde)) continue;
        
        int edcba = reverseNumber(abcde);
        
        // 检查edcba是否是5位数且各位数字不重复
        if (edcba < 10000 || edcba > 99999) continue;
        if (hasDuplicateDigits(edcba)) continue;
        
        // 检查是否能整除
        if (abcde == 0) continue;
        
        if (edcba % abcde == 0) {
            int multiplier = edcba / abcde;
            // 乘数必须是1位数 (1-9)
            if (multiplier >= 1 && multiplier <= 9) {
                cout << abcde << " * " << multiplier << " = " << edcba << endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        cout << "没有找到符合条件的算式" << endl;
    }
    
    return 0;
}