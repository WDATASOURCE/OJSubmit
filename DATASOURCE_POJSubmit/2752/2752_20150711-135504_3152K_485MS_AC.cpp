/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-07-11 13:09
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

char ch[400040];
int nxt[400040];
int ans[400040];

void getNext(){
    fill(nxt, nxt + 400040, 0);
    int k = nxt[0] = -1;
    int len = strlen(ch);
    for(int i = 1; i <= len; i++){
        while(k != -1 && ch[k + 1] != ch[i]) k = nxt[k];
        if(ch[k + 1] == ch[i]) k++;
        nxt[i] = k;
    }
}
 
int main(){
    while(scanf(" %s", ch) != EOF){
        int len = strlen(ch);
        getNext();
        int dx = 0;
        ans[dx++] = len;
        int i = len - 1;
        while(nxt[i] > -1){
            ans[dx++] = nxt[i] + 1;
            i = nxt[i];
        }
        for(int i = dx - 1; i >= 0; i--)
            printf("%d%c", ans[i], i == 0 ? '\n' : ' ');
    }
    return 0;
}
