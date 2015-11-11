#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define M 110
using namespace std;

vector <int> vec[M];
int ingree[M];     
int ans[M];       
int n, m;        

bool TOSort(){  
    int i, j;
    int top = -1;  
    int count = 0;       
    fill(ingree, ingree + M, 0);
    for(i = 1; i <= n; i++){    
        int end = vec[i].size();
        for(j = 0; j < end; j++)
            ingree[vec[i][j]]++;
    }
    for(i = 1; i <= n; i++)    
        if(ingree[i] == 0){
            ingree[i] = top;
            top = i;
        }
    while(top != -1){       
        int t = top;
        top = ingree[t];
        ans[count++] = t;
        int end = vec[t].size();
        for(i = 0; i < end; i++){
            ingree[vec[t][i]]--;
            if(ingree[vec[t][i]] == 0){
                ingree[vec[t][i]] = top;
                top = vec[t][i];
            }
        }
    }
    if(count < n) return false;
    return true;
}
 
int main(){
    int i, a, b;
    while(~scanf("%d%d", &n, &m)){
        for(i = 0; i < M; i++)
            vec[i].clear();
        for(i = 0; i < m; i++){
            scanf("%d%d", &a, &b); 
            vec[a].push_back(b);
        }
        if(TOSort()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
