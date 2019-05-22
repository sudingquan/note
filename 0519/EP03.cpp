/*************************************************************************
	> File Name: EP03.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  5/19 19:04:59 2019
 ************************************************************************/

#include <iostream>
using namespace std;
#define N 600851475143LL

int main() {
    long long num = N, ans, i = 2;
    while (i * i <= num) {
        if (num % i == 0) ans = i; // ans 记录最大的素因子
        while (num % i == 0) num /= i;
        i++;
    }
    if (num != 1) ans = num; // num 为什么一定是素数
    printf("%lld\n", ans);
    return 0;
}
