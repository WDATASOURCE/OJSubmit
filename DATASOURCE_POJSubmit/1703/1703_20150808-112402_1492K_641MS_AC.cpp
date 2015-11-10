#include<iostream>
#include<stdio.h> 
#define N 100005
using namespace std;
int par[N], rank[N], rela[N];
int n, m;
void init(){
    int i;
    for(i = 1; i <= N; i++){
        par[i] = i;
        rela[i] = 0;
    }
}
int find(int x){
    if(par[x] == x)
        return x;
    else{
        int temp = par[x];
        par[x] = find(par[x]);
        rela[x] = (rela[temp] + rela[x]) % 2;
      // rela[x] =(rela[temp] ^ rela[x]);
        return par[x];
    }
}
void unit(int x, int y){
   int fx = find(x);
   int fy = find(y);
    if(fx == fy) return;
    else{
        par[fy] = fx;
        rela[fy] = (rela[x] + 1 -rela[y]) % 2;
        //rela[y] = !(rela[x] ^ rela[y]);
    }
}
void sol(int x, int y){
    if(find(x)== find(y) && rela[x] == rela[y])
        printf("In the same gang.\n"); 
    else if(find(y) == find(x) && rela[x] != rela[y])
        printf("In different gangs.\n");  
    else 
        printf("Not sure yet.\n");  
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    int t, i, n, x, y;
    char ch;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d", &n, &m);
        init();
        for(i = 1; i <= m; i++){
            getchar();
            scanf("%c %d %d", &ch, &x, &y);
            if(ch == 'A')
                sol(x, y);
            else
                unit(x, y);
        }
    }
    return 0;
}