#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define M 210
using namespace std;

vector <int> vec[M];
int degree[M];
int ans[M];
bool is[M][M];
int n, m;

struct cmp {
    bool operator ()(int x, int y) {
        return x > y;
    }
};

bool tosort(){
    int i, count = 0;
    //priority_queue<int, vector<int>, cmp> sta;
    priority_queue<int> sta;
    for(i = 1; i <= n; i++){
        if(degree[i] == 0)
            sta.push(i);
    }
    while(!sta.empty()){
        int t = sta.top();
        sta.pop();
        ans[count++] = t;
        int end = vec[t].size();
        for(i = 0; i < end; i++){
            int k = vec[t][i];
            degree[k]--;
            if(degree[k] == 0)
                sta.push(k);
        }
    }
    if(count < n)
        return false;                           // 出现环;
    else
        return true;                           // nn 个元素正常拓扑排序;
}

int main(){
    int i, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        int f = 1;
        int aa, bb;
        for(i = 0; i < M; i++){
            vec[i].clear();
            degree[i] = 0;
        }
        fill(is[0], is[M], false);
        while(m--){
            scanf("%d%d", &aa, &bb);
            if(is[aa][bb])
                continue;
            else if(aa == bb)
                f = 0;
            else{
                is[aa][bb] = true;
                vec[bb].push_back(aa);
                degree[aa]++;
            }
        }
        bool ch = tosort();
        int a[M];
        if(ch && f){
            for(int i = n; i >= 1; i--)
                a[ans[i - 1]] = n - i + 1;
            for(int i = 1; i <= n; i++)
                printf("%d%c", a[i], i == n ? '\n' : ' ');
        }
        else printf("-1\n");
    }
    return 0;
}
