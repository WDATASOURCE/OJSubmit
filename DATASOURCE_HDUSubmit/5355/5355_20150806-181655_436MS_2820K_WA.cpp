/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-08-06 11:53
# Filename:         a.cpp
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

vector <int> vec[100];
long long sum[100];
 
int main(){
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < 100; i++)
            vec[i].clear();
        memset(sum, 0, sizeof(sum));
        long long su = (long long)n * (long long)(n + 1) / 2;
        su /= m;
        int f = 1;
        for(int i = n; i >= 1; i--){
            int j;
            for(j = 0; j < m; j++){
                if(sum[j] + i <= su){
                    sum[j] += i;
                    vec[j].push_back(i);
                    break;
                }
            }
            if(j == m) f = 0;
        }
        for(int i = 0; i < m; i++)
            if(sum[i] != su) f = 0;
        if(f){
            printf("YES\n");
            for(int i = 0; i < m; i++){
                printf("%d ", vec[i].size());
                int size = vec[i].size();
                for(int j = 0; j < size; j++)
                    printf("%d%c", vec[i][j], j == size - 1 ? '\n' : ' ');
            }
        }else printf("NO\n");
    }
    return 0;
}
