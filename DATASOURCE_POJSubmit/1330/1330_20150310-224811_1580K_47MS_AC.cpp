#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#define mem(a , b) memset(a , b , sizeof(a))
using namespace std ;
const int MAXN = 1e4 + 5 ;
int n ;
int root ;
int u , v ;
vector<int> G[MAXN] ;
bool vis[MAXN] ;
int set[MAXN] ;
void chu() {
    int i ;
    for(i = 0 ; i <= n ; i ++)
    {
        G[i].clear() ;
        set[i] = i ;
    }
    mem(vis , 0) ;
}

int find(int x) {
    int r = x ;
    while (r != set[r]) r = set[r] ;
    int t ;
    while (x != r) {
        t = set[x] ;
        set[x] = r ;
        x = t ;
    }
    return r ;
}

void init() {
    scanf("%d" , &n) ;
    chu() ;
    int i ;
    for(i = 0 ; i < n - 1 ; i ++) {
        int a , b ;
        scanf("%d%d" , &a , &b) ;
        G[a].push_back(b) ;

        vis[b] = true ;
    }
    scanf("%d%d" , &u , &v) ;
    for(i = 1 ; i <= n ; i ++) {
        if(!vis[i]) {
            root = i ;
            break ;
        }
    }
    mem(vis , 0) ;
}

void LCA(int x) {
    vis[x] = true ;
    int i ;
    for(i = 0 ; i < G[x].size() ; i ++) {
        int y = G[x][i] ;
        if(!vis[y]) {
            if(y == u) {
                if(vis[v]) {
                    printf("%d\n" , find(v)) ;
                    return  ;
                }
            }
            else if(y == v) {
                if(vis[u]) {
                    printf("%d\n" , find(u)) ;
                    return  ;
                }
            }
            LCA(y) ;
            set[y] = x ;
        }
    }
}

void solve() {
    LCA(root) ;
}

int main() {
    int T ;
    scanf("%d" , &T) ;
    while (T --) {
        init() ;
        solve() ;
    }
    return 0 ;
}
