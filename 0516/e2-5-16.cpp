/*************************************************************************
	> File Name: e2-5-16.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 四  5/16 19:15:37 2019
 ************************************************************************/

#include <iostream>

using namespace std;

int is_little() {
    static int a = 1;
    return ((char *)(&a))[0];
}
