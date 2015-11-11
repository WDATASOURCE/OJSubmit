/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-11 18:21
# Filename:         b.cpp
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

char ch[100050];
int nxt[100050];
int len;

void getNext(){
    int k = nxt[0] = -1;
    nxt[1] = 0;
    for(int i = 1; i < len; i++){
        while(k != -1 && ch[k + 1] != ch[i]) k = nxt[k];
        if(ch[k + 1] == ch[i]) k++;
        nxt[i] = k;
    }
}

 
int main(){
 
    while(scanf("%s", ch) != EOF){
        scanf("%s", ch + strlen(ch));
        len = strlen(ch);
        getNext();
        int ans = nxt[len - 1] + 1;
        if(!ans) printf("%d\n", ans);
        else{
            ch[ans] = '\0';
            printf("%s %d\n", ch, ans);
        }
    }
    return 0;
}
