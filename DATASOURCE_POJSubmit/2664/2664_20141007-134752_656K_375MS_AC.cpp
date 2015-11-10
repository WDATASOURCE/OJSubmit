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
#define lson l, mid, lp
#define rson mid, r, rp
#define lp (node << 1) + 1
#define rp (node << 1) + 2
using namespace std;

char ch[110][10];
char s[10];

int main(){
    int k, m, c, r;
    while(scanf("%d", &k) != EOF && k){
        scanf("%d", &m);
        getchar();
        for(int i = 0; i < k; i++)
            scanf("%s", ch[i]);
        int f = 1;
        while(m--){
            scanf("%d%d", &c, &r);
            getchar();
            int v = 0;
            for(int i = 0; i < c; i++){
                scanf("%s", s);
                for(int j = 0; j < k; j++)
                    if(strcmp(ch[j], s) == 0)
                        v++;
            }
            if(v < r)
                f = 0;
        }
        if(f)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
