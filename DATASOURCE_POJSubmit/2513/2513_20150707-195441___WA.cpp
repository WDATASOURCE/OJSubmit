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
    int p[26];

    int v, cnt;
    
    Node(){
        for(int i = 0; i < 26; i++) p[i] = 0;
        v = cnt = 0;
    }
};

char str[500010][20];
Node node[500050];
int tot;                    // 记录 node 中的编号
int dx;                     // 哈希值

void init(){
    tot = 1;
    dx = 0;
    memset(node, 0, sizeof(node));
}

void insertTree(char *ch){
    int cur = 0;
    for(int i = 0; ch[i]; i++){
        if(node[cur].p[ch[i] - 'a'] == '0') node[cur].p[ch[i] - 'a'] = tot++; 
        cur = node[cur].p[ch[i] - 'a'];
    }
    node[cur].cnt++;
    if(!node[cur].v) node[cur].v = dx++;
}

int find(char * ch){
    int cur = 0;
    for(int i = 0; ch[i]; i++)
        cur = node[cur].p[ch[i] - 'a'];
    return node[cur].cnt;
}

int main(){
    int cnt = 0;
    init();
    while(scanf(" %s", str[cnt++]) != EOF);
    int num = 0;
    for(int i = 0; i < cnt; i++)
        if(find(str[i]) & 1) num++;
    if(num > 2) printf("Impossible\n");
    else printf("Possible\n");
    return 0;
}
