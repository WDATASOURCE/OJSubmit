#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 110
using namespace std;

int mp[N][N];

int main(){
    int i, n, j;
    while(scanf("%d", &n) != EOF){
        int ans = 0;
        for(i = 1; i <= n; i++)
        for(j = 1; j <= i; j++)
        scanf("%d", &mp[i][j]);
        for(i = n; i >= 2; i--)
        for(j = 1; j < i; j++)
            mp[i - 1][j] += max(mp[i][j], mp[i][j + 1]);
        printf("%d\n", mp[1][1]);
    }
    return 0;
}
