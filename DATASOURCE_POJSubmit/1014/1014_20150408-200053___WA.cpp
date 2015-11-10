#include <cstdio>
#include <iostream>
#include <algorithm>
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int w[7] = {0, 1, 2, 3, 4, 5, 6};
int v[7];

int dp[7][20010];

int main(){
    for(int di = 1; ; di++){
        int sum = 0;
        fill(dp[0], dp[7], 0);
        //for(int i = 0; i < 7; i++){
            //for(int j = 0; j < 10; j++)
                //printf("%11d ", dp[i][j]);
            //printf("\n");
        //}
        for(int i = 1; i <= 6; i++){
            scanf("%d", &v[i]);
            sum += v[i] * i;
        }
        if(sum == 0) break;
        printf("Collection #%d:\n", di);
        if(sum & 1){
            printf("Can't be divided.\n\n");
            break;
        }
        int V = sum / 2;
        //cerr <<"V = "<< V << endl;
        for(int i = 1; i <= 6; i++){
            if(v[i] == 0){
                for(int j = 0; j <= V; j++) dp[i][j] = dp[i - 1][j];
                continue;
            }
            for(int j = 0; j <= V; j++){
                int nc = Min(v[i], j / w[i]);
                for(int k = 0; k <= nc; k++)
                    dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - k * w[i]] + w[i] * k);
            }
        }
        //for(int i = 0; i < 7; i++){
            //for(int j = 0; j < 10; j++)
                //printf("%11d ", dp[i][j]);
            //printf("\n");
        //}
        if(dp[6][V] == V) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}

