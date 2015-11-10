#include<iostream>
#define N 100005
using namespace std;

int par[N], rank[N], rela[N];
int n, m;

void init(int n){
    int i;
    for(i = 1; i <= n; i++){
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

/*void sol(int i, int j){
    if(find(i)== find(j) && rela[i] == rela[j])
        cout<<"In the same gang."<<endl;
    else if(find(j) == find(i) && rela[i] != rela[j])
        cout<<"In different gangs."<<endl;
    else 
        cout<<"Not sure yet."<<endl;
    return;
}
*/

int main(){
    ios_base::sync_with_stdio(false);
    int t, i, j, n, x, y;
    char ch;
    cin >> t;
    while(t--){
        cin >> n >> m;
        init(n);
        for(i = 1; i <= m; i++){
            cin >> ch;
            cin >> x >> y;
            if(ch == 'A'){
                int px = find(x), py = find(y);
                if(px == py && rela[x] == rela[y])
puts("In the same gang.");
                    //cout<<"In the same gang."<<endl;
                else if(px == py && rela[x] != rela[y])
puts("In different gangs.");
                    //cout<<"In different gangs."<<endl;
                else 
puts("Not sure yet.");
                    //cout<<"Not sure yet."<<endl;
            }

            //sol(x, y);
            else
                unit(x, y);
        }
    }
    return 0;
}
