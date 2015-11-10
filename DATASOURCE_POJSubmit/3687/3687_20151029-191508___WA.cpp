#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 300;
const int MAXM = 40010;

struct Edge{
    int v, nxt;
};

bool vis[MAXN];
Edge edge[MAXM];
int n, m, ecnt, num;
int ans[MAXN], tmp[MAXN];
int head[MAXN], deg[MAXN], res[MAXN];

void init(){
    num = ecnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(res, 0, sizeof(res));
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v){
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt++;
}

/*
 * return 0: 拓扑序不唯一
 * return cnt: 拓扑序唯一且排序完毕
 * return -1: 矛盾
 */
int toSort(){
    priority_queue <int, vector<int>, greater<int> > que;
    memset(deg, 0, sizeof(deg));
    for(int u = 1; u <= n; u++)
        for(int i = head[u]; i + 1; i = edge[i].nxt)
            deg[edge[i].v]++;

    for(int i = 1; i <= n; i++)
        if(!deg[i] && vis[i]) que.push(i);

    int cnt = 0;
    while(!que.empty()){
        int top = que.top();
        que.pop();
        res[cnt++] = top;
        for(int i = head[top]; i + 1; i = edge[i].nxt){
            if(deg[edge[i].v] && vis[edge[i].v]){
                deg[edge[i].v]--;
                if(deg[edge[i].v] == 0 && vis[edge[i].v]) que.push(edge[i].v);
            }
        }
    }
    if(cnt == num) return cnt;
    return -1;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        init();
        int a, b;
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &a, &b);
            if(!vis[a]) vis[a] = true, num++;
            if(!vis[b]) vis[b] = true, num++;
            addEdge(a, b);
        }

        int choice = toSort();
        if(choice == -1) printf("%d\n", -1);
        else{
            int res_cnt = num, tmp_cnt = 0;
            for(int i = 1; i <= n; i++)
                if(!vis[i]) tmp[tmp_cnt++] = i;

            int i = 0, j = 0;
            int cnt = 0;

            while(i < res_cnt && j < tmp_cnt){
                if(res[i] < tmp[j]) ans[cnt++] = res[i++];
                else ans[cnt++] = tmp[j++];
            }

            while(i < res_cnt) ans[cnt++] = res[i++];
            while(j < tmp_cnt) ans[cnt++] = tmp[j++];

            for(int i = 0; i < n; i++)
                printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
