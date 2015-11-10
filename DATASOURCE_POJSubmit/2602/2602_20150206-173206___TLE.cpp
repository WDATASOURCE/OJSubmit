#include <cstdio>
#include <iostream>
#define N 1000010
using namespace std;

int a[N], b[N];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &a[i], &b[i]);
        int s, t = 0;
        for(int i = n; i >= 0; i--){
            s = a[i] + b[i] + t;
            a[i] = s % 10;
            t = s / 10;
        }
        for(int i = 1; i <= n; i++)
            printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}
