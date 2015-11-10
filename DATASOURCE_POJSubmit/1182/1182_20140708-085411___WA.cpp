#include<iostream>
#define N 50005
using namespace std;

int par[N], rela[N], know[N];
int n, k, d, a, b;

void init(){
    int i;
    for(i = 1; i <= n; i++){
        par[i] = i;
        rela[i] = 0;
        know[i] = 0;
    }
}

int find(int x){
    if(par[x] == x)
        return x;
    int t = par[x];
    par[x] = find(par[x]);
    if(d == 1)
        rela[x] = 0;
    else
    rela[x] = (rela[t] ^ rela[x]);
    return par[x];
}

void unit(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy)
        return;
    par[fy] = x;
    if(d == 1)
        rela[fy] = 0;
    else
    rela[fy] =!(rela[x] ^ rela[y]);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    int i, sum = 0;
    cin >> n >> k;
    for(i = 1; i <= n; i++){
        cin >> d >> a >> b;
        if(a > n || b > n){
            sum++;
            continue;
        }
        else if(know[a] == 1 && know[b] == 1){
            if(d == 1 && rela[a] ^ rela[b] == 1)
                sum++;
            if(d == 2 && rela[a] ^ rela[b] ==0)
                sum++;
            continue;
        }
        else{
            know[a] = 1;
            know[b] = 1;
            unit(a, b);
        }
    }
    cout << sum << endl;
    return 0;
}

            

        
