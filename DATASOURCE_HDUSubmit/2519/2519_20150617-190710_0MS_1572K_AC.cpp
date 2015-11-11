#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int c[40][40];

int main(){
    int t;
    scanf("%d", &t);
    fill(c[0], c[40], 0);
    for(int i = 1; i < 31; i++)
        c[i][1] = i, c[i][0] = 1;
    for(int i = 1; i < 31; i++){
        for(int j = 2; j <= i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    while(t--){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", c[a][b]);
    }
    return 0;
}
