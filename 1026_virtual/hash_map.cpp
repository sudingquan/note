/*************************************************************************
	> File Name: hash_map.cpp
	> Author: sudingquan
	> Mail: 1151015256@qq.com
	> Created Time: 六 10/26 16:23:02 2019
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

class HashFunc {
public:
    virtual int operator()(const void *str) = 0;
    virtual ~HashFunc() {}
};

class HashMap {
public:
    HashMap(HashFunc &hf) : _hf(hf) {}
    int hash(const void *data) {
        return _hf(data);
    }
private:
    HashFunc &_hf;
};

class Hash1 : public HashFunc {
public:
    int operator()(const void *str) override {
        const char *data = (const char *)str;
        int hash_code = 0, seed = 131;
        while (*data) {
            hash_code = hash_code * seed + data[0];
            data++;
        }
        return hash_code & 0x7fffffff;
    }
};

int main() {
    Hash1 hash;
    HashMap hashmap(hash);
    char data[1000];
    cin >> data;
    cout << hashmap.hash(data) << endl;
    return 0;
}
