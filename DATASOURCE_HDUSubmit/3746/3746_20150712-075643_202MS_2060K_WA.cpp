/*=============================================================================
# Author:            He Shuwei
# Last modified:    2015-07-12 07:32
# Filename:            a.cpp
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

int len;
char ch[100100];
int nxt[100100];

void getNext(){
    int k = nxt[0] = -1;
    for(int i = 1; i < len; i++){
        while(k != -1 && ch[k + 1] != ch[i]) k = nxt[k];
        if(ch[k + 1] == ch[i]) k++;
        nxt[i] = k;
    }
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf(" %s", ch);
        len = strlen(ch);
        getNext();
        //for(int i = 0; i < len; i++)
            //printf("%d ", nxt[i]);
        //printf("\n");
        if(nxt[len - 1] == -1) printf("%d\n", len);
        else printf("%d\n", len - 1 - nxt[len - 1] - 1);
    }
    return 0;
}
