/*************************************************************************
	> File Name: EP28.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  5/19 20:31:13 2019
 ************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int sum = 1;
    //推导出通项公式
    for (int l = 3; l <= 1001; l += 2) {
        sum += 4 * l * l - 6 * l + 6;
    }
    printf("%d\n", sum);
}
