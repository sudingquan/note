/*************************************************************************
	> File Name: e.cpp
	> Author: sudingquan 
	> Mail: 1151015256@qq.com 
	> Created Time: 二  4/16 20:03:16 2019
 ************************************************************************/

#include <iostream>
using namespace std;
int main(){
    int n;
    scanf("%d" , &n);
    FILE *fout = fopen("/dev/null" , "w");
    printf("%d\n" , fprintf(fout , "%d" , n));
    return 0;
}
