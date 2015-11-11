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
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int MAXN = 100100;
const int MAXE = 200100;
const int MOD = 1000000007;

vector <int> tree[MAXN];
vector <int> edge[MAXN];
vector <int> leaf[MAXN];
vector <int> subt[MAXN];
bool vis[MAXN];
int n;

void init(){
    for(int i = 0; i < MAXN; i++){
        tree[i].clear();
        edge[i].clear();
        leaf[i].clear();
        subt[i].clear();
    }
    memset(vis, 0, sizeof(vis));
}

void cal(){
    for(int i = 1; i <= n; i++){
        int size = edge[i].size();
        for(int j = 0; j < size; j++){
            int v = edge[i][j];
            if(edge[v].size() == 0) leaf[i].push_back(v);
            else subt[i].push_back(v);
        }
    }
}

void make_tree(int u){
    vis[u] = true;
    int size = tree[u].size();
    for(int i = 0; i < size; i++){
        if(!vis[tree[u][i]]){
            edge[u].push_back(tree[u][i]);
            make_tree(tree[u][i]);
        }
    }
}

long long fat(int n)
{
    long long res = 1;
    int i;
    for(i=1; i<=n; i++)
    {
        res = ((long long)res * (long long )i) % MOD;
    }
    return res;
}

long long dfs(int u){
    /*for(int i = 0; i < size; i++){
        int v = edge[u][i];
        int a = leaf[v].size();
        int b = subt[v].size();
    }*/
    int b = leaf[u].size();
    int a = subt[u].size();
//    printf ( "getab of : [%d], a: %d, b: %d\n", u, a, b );
    if(a == 0)
    {
        return 2*fat(b) % MOD;
    }
    else if(a == 1)
    {
        long long res = 2;
        res = (res * fat(b)) % MOD;
        for(int i=0; i<a; i++)
        {
            res = (res * dfs(subt[u][i])) % MOD;
        }
        return res;
    }
    else if(a == 2)
    {
        long long res = 1;
        res = (res*fat(b)) % MOD;
        for(int i=0; i<a; i++)
        {
            res = (res*dfs(subt[u][i])) % MOD;
        }
        return res;
    }
    else
    {
        //printf ( "fuck!\n" );
        return 0;
    }
}

int main(){
     int T;
    scanf("%d", &T);
    for(int dx = 1; dx <= T; dx++){
        init();
        scanf("%d", &n);
        int u, v;
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        make_tree(1);
        cal();


        /*
        for(int i = 1; i <= n; i++){
            int size1 = leaf[i].size();
            int size2 = subt[i].size();

            cerr <<"i = "<< i <<": "<< endl;
            for(int j = 0; j < size1; j++)
                cerr <<"j = "<< j <<", leaf[i][j] = "<< leaf[i][j] << endl;
            cerr << endl;

            cerr <<"i = "<< i <<": "<< endl;;
            for(int j = 0; j < size2; j++)
                cerr <<"j = "<< j <<", subt[i][j] = "<< subt[i][j] << endl;
            cerr << endl;
        }
        */
        if(n != 1)
            printf ( "Case #%d: %I64d\n", dx, dfs(1));
        else
            printf("Case #%d: %d\n", dx, 1);


    }
    return 0;
}