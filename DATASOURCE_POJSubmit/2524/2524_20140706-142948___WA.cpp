#include<iostream>
#define N 50005
using namespace std;

int par[N], rank[N];
int n, m;

void init(){
    int i;
     for(i = 0; i < n; i++){
            rank[i] = 1;
            par[i] = i;
        }
}

int find(int x){
    if(par[x] = x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]){
        par[x] = y;
        rank[x] = 0;
    }
    else{
        par[y] = x;
        rank[y] = 0;
        if(rank[x] == rank[y])
            rank[x]++;
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
        for(i = 0; i < n; i++)
           sum += rank[i];
       cout <<"Case "<< a <<": "<< sum - 1 << endl; 
    }
    return 0;
}
