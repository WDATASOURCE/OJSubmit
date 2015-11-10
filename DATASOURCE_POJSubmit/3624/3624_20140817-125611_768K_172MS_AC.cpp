#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 3410
#define M 12890
using namespace std;
int v[N], w[N], n, c;
int mp[M];

int main(){
    int i, j, sum;
    while(scanf("%d%d", &n, &c) != EOF){
        fill(mp, mp + M, 0);
        for(i = 1; i <= n; i++)
            scanf("%d%d", &w[i], &v[i]);
        for(i = 1; i <= n; i++)
        for(j = c; j >= w[i]; j--)
        if(mp[j - w[i]] + v[i] > mp[j])
        mp[j] = mp[j- w[i]] + v[i];
        printf("%d\n", mp[c]);
    }
    return 0;
}
