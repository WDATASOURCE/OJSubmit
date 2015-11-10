#include<iostream>
using namespace std;
#define N 110
#define M 0x3f3f3f3f
int map[N][N], low[N], visited[N];
int n;

void prim(){
    int i, j, min, minp, key = 0;
    for(i = 0; i < n; i++)
        visited[i] = -1;
    visited[0] = 0;
    minp = 0;
    min = M;
    for(j = 0; j < n; j++)
        if(j != 0 )
             low[j] = map[0][j];
    for(i = 0; i < n - 1; i++){                                 // 由 i < n 改为 i < n - 1     最后一个数不用循环
        min = M;
        for(j = 0; j < n; j++)
            if(visited[j] == -1 && min > low[j]){
                min = low[j];
                minp = j;
            }
        visited[minp] = 0;
        key += min;
        for(j = 0; j < n; j++)
            if(visited[j] == -1 && map[minp][j] < low[j])
                low[j] = map[minp][j];
    }
    cout << key << endl;
}




int main(){
    ios_base::sync_with_stdio(false);
    int i , j;
    while(cin >> n){
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                cin >> map[i][j];
        prim();
    }
    return 0;

}
    


