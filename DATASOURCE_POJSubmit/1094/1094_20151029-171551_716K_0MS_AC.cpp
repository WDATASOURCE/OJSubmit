#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 30;
const int MAXM = 1010;

struct Edge{
    int v, nxt;
};

bool vis[MAXN];
Edge edge[MAXM];
int n, m, ecnt, num;
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
    queue <int> que;
    memset(deg, 0, sizeof(deg));
    for(int u = 0; u < 26; u++)
        for(int i = head[u]; i + 1; i = edge[i].nxt)
            deg[edge[i].v]++;

    for(int i = 0; i < 26; i++)
        if(!deg[i] && vis[i]) que.push(i);

    int cnt = 0;
    bool flag = false;
    while(!que.empty()){
        if(que.size() > 1) flag = true;
        int top = que.front();
        que.pop();
        res[cnt++] = top;
        for(int i = head[top]; i + 1; i = edge[i].nxt){
            if(deg[edge[i].v] && vis[edge[i].v]){
                deg[edge[i].v]--;
                if(deg[edge[i].v] == 0 && vis[edge[i].v]) que.push(edge[i].v);
            }
        }
    }
    if(cnt != num) return -1;
    else if(flag) return 0;
    else return cnt;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        if(!(n + m)) break;
        init();
        char a, b;
        int ans = 0, dx = 0;
        for(int i = 1; i <= m; i++){
            scanf(" %c<%c", &a, &b);
            if(!vis[a - 'A']) vis[a - 'A'] = true, num++; 
            if(!vis[b - 'A']) vis[b - 'A'] = true, num++; 
            addEdge(a - 'A', b - 'A');
            if(ans == 0){
                int tmp = toSort();
                if(tmp == -1) ans = tmp, dx = i;
                else if(tmp == n && ans == 0) ans = tmp, dx = i;
            }
        }
        if(ans == -1) printf("Inconsistency found after %d relations.\n", dx);
        else if(ans){
            printf("Sorted sequence determined after %d relations: ", dx);
            for(int i = 0; i < n; i++)
                printf("%c", res[i] + 'A');
            printf(".\n");
        }
        else printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
