/*=============================================================================
# Author:			He Shuwei
# Last modified:	2015-07-10 14:45
# Filename:			a.cpp
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

int nxt[10010];
char ch[10010];
char str[1000100];

void getNext(){
    int k = 0;
    fill(nxt, nxt + 10010, 0);
    nxt[1] = 0;
    nxt[0] = -1;
    int len = strlen(ch + 1);
    for(int i = 2; i <= len; i++){
        while(k > 0 && ch[k + 1] != ch[i]) k = nxt[k];
        if(ch[k + 1] == ch[i]) k++;
        nxt[i] = k;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ch[0] = str[0] = '#';
        scanf(" %s %s", ch + 1, str + 1);
        int len1 = strlen(ch + 1);
        int len2 = strlen(str + 1);
        getNext();
        int ans = 0;
        int i = 1, j = 1;
        while(i <= len2){
            if(j < 1 || ch[j] == str[i]) i++, j++;
            else j = nxt[j];
            //cerr<<"i = "<< i <<", j = "<< j << endl;
            if(j == len1 + 1){
                ans++;
                //cerr <<"j = "<< j <<", nxt[j - 1] = "<< nxt[j - 1] << endl;
                j = nxt[j - 1] + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
