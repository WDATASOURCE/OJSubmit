#include <cstdio>
#include <iostream>
#include <algorithm>
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int w[7] = {0, 1, 2, 3, 4, 5, 6};
int v[7], V;
int dp[120010];
bool f;

void CompletePack(int w, int v){
    for(int i = w; i <= V; i++){
        dp[i] = Max(dp[i], dp[i - w] + v);
        if(dp[i] == V){ 
            f = true;
            return;
        }
    }
}

void ZeroOnePack(int w, int v){
    for(int i = V; i >= w; i--){
        dp[i] = Max(dp[i], dp[i - w] + v);
        if(dp[i] == V){
            f = true;
            return;
        }
    }
}

void MultiplePack(int w, int v, int am){
    if(w * am >= V){
        CompletePack(w, v);
        return;
    }
    if(f) return;
    int k = 1; 
    while(k < am){
        ZeroOnePack(k * w, k * v);
        if(f) return;
        am -= k;
        k *= 2;
    }
    ZeroOnePack(am * w, am * v);
    return;
}

int main(){
    for(int di = 1; ; di++){
        int sum = 0;
        for(int i = 1; i <= 6; i++){
            scanf("%d", &v[i]);
            sum += v[i] * i;
        }
        if(sum == 0) break;
        printf("Collection #%d:\n", di);
        if(sum & 1){
            printf("Can't be divided.\n\n");
            continue;
        }
        V = sum >> 1;
        f = 0;
        fill(dp, dp + 120010, -1);
        dp[0] = 0;
        for(int i = 1; i <= 6; i++){
            MultiplePack(i, i, v[i]);
            if(f) break;
        }
        if(f) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}

