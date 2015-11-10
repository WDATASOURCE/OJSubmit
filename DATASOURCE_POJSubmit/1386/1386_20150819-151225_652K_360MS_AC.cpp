/*=============================================================================
# Author:           He Shuwei
# Last modified: 	2015-08-19 11:56
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int t, n;
int In[30];
int Out[30];
int par[30];
bool use[30];
char temp[1010];

void init(){
    for(int i = 0; i < 30; i ++){
        par[i] = i;
        use[i] = false;
        In[i] = Out[i] = 0;
    }
}

int find(int x){
    if(par[x] != x) par[x] = find(par[x]);
    return par[x];
}

void Union(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) return;
    par[fy] = fx;
}

bool solve(){
    int cut = 0;
    for(int i = 0; i < 26; i++)
        if(use[i] && par[i] == i) cut++;

    if(cut > 1) return false;

    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < 26; i++){
        if(use[i] && In[i] != Out[i]){
            if(In[i] == Out[i] + 1) sum1++;
            else if(Out[i] == In[i] + 1) sum2++;
            else return false;
        }
    }

    if((!sum1 && !sum2) || (sum1 == 1 && sum2 == 1)) return true;
    else return false;
}

int main(){
    scanf("%d", &t);
    while(t--){
        init();
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%s", temp);
            int len = strlen(temp);
            int u = temp[0] - 'a';
            int v = temp[len - 1] - 'a';
            Out[u]++;
            In[v]++;
            use[u] = use[v] = true;
            Union(u, v);
        }

        bool ans = solve();

        if(ans) printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    return 0;
}
