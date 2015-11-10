#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int w[7] = {0, 1, 2, 3, 4, 5, 6};
int c[7];
int v, f;
int s[7];

void DFS(int ans, int n){
    if(ans == v){
        f = 1; return;
    }
    for(int i = n; i > 0; i--){
        if(c[i] && ans + i <= v){
            c[i]--;
            DFS(ans + i, i);
            if(f) return;
        }
    }
}

int main(){
    for(int di = 1; ; di++){
        int sum = 0;
        s[0] = 0;
        for(int i = 1; i <= 6; i++){
            scanf("%d", &c[i]);
            sum += (c[i] * w[i]);
            s[i] = sum;
        }
        if(sum == 0) break;
        printf("Collection #%d:\n", di);
        if(sum & 1){
            printf("Can't be divided.\n\n");
            continue;
        }
        f = 0;
        v = sum >> 1;
        DFS(0, 6); 
        if(f) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}
