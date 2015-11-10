/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-05 13:49
# Filename: 		a.cpp
# Description: 
=============================================================================*/

#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, node * 2 + 1
#define rson mid, r, node * 2 + 2
#define M 50010
using namespace std;

struct Tree{
    int l, r, mi, ma;
};

Tree tre[M * 4];
int cow[M], mi, ma;

void build_tree(int l, int r, int node){
    tre[node].l = l, tre[node].r = r;
    if(r - l == 1){
        tre[node].mi = tre[node].ma = cow[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(lson);
    build_tree(rson);
    tre[node].mi = min(tre[node * 2 + 1].mi, tre[node * 2 + 2].mi);
    tre[node].ma = max(tre[node * 2 + 1].ma, tre[node * 2 + 2].ma);
}

void query(int l, int r, int node){
    if(tre[node].l == l && tre[node].r == r){
        mi = min(mi, tre[node].mi);
        ma = max(ma, tre[node].ma);
        return;
    }
    int mid = (tre[node].l + tre[node].r) / 2;
    if(mid <= l) query(l, r, node * 2 + 2);
    else if(mid >= r) query(l, r, node * 2 + 1);
    else{
        query(l, mid, node * 2 + 1);
        query(mid, r, node * 2 + 2);
    }
}

int main(){
    int n, m, i;
    int a, b;
    while(scanf("%d%d", &n, &m) != EOF){
        for(i = 0; i < M * 4; i++)
            tre[i].l = tre[i].r = tre[i].mi = tre[i].ma = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &cow[i]);
        build_tree(0, n, 0);
        for(i = 0; i < m; i++){
            scanf("%d%d", &a, &b);
            mi = (1 << 30), ma = 0;
            query(a - 1, b, 0);
            printf("%d\n", ma - mi);
        }
    }
    return 0;
}
