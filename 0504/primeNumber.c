/*************************************************************************
	> File Name: primeNumber.c
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六  5/ 4 14:33:46 2019
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10000

int prime[MAX_N + 5] = {0};

int main() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
    }
    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n",  prime[n]);
    }
    return 0;
}
