/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-05 13:49
# Filename: 		a.cpp
# Description: 
=============================================================================*/

#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 50050
using namespace std;

struct Tree{
    int l, r, mi, ma;
};

int a[110][110];

int main(){
    int i, j, t;
    int x, y, l;
    scanf("%d", &t);
    char ch[10];
    fill(a[0], a[110], 0);
    while(t--){
        scanf(" %s%d%d%d", ch, &x, &y, &l);
        if(strcmp(ch, "WHITE") == 0){
            for(i = x; i < x + l; i++)
                for(j = y; j < y + l; j++)
                    a[i][j] = 0;
        }
        if(strcmp(ch, "BLACK") == 0){
            for(i = x; i < x + l; i++)
                for(j = y; j < y + l; j++)
                    a[i][j] = 1;
        }
        if(strcmp(ch, "TEST") == 0){
            int ans = 0;
            for(i = x; i < x + l; i++)
                for(j = y; j < y + l; j++)
                    if(a[i][j] == 1)
                        ans++;
            printf("%d\n", ans);
        }
    }
    return 0;
}
