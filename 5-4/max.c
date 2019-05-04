/*************************************************************************
	> File Name: max.c
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六  5/ 4 19:38:30 2019
 ************************************************************************/

#include <stdio.h>
#define P(a, b){ \
    printf("%s = %d    expect = %d\n", #a, a, b); \
}

//#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MAX(a, b) ({ \
    __typeof(a) temp_a = (a), temp_b = (b); \
    temp_a > temp_b ? temp_a : temp_b; \
})

int main(){
    P(MAX(2, 3), 3);
    P(5 + MAX(3, 4), 9);
    P(MAX(2, MAX(3, 4)), 4);
    P(MAX(2, 3 > 4 ? 3 : 4), 4);
    int a = 7;
    P(MAX(a++, 6), 7);
    P(a, 8);
    return 0;
}
