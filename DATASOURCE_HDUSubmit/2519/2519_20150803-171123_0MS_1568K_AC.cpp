#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int c[40][40];

int main(){
    fill(c[0], c[40], 0);
    for(int i = 0; i < 31; i++)
        c[i][0] = 1;
    for(int i = 1; i < 31; i++){
        for(int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    int t, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        printf("%d\n", c[a][b]);
    }
    return 0;
}
