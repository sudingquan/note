/*************************************************************************
	> File Name: e1-5-16.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 四  5/16 18:56:26 2019
 ************************************************************************/

#include <iostream>

using namespace std;

union IP {
    int num;
    unsigned char ip[4];
};

//小端机输出1，大端机输出0
int is_little() {
    static int a = 1;
    return ((char *)(&a))[0];
}

int main() {
    printf("%d\n", is_little());
    char ip_str[25];
    while (~scanf("%s", ip_str)) {
        int a, b, c, d;
        sscanf(ip_str, "%d.%d.%d.%d", &a, &b, &c, &d);
        IP ip;
        ip.ip[3] = a;
        ip.ip[2] = b;
        ip.ip[1] = c;
        ip.ip[0] = d;
        printf("%s = %d\n", ip_str, ip.num);
    }
    return 0;
}
