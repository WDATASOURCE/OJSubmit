#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int a[3];
int sum[3][2000];

void change(){
    for(int i = 0; i < 3; i++){
        int j = 0;
        while(a[i]){
            sum[i][j++] = a[i] % 10;
            a[i] /= 10;
        }
    }
    return;
}

int main(){
    int i, j, k, l, r;
    while(scanf("%d%d%d", &a[0], &a[1], &a[2]) != EOF){
        fill(sum[0], sum[3], 0);
        change();
        k = 0;
        for(i = 3; i <= 99; i++){
            k = 0;
            int t = i % 3;
            if(t == 1)
            l = 0, r = 2;
            else if(t == 2)
            l = 0, r = 1;
            else
            l = 1, r = 2;
            for(j = 0; j < 2000; j++){
                int s = sum[t][j] + sum[l][j] + sum[r][j] + k;
                k = s / 10;
                sum[t][j] = s % 10;
            }
        }
        j = 2000 - 1;
        while(!sum[0][j])
            j--;
        for(i = j; i >= 0; i--)
            printf("%d", sum[0][i]);
        printf("\n");
    }
    return 0;
}
