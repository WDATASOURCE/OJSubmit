/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-07 11:11
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
#define M 50010
#define lson l, mid, lp
#define rson mid, r, rp
#define lp (rt << 1) + 1
#define rp (rt << 1) + 2
using namespace std;

struct Tree{
    int l, r, lx, rx, mx, f;
};

Tree tre[M << 2];

void push_down(int rt){
    if(tre[rt].f != -1){
        int ll = tre[lp].r - tre[lp].l;
        int rr = tre[rp].r - tre[rp].l;
        tre[lp].f = tre[rp].f = tre[rt].f;
        tre[lp].lx = tre[lp].rx = tre[lp].mx = (tre[lp].f ? 0 : ll);
        tre[rp].lx = tre[rp].rx = tre[rp].mx = (tre[rp].f ? 0 : rr);
        tre[rt].f = -1;                                              
    }
}

void push_up(int rt){
    int mid = tre[rt].l + tre[rt].r >> 2;
    tre[rt].lx = tre[lp].lx;                            // 不同;
    tre[rt].rx = tre[rp].rx;
    if(tre[rt].lx == mid - tre[rt].l) tre[rt].lx += tre[rp].lx;
    if(tre[rt].rx == tre[rt].r - mid) tre[rt].rx += tre[lp].rx;
    tre[rt].mx = max(tre[lp].rx + tre[rp].lx, max(tre[lp].mx, tre[rp].mx));
}

/*
void push_up(int rt){
    int ll = tre[lp].r - tre[lp].l;
    int rr = tre[rp].r - tre[rp].l;
    tre[rt].lx = tre[lp].lx;
    tre[rt].rx = tre[rp].rx;
    if(tre[lp].lx == ll) tre[rt].lx += tre[rp].lx;
    if(tre[rt].rx == rr) tre[rt].rx += tre[lp].rx;
    tre[rt].mx = max(max(tre[lp].mx, tre[rp].mx), tre[lp].rx + tre[rp].lx);
}
*/

void build_tree(int l, int r, int rt){
    tre[rt].l = l, tre[rt].r = r, tre[rt].f = -1;
    tre[rt].lx = tre[rt].rx = tre[rt].mx = r - l;
    if(r - l == 1)
        return;
    int mid = l + r >> 1;
    build_tree(lson);
    build_tree(rson);
    //push_up(rt);                    //  想想这句要加吗;
}

void update(int l, int r, int rt, int c){
    if(tre[rt].l == l && tre[rt].r == r){
        tre[rt].f = c;
        tre[rt].lx = tre[rt].rx = tre[rt].mx = (c ? 0 : r - l);
        return;
    }
    push_down(rt);
    int mid = tre[rt].l + tre[rt].r >> 1;
    if(mid <= l) update(l, r, rp, c);
    else if(mid >= r) update(l, r, lp, c);
    else{
        update(lson, c);
        update(rson, c);
    }
    push_up(rt);
}

int query(int l, int r, int rt, int x){
    if(r - l == 1)
        return l;                                   // 此处是 l  还是 tre[rt].l
    push_down(rt);
    int mid = l + r >> 1;
    if(tre[lp].mx >= x) return query(lson, x);
    else if(tre[lp].rx + tre[rp].lx >= x)
        return mid - tre[lp].rx;                    // 要不要 +1
    else return query(rson, x);
}

/*
int query(int l, int r, int rt, int x){
    if(tre[rt].l == tre[rt].r)
        return tre[rt].l;
    push_down(rt);
    int mid = tre[rt].l + tre[rt].r >> 1;
    if(tre[lp].mx >= x)
        return query(l, r, lp, x);
    else if(tre[lp].rx + tre[rp].lx >= x)
        return mid - tre[lp].rx;
    return query(l, r, rp, x);
}
*/

int main(){
    int n, m, a, b, c, x;
    while(scanf("%d%d", &n, &m) != EOF){
        build_tree(0, n, 0);
        while(m--){
            scanf("%d", &c);
            if(c == 1){
                scanf("%d", &x);
                if(tre[0].mx < x){  
                     printf("0\n");  
                     continue;  
                 }  
                int ans = query(0, n, 0, x);
                printf("%d\n", ans + 1);
                update(ans, ans + x, 0, c);
            }
            else{
                scanf("%d%d", &a, &b);
                update(a - 1, a + b, 0, 0);
            }
        }
    }
    return 0;
}
