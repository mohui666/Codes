#include <iostream>
#include <algorithm>
using namespace std;

string s1, s2;
int a[101], b[101], c[101] = {0};

void strToInt(string s, int a[]) {
    // 将字符串转换为倒序的整数数组
    for (int i = 0; i < s.size(); i++) {
        a[i + 1] = s[s.size() - 1 - i] - '0'; // 从低位开始存储
    }
}

int main() {
    // 输入两个大数字符串
    cin >> s1 >> s2;
    
    // 将字符串转换为对应的整数数组
    strToInt(s1, a);
    strToInt(s2, b);
    
    int la = s1.size(), lb = s2.size();
    int lc = max(la, lb) + 1;
    
    // 逐位相加处理
    for (int i = 1; i <= lc; i++) {
        c[i] += a[i] + b[i]; // 将两数相加
        c[i + 1] = c[i] / 10; // 处理进位
        c[i] %= 10; // 保留当前位
    }
    
    // 移除前导0
    while (c[lc] == 0 && lc > 1) {
        lc--;
    }
    
    // 输出结果，从高位到低位
    for (int i = lc; i >= 1; i--) {
        cout << c[i];
    }
    cout << endl;
    
    return 0;
}
