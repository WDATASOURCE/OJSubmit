/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-05-31 15:06
# Filename:         a.cpp
# Description: 
=============================================================================*/
 
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
using namespace std;
 
#define MAXSIZE 2000100            /*  */
using namespace std;
typedef struct{
    int u, v, c;
}edge;
edge a[MAXSIZE] = {0};
int e = 0;
void addnode(edge tmp) {
    a[e++] = tmp;
}

int krus_cmp(const void *a, const void *b) {
    return ((edge *)a)->c - ((edge*)b)->c;
}

int uset[MAXSIZE] = {0};

void makeSet() {
    int i;
    for(i=0;i<MAXSIZE;i++)
        uset[i] = i;
}

int find(int x) {
    return uset[x]==x?x:(uset[x]=find(uset[x]));
}

int _n;
int kruskal() {
    qsort(a, e, sizeof(edge), krus_cmp);
    int i;
    int ans=0;
    int cnt = 0;
    int px, py;
    for(i=0; i<e; i++) {
        px = find(a[i].u);
        py = find(a[i].v);
        if(px == py)
            continue;
        cnt++;
        ans += a[i].c;
        uset[py] = px;
        if(cnt == _n-1)
            break;
    }
    return ans;
}

int map[1010][1010] = {0};

int main () {
    int t, k;int n, m;
    scanf("%d", &t);
    edge tmp;
    for(k=1; k<=t; k++) {
        makeSet();
        e = 0;
        scanf("%d%d", &n, &m);
        int i, j;
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }
        _n = (n-1)*(m-1)*2 + n + m -2;
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                tmp.u = i*m+j;
                if(j!=m-1) {
                    tmp.v = tmp.u + 1;
                    tmp.c = abs(map[i][j]- map[i][j+1]);
                    addnode(tmp);
                }
                if(i!=n-1) {
                    tmp.v = tmp.u + m;
                    tmp.c = abs(map[i][j]- map[i+1][j]);
                    addnode(tmp);
                }

            }
        }
        int ans = kruskal();
        printf("Case #%d:\n%d\n", k, ans);
    }
    return 0;
}