#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define M 30
using namespace std;

vector <int> vec[M];
int degree[M];     
int ans[M];       
bool is[M];      
int n, m, nn;   

int tosort(){
    int i, j;
    int f = 0;   
    int ff = 0; 
    int count = 0;
    fill(degree, degree + M, 0);
    stack <int> sta;
    for(i = 1; i <= n; i++){
        int end = vec[i].size();
        for(j = 0; j < end; j++)
            degree[vec[i][j]]++;
    }
    for(i = 1; i <= n; i++){
        if(degree[i] == 0 && is[i])
            sta.push(i);
    }
    if(sta.size() > 1)  
        f = 1;
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
        if(sta.size() > 1)
            f = 1;
    }
    if(count < nn) return 1; 
    else if(f) return 2;
    else return 3;
}

int main(){
    int i, j;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0 && m == 0)
            break;
        nn = 0;
        char a, b;
        int f = 0;
        int fx = 0;
        int ff = 0;
        int ffx = 0;
        for(i = 0; i < M; i++)
            vec[i].clear();
        fill(is, is + M, false);
        for(i = 0; i < m; i++){
            getchar();
            scanf("%c<%c", &a, &b);
            int aa = a - 'A' + 1;
            int bb = b - 'A' + 1;
            if(!is[aa]){
                nn++;
                is[aa] = true;
            }
            if(!is[bb]){
                nn++;
                is[bb] = true;
            }
            vec[aa].push_back(bb);
            int choice = tosort();              // 1 代表有环   2 代表没有环但是不确定  3 代表 满足条件;
            if(choice == 1 && !f){
                f = 1;                          // 出现矛盾;
                fx = i + 1;
            }
            else if(choice == 3 && nn == n && !ff){
                ff = 1;
                ffx = i + 1;
            }
        }
        if(ff){
            printf("Sorted sequence determined after %d relations: ", ffx);
            for(int i = 0; i < n; i++)
                printf("%c", ans[i] - 1 + 'A');
            printf(".\n");
        }
        else if(f)
            printf("Inconsistency found after %d relations.\n", fx);
        else
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
