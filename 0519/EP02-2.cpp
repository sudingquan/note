/*************************************************************************
	> File Name: EP02-2.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 日  5/19 18:14:27 2019
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_M 4000000

int main() {
    long long sum = 0;
    int a = 0, b = 1;
    while (a + b < MAX_M) {
        b = a + b;
        a = b - a;
        if (!(b & 1)) sum += b;
    }
    printf("%lld\n", sum);
    return 0;
}
