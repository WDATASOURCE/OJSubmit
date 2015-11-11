/*=============================================================================
# Author:            He Shuwei
# Last modified:    2015-05-25 11:32
# Filename:            a.cpp
# Description:      
=============================================================================*/
 
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

struct Edge{
    int a, b, c;

    friend bool operator < (const Edge &a, const Edge &b){
        return a.b < b.b;
    }
};

Edge edge[100010];

int main(){
    int t;
    scanf("%d", &t);
    for(int di = 1; di <= t; di++){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].c);
        sort(edge, edge + n);
        int f = 1;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += edge[i].a;
            if(sum > edge[i].b){
                f = 0;
                break;
            }
            sum += edge[i].c;
        }
        if(f) printf("Case #%d: YES\n", di);
        else printf("Case #%d: NO\n", di);
    }
    return 0;
}
