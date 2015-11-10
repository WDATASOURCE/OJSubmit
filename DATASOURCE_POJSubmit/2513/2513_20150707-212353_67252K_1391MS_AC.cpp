/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-07-07 15:20
# Filename: 		c.cpp
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

struct Node{
    short p[26];
    bool vis;
    int v, cnt;
    Node(){
        for(int i = 0; i < 26; i++) p[i] = 0;
        v = cnt = 0;
        vis = 0;
    }
};

int par[500050];
int dig[500050];
Node node[1000050];
int tot;                    // 记录 node 中的编号
int dx;                     // 哈希值

void init(){
    tot = 1;
    dx = 1;
    memset(node, 0, sizeof(node));
    for(int i = 0; i < 500050; i++)
        par[i] = i, dig[i] = 0;
}

int Find(int x){
    if(par[x] != x) par[x] = Find(par[x]);
    return par[x];
}

void Union(int x, int y){
    int fx = Find(x);
    int fy = Find(y);
    if(fx == fy) return;
    par[fx] = par[fy];
}

int insertTree(char *ch){
    int cur = 0;
    for(int i = 0; ch[i]; i++){
        if(node[cur].p[ch[i] - 'a'] == 0) node[cur].p[ch[i] - 'a'] = tot++; 
        cur = node[cur].p[ch[i] - 'a'];
    }
    node[cur].cnt++;
    if(!node[cur].v) node[cur].v = dx++;
    return node[cur].v;
}

int main(){
    init();
    char ch1[20], ch2[20];
    while(scanf(" %s %s", ch1, ch2) != EOF){
        int p1 = insertTree(ch1);
        int p2 = insertTree(ch2);
        //cerr <<"p1 = "<< p1 <<", p2 = "<< p2 << endl;
        Union(p1, p2);
        dig[p1]++;
        dig[p2]++;
    }
    int tt = Find(1);
    //cerr <<"tt = "<< tt << endl;
    int f = 1;
    int num = 0;
    //cerr <<"dx = "<< dx << endl;
    for(int i = 1; i < dx; i++)
        if(dig[i] & 1) num++;
    for(int i = 2; i < dx; i++)
        if(Find(i) != tt){
            f = 0;
            //cerr <<"i = "<< i <<", par[i] = "<< par[i] << endl;
            break;
        }
    if(f && num <= 2) printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}
