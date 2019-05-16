/*************************************************************************
	> File Name: main.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 四  5/16 21:01:20 2019
 ************************************************************************/

#include <iostream>

using namespace std;



int main() {
    int num = 0x61626364;
    char *p = (char *)(&num);
    printf("%s\n", p);
    return 0;
}
