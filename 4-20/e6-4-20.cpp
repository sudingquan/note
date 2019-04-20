/*************************************************************************
	> File Name: e6-4-20.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  4/20 20:44:30 2019
 ************************************************************************/

#include <iostream>

using namespace std;

int f(int k , int b , int x) {
    return k * x + b;
}

int main() {
    int k, b;
    scanf("%d%d", &k, &b);
    for (int i = 1; i <= 100; i++) {
        printf("f(%d)=%d\n", i, f(k, b, i));
    }
    return 0;
}
