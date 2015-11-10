#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define M 210
using namespace std;

vector <int> vec[M];
int degree[M];
int ans[M];
bool is[M];
int n, m, nn;

int tosort(){
    int i, j;
    int count = 0;
    fill(degree, degree + M, 0);
    stack <int> sta;
    for(i = 1; i <= n; i++){
        int end = vec[i].size();
        for(j = 0; j < end; j++)
            degree[vec[i][j]]++;
        //cerr << 1 << endl;
    }
    for(i = 1; i <= n; i++){
        if(degree[i] == 0 && is[i])
            sta.push(i);
        //cerr << 2 << endl;
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
            //cerr << 3 << endl;
        }
    }
    if(count < nn)
        return 1;                           // 出现环;
    else
        return 3;                           // nn 个元素正常拓扑排序;
}

int main(){
    int i, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        nn = 0;
        int aa, bb;
        for(i = 0; i < M; i++)
            vec[i].clear();
        fill(is, is + M, false);
        for(i = 0; i < m; i++){
            scanf("%d%d", &aa, &bb);
            //printf("%c%c", a, b);
            if(!is[aa]){
                nn++;
                is[aa] = true;
            }
            if(!is[bb]){
                nn++;
                is[bb] = true;
            }
            vec[aa].push_back(bb);
        }
        int choice = tosort();              // 1 代表有环   2 代表没有环但是不确定  3 代表 满足条件;
        if(choice == 1)
            printf("%d\n", -1);
        else{
            int k = 0;
            for(int i = 1; i <= n; i++){
                if(is[i]) printf("%d", ans[k++]);
                else printf("%d", i);
                if(i == n) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
