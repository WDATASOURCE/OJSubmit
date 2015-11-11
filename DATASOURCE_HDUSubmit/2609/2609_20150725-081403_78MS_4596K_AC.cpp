/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-07-25 07:59
# Filename:         b.cpp
# Description: 
=============================================================================*/
 
#include <set>
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
 
int n, len;
set <string> se;
char ch[10010][110];

void MiDis(int dx){
    char ch1[110];
    strcpy(ch1, ch[dx]);
    int i = 0, j = 1, k = 0, t;
    while(i < len && j < len && k < len){
        t = ch[dx][(i + k) % len] - ch[dx][(j + k) % len];
        if(t == 0) k++;
        else{
            if(t < 0) j = j + k + 1;
            else i = i + k + 1;
            if(i == j) j++;
            k = 0;
        }
    }

    for(k = 0; k < len; k++)
        ch[dx][k] = ch1[(i + k) % len];
}

int main(){
    while(scanf("%d", &n) != EOF){
        se.clear();
        for(int i = 0; i < n; i++)
            scanf(" %s", ch[i]);

        len = strlen(ch[0]);
        for(int i = 0; i < n; i++)
            MiDis(i);

        string str;
        for(int i = 0; i < n; i++){
            str = ch[i];
            se.insert(str);
        }

        printf("%d\n", se.size());
    }
    return 0;
}
