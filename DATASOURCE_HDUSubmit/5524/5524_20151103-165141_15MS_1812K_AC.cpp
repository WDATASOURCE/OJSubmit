/*=============================================================================
# Author:            DATASOURCE
# Last modified:     2015-11-03 16:50
# Filename:         a.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
 
set <int> s;

void dfs(long long x) {
    if(x == 0 || s.count(x)) return;
    s.insert(x);
    x -= 1;
    if(x % 2 == 0) dfs(x / 2);
    else {
        dfs(x / 2 + 1);
        dfs(x / 2);
    }
}

int main() {
    long long n;
    while(cin >> n){
        s.clear();
        dfs(n);
        cout << s.size() << endl;
    }
    return 0;
}
