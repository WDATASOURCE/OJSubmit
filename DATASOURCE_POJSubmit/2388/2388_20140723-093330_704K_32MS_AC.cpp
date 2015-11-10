#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;

int n, a[10010];

int main(){
    int i;
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        printf("%d\n", a[n / 2]);
    }
    return 0;
}
