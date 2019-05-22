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
    int f[3] = {0, 1};
    int n = 1;
    while (f[n % 3] + f[(n - 1) % 3] < MAX_M) {
        n += 1;
        f[n % 3] = f[(n - 1) % 3] + f[(n - 2) % 3];
        if (!(f[n % 3] & 1)) sum += f[n % 3];
    }
    printf("%lld\n", sum);
    return 0;
}
