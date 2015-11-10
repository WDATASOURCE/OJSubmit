#include<iostream>
#define N 50005
using namespace std;

int par[N], rank[N];
int n, m;

void init(){
    int i;
     for(i = 1; i <= n; i++){
            rank[i] = 1;
            par[i] = i;
        }
}

int find(int x){
    if(par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;
    if(rank[x] > rank[y]){
        rank[y] = 0;
        par[y] = x;
        rank[x] ++;
    }
    else if(rank[x] < rank[y]){
        par[x] = y;
        rank[x] = 0;
        rank[y] ++;
    }
    else{
        par[y] = x;
        rank[y] = 0;
        rank[x] ++;
    }
}


int main(){
    int i, j, x, y, sum, a = 0;
    while(cin >> n >>m){
        if(n == 0 && m == 0)
            break;
        a++;
        sum = 0;
        init();
        for(i = 0; i < m; i++){
            cin >> x >> y;
            unite(x, y);
        }
        for(i = 1; i <= n; i++){
            if(rank[i] != 0)
           sum += 1;
        }
       cout <<"Case "<< a <<": "<< sum << endl; 
    }
    return 0;
}
