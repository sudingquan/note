/*************************************************************************
	> File Name: 1.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 四 10/10 20:12:33 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

class Point {
public:
    //初始化列表只规定如何初始化，而初始化顺序根据变量声明顺序来进行
    Point();
    Point(int x, int y);
    Point(const Point &p);
    static int cnt() { return Point::_cnt; }
    int x() { return _x; }
    int y() { return _y; }
private:
    int _x, _y;
    static int _cnt;
};

Point::Point() : _x(0), _y(0) {
    cout << "constructor" << endl;
}

Point::Point(int x, int y) : _x(x), _y(y) {
    cout << "constructor with  parameters" << endl;
}

Point::Point(const Point &p) {
    _x = p._x;
    _y = p._y;
    cout << "copy constructor" << endl;
}

int main() {
    Point p1, p2(2, 3), p3(p2);
    cout << p1.x() << " " << p1.y() << endl;
    cout << p2.x() << " " << p2.y() << endl;
    cout << p3.x() << " " << p3.y() << endl;
    cout << Point::cnt() << endl;
    return 0;
}
