/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-06 20:45
# Filename: 		b.cpp
# Description: 
=============================================================================*/

#include <map>
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
#define M 100010
#define lson l, mid, lp
#define rson mid, r, rp
#define lp (rt << 1) + 1
#define rp (rt << 1) + 2
using namespace std;

struct Tree{
    int l, r;
    long long sum, lazy;
    Tree(){
        lazy = 0;
        sum = 0;
    }
};

Tree tre[M << 2];
int a[M];

void push_up(int rt){
    tre[rt].sum = tre[lp].sum + tre[rp].sum;
}

void push_down(int rt){
    if(tre[rt].lazy){
        tre[lp].lazy += tre[rt].lazy;
        tre[rp].lazy += tre[rt].lazy;
        tre[lp].sum += tre[rt].lazy * (tre[lp].r - tre[lp].l);      //注意这两句;
        tre[rp].sum += tre[rt].lazy * (tre[rp].r - tre[rp].l);
        tre[rt].lazy = 0;
    }
}

void build_tree(int l, int r, int rt){
    tre[rt].l = l, tre[rt].r = r;
    tre[rt].lazy = 0;
    if(r - l == 1){
        tre[rt].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build_tree(lson);
    build_tree(rson);
    push_up(rt);
}

void update(int l, int r, int rt, int c){
    if(tre[rt].l == l && tre[rt].r == r){
        tre[rt].lazy += c;
        tre[rt].sum += (long long)c * (tre[rt].r - tre[rt].l);      //  注意此处为c * (tre[rt].r - tre[rt].l);
        return;
    }
    if(tre[rt].l == tre[rt].r) return;                      // 想想这句该不该有;
    push_down(rt);
    int mid = tre[rt].l + tre[rt].r >> 1;
    if(mid <= l) update(l, r, rp, c);
    else if(mid >= r) update(l, r, lp, c);
    else{
        update(l, mid, lp, c);
        update(mid, r, rp, c);
    }
    push_up(rt);
}

long long query(int l, int r, int rt){
    if(tre[rt].l == l && tre[rt].r == r)
        return tre[rt].sum;
    push_down(rt);
    long long ans = 0;
    int mid = tre[rt].l + tre[rt].r >> 1;
    if(mid <= l) ans += query(l, r, rp);
    else if(mid >= r) ans += query(l, r, lp);
    else{
        ans += query(l, mid, lp);
        ans += query(mid, r, rp);
    }
    return ans;
}

int main(){
    int i, j, n, q;
    while(scanf("%d%d", &n, &q) != EOF){
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        build_tree(0, n, 0);
        while(q--){
            char ch;
            scanf(" %c", &ch);
            if(ch == 'Q'){
                int a, b;
                scanf("%d%d", &a, &b);
                long long ans = query(a - 1, b, 0);
                printf("%lld\n", ans);
            }
            else{
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                update(a - 1, b, 0, c);
            }
        }
    }
    return 0;
}
