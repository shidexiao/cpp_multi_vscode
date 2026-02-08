#include <iostream>
// 引入头文件（对标Python的import calculator）
#include "calculator.h"
using namespace std;

int main() {
    cout << "=== C++ 多文件程序 ===" << endl;
    int x = 15, y = 5;
    cout << x << " + " << y << " = " << add(x, y) << endl;
    cout << x << " * " << y << " = " << multiply(x, y) << endl;
    return 0;
}