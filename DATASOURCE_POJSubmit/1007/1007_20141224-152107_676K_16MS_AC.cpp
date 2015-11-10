/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-23 22:59
# Filename: 		a.cpp
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
#define N 200
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

char ch[N][N];
int a[N];
 
int main(){
	int n, m;
	while(~scanf("%d%d",&m, &n)){
        for(int i = 0; i < n; i++)
            scanf("%s", ch[i]);
        fill(a, a + n, 0);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = j + 1; k < m; k++)
                    if(ch[i][j] > ch[i][k]) a[i]++;
        char tt[N];
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(a[i] > a[j]){
                    strcpy(tt, ch[i]);
                    strcpy(ch[i], ch[j]);
                    strcpy(ch[j], tt);
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
        for(int i = 0; i < n; i++) printf("%s\n", ch[i]);
	}
	return 0;
}
