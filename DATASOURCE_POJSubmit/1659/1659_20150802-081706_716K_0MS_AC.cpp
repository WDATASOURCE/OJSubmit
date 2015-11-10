/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-02 08:07
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

struct Point{
    int index, val;

    friend bool operator < (const Point &a, const Point &b){
        return a.val > b.val;
    }
};


Point point[100];
int mp[100][100];
 
int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(mp, 0, sizeof(mp));
        for(int i = 0; i < n; i++){
            scanf("%d", &point[i].val);
            point[i].index = i + 1;
        }

        int flag = 1;
        while(1){
            sort(point, point + n);
            int cnt = point[0].val;
            point[0].val = 0;
            if(cnt == 0) break;
            for(int i = 1; i <= cnt; i++){
                point[i].val--;
                mp[point[0].index][point[i].index] = mp[point[i].index][point[0].index] = 1;
                if(point[i].val < 0){
                    flag = 0;
                    goto A;
                }
            }
        }

A:

        if(flag){
            printf("YES\n");
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    printf("%d%c", mp[i][j], j == n ? '\n' : ' ');
        }else printf("NO\n");
        printf("\n");
    }
    return 0;
}
