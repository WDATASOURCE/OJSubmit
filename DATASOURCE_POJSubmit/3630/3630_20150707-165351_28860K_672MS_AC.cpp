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
    Node * net[10];
    int cnt;
    bool isEnd;

    Node(){
        for(int i = 0; i < 10; i++) net[i] = NULL;
        cnt = 0;
        isEnd = false;
    }
};

Node * root;
Node node[600010];
int tot = 0;

bool insertTree(char *ch){
    Node * cur  = root;
    int num;
    for(int i = 0; ch[i]; i++){
        num = ch[i] - '0';
        if(cur -> net[num] == NULL) cur -> net[num] = &node[tot++];
        else{
            cur -> net[num] -> cnt++;
            if(cur -> net[num] -> isEnd) return false;
        }
        cur = cur -> net[num];
    }
    cur -> isEnd = true;
    if(cur -> cnt) return false;
    return true;
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        tot = 0;
        memset(node, 0, sizeof(node));
        root = &node[tot++];
        int n;
        scanf("%d", &n);
        int flag = 1;
        char ch[20];
        for(int i = 0; i < n; i++){
            scanf(" %s", ch);
            if(flag) flag = insertTree(ch);
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
