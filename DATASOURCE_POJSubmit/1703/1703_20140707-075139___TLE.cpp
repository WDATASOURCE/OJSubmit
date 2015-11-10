#include <iostream>
#define N 100000
using namespace std;
int par[2 * N], rank[2 * N];
int n, m;
char ch;

void nint(){
    int i;
    for(i = 1; i <= m + N; i++){
        rank[i] = 0;
        par[i] = i;
    }
}

int find(int x){
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}


void unit(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return ;
    par[y] = x;
}

void sol(int i, int j){
    if(find(i)==find(j))
        cout<<"In the same gang."<<endl;
    else if(find(i)==find(i+N) || find(j)==find(i+N))
        cout<<"In different gangs."<<endl;
    else 
        cout<<"Not sure yet."<<endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t, i, j, n, x, y;
    cin >> t;
    while(t--){
        cin >> n >> m;
        nint();
        for(i = 1; i <= m; i++){
            cin >> ch;
            cin >> x >> y;
            if(ch == 'A')
                sol(x, y);
            else{
                unit(x, y + N);
                unit(y, x + N);
            }
        }
    }
    return 0;
}
