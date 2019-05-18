/*************************************************************************
	> File Name: e3-4-20.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  4/20 15:56:31 2019
 ************************************************************************/

#include<iostream>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) && n){
        switch (n) {
            case 1:
                printf("one ");
            case 2:
                printf("two ");
            case 3:
                printf("three\n");
                break;
            default:
                printf("error\n");
                break;
        }
    }
    return 0;
}
