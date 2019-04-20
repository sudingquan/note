/*************************************************************************
	> File Name: e1-4-20.cpp
	> Author: sudingquan 
	> Mail: 1151015256@qq.com 
	> Created Time: 六  4/20 14:58:04 2019
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    if (!n) {
        printf("FOOLISH\n");
    } else if (n < 60) {
        printf("FAIL\n");
    } else if (n < 75) {
        printf("MEDIUM\n");
    } else if (n <= 100) {
        printf("GOOD\n");
    }
    return 0;
}
