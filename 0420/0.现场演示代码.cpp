/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  4/20 19:11:26 2019
 ************************************************************************/

#include <iostream>
#include <time.h>
using namespace std;

int main() {
    srand(time(0));
    int a,b;
    scanf("%d%d", &a, &b);
    if (a - b) {
        printf("not equal\n");
    } else {
        printf("equal\n");
    }

    if ((a++) && (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    if ((a++) || (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("%d %d\n", a, b);

    for (int i = 0; i < 10; i++) {
        i == 0 || printf(" ");
        printf("%d", i);
    }
    printf("\n");
    int cnt = 0;
    for ( int i = 0; i < 10; i++ ) {
        int val = rand()%100;
        i == 0 ||printf(" ");
        printf("%d",val);
        cnt += !(val % 2);
        //cnt += (val % 2 == 0);
        //cnt += !(val & 1);
        //val & 1 等价于 val % 2
        //val & 3 等价于 val % 4
        //val & 7 等价于 val % 8
        //val & 2^i-1 等价于 val & 2^i
    }
    return 0;
}
