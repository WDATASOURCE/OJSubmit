/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-11 13:09
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

char ch[200020];
int nxt[200020];
int n;

void getNext(){
    int k = nxt[0] = -1;
    for(int i = 1; i < n; i++){
        while(k != -1 && ch[k + 1] != ch[i]) k = nxt[k];
        if(ch[k + 1] == ch[i]) k++;
        nxt[i] = k;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %s", &n, ch);
        getNext();
        long long ans = n;
        for(int i = 0; i < n; i++)
            if(nxt[i] > -1) ans++;
        printf("%I64d\n", ans % 10007);
    }
    return 0;
}
