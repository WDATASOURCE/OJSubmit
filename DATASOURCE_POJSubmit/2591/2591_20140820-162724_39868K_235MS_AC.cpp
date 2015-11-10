#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 10000002
using namespace std;

int a[N];

void makesh(){
    a[1] = 1;
    int n1 = 1, n2 = 1;
    for(int i = 2; i <= N; i++){
        a[i] = min(a[n1] * 2 + 1, a[n2] * 3 + 1);
        if(a[i] == a[n1] * 2 + 1)
        n1++;
        if(a[i] == a[n2] * 3 + 1)
        n2++;
    }
}

int main(){
    int m;
    makesh();
    while(scanf("%d", &m) != EOF)
    printf("%d\n", a[m]);
    return 0;
}
