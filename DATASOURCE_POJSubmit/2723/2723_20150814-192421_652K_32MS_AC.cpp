#include<stdio.h>
#include<string.h>
 #define MM 6200
 #define NN 4200
typedef struct node{
    int v;
    struct node *nxt;
}NODE;
NODE edg[MM];
NODE *link[NN];

 int f[NN][2];
 int g[NN][2];
 int N, M;
 int idx; // 边的总数 
int scc; // 强连通分支个数 
int top; // 栈顶
int time; // 时间戳，每个节点的访问次序编号 

int cnt[NN]; // 标记强连通分支i中节点数
int dfn[NN]; // 标记结点i的时间戳（访问次序号）
int low[NN]; //  记录结点u或u的子树中所有节点的最小标号 
int stack[NN];
int inSta[NN]; // 标记结点是否在栈中
int out[NN]; // 标记分支i是否有出度
int root[NN]; // 标记结点i属于哪个分支 

int Min(int a, int b){
    return a < b ? a : b;
}

void Add(int u, int v){// 加边 
    edg[idx].v = v;
    edg[idx].nxt = link[u];
    link[u] = edg + idx++;
}

void Tarjan(int u){
    int v;
    dfn[u] = low[u] = ++time;
    stack[++top] = u;
    inSta[u] = 1;
    for (NODE *p = link[u]; p; p = p->nxt){
        v = p->v;
        if (dfn[v] == 0){// 未访问 
            Tarjan(v);
            low[u] = Min(low[u], low[v]); 
        }else if (inSta[v]){
            low[u] = Min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]){
        scc++;
        do{
            v = stack[top--];
            inSta[v] = 0;
            root[v] = scc;
            cnt[scc]++;
        }while(v != u);
    }
}

void Init(){
    memset(dfn, 0, sizeof(dfn));
    memset(cnt, 0, sizeof(cnt));
    memset(inSta, 0, sizeof(inSta));
    time = scc = top = 0;
}
int Solve(){
    int i;
    Init();
    for (i = 0; i < N * 2; i++){
        if (!dfn[i]){
            Tarjan(i);
        }
    }
    for (i = 0; i < N; i++){
        if (root[i] == root[i + N]) return 0;
    }
    return 1;
}

void Build(int mid){
    int i;
    idx = 0;
    memset(link, 0, sizeof(link));
    for (i = 0; i < N / 2; i++){
        Add(g[i][0], g[i][1] + N);
        Add(g[i][1], g[i][0] + N);
    }
    for (i = 0; i < mid; i++){
        Add(f[i][0] + N, f[i][1]);
        Add(f[i][1] + N, f[i][0]);
    }    
}
int Binary(){
    int low = 0;
    int hig = M;
    int mid, ans = 0;
    while(low <= hig){
        mid = (low + hig) >> 1;
        Build(mid);
        if (Solve()){
            ans = mid;
            low = mid + 1;
        }else hig = mid - 1;
    }
    return ans;
}
int main()
{
    int i;
    while(scanf("%d%d", &N, &M) != EOF){
        if (N == 0 && M == 0) break;

        for(i = 0; i < N; i++){
            scanf("%d%d", &g[i][0], &g[i][1]);           
        }
        
        for(i = 0; i < M; i++){
            scanf("%d%d", &f[i][0], &f[i][1]);
        }
        N *= 2;
        printf("%d\n", Binary());
    }
    return 0;
}
