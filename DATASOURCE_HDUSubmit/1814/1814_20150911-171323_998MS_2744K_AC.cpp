#include <cstdio>
#include <cstring>
#include <vector>
using std::vector;
#define R 1
#define B 2
#define W 0
const int maxn = 16005;
int col[maxn];
int cnt, ans[maxn];
vector<int> G[maxn];
int n, m;
bool read(){
    if(scanf("%d%d", &n, &m)==EOF)
        return false;
    n = n<<1;
    for(int i = 0; i < n; i ++)
        G[i].clear();
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        G[a].push_back(b ^ 1);
        G[b].push_back(a ^ 1);
    }
    return true;
}

bool dfs(int v){
    int size = G[v].size();
    if(col[v] == B) return false;
    if(col[v] == R) return true;
    col[v] = R;
    col[v^1] = B;
    ans[cnt ++] = v;
    for(int i = 0; i != size ; i ++){
        int u = G[v][i];
        if(!dfs(u)) return false;
    }
    return true;
}

bool solve(){
    memset(col, 0, sizeof(col));
    for(int i = 0; i < n; i ++){
        if(col[i]) continue;
        cnt = 0;
        if(!dfs(i)){
            for(int j = 0; j < cnt; j ++){
                col[ans[j]] = W;
                col[ans[j]^1] = W;
            }
            if(!dfs(i^1)) return false;
        }
    }
    return true;
}

int main(){
    while(read()){
        if(solve()){
            for(int i = 0; i < n; i ++)
                if(col[i]==R) printf("%d\n", i+1);
        }
        else printf("NIE\n");
    }
    return 0;
}
