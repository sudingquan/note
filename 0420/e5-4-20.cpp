/*************************************************************************
	> File Name: e5-4-20.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  4/20 16:59:14 2019
 ************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int  n;
    int  digit = 0;
    scanf("%d", &n);
    do {
        n /= 10;
        digit++;
    } while (n);
    printf("%d\n", digit);
    return 0;
}
