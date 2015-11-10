/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-10-15 21:37
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

struct stdu{
    char ch[10];
    int a;
};

stdu a[10010];
bool cmp(stdu a, stdu b){
    return a.a > b.a;
}

int main(){
    int n, m;
    char ch[100];
    while(scanf("%d", &n) != EOF){
        getchar();
        for(int i = 0; i < n; i++)
            gets(ch);
        scanf("%d", &m);
        while(m--){
            for(int i = 0; i < n; i++){
                scanf("%d", &a[i].a);
                getchar();
                gets(a[i].ch);
            }
            sort(a, a + n, cmp);
            for(int i = 0; i < n; i++)
                if(strcmp(a[i].ch, "Li Ming") == 0){
                    printf("%d\n", i + 1);
                    break;
                }
        }
    }
    return 0;
}
