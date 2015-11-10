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

char ch[1000010];
int nxt[1000010];
int ans[1000010];
int n;

void getNext(){
    int k = nxt[0] = -1;
    nxt[1] = 0;
    int len = n;
    for(int i = 1; i < len; i++){
        while(k != -1 && ch[k + 1] != ch[i]) k = nxt[k];
        if(ch[k + 1] == ch[i]) k++;
        nxt[i] = k;
    }
}

int main(){
    int dx = 1;
    while(scanf("%d", &n) != EOF && n){
        scanf(" %s", ch);
        getNext();

        //for(int i = 0; i <= n; i++)
            //printf("%d ", nxt[i]);
        //printf("\n");

        printf("Test case #%d\n", dx++);
        for(int i = 1; i < n; i++){
            if(nxt[i] == -1) continue;
            //cerr <<"i + 1 = "<< i + 1 <<", i - nxt[i] = "<< i + 1 - nxt[i] << endl;
            if((i + 1) % (i - nxt[i]) == 0) printf("%d %d\n", i + 1, (i + 1) / (i - nxt[i]));
        }
        printf("\n");
    }
    return 0;
}
