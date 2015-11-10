#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[355][355];

int main(){
    int i, n, sum, j;
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++)
        for(j = 0; j <= i; j++)
        scanf("%d", &a[i][j]);
        for(i = n; i > 0; i--)
        for(j = 0; j < i; j++)
        a[i - 1][j] += max(a[i][j], a[i][j + 1]);
        printf("%d\n", a[0][0]);
    }
    return 0;
}
