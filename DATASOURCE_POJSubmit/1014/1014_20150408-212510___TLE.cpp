#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int w[7] = {0, 1, 2, 3, 4, 5, 6};
int c[7];
int v, f;

void DFS(int ans, int n){
    if(ans == v){
        f = 1;
        return;
    }else if(ans > v || n > 6 || f) return;
    for(int i = c[n]; i >= 0; i--){
        DFS(ans + w[n] * i, n + 1);
        if(f) return;
    }
}

int main(){
    for(int di = 1; ; di++){
        int sum = 0;
        for(int i = 1; i <= 6; i++){
            scanf("%d", &c[i]);
            sum += (c[i] * i);
        }
        if(sum == 0) break;
        printf("Collection #%d:\n", di);
        if(sum & 1){
            printf("Can't be divided.\n\n");
            continue;
        }
        f = 0;
        v = sum >> 1;
        DFS(0, 1); 
        if(f) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}
        
