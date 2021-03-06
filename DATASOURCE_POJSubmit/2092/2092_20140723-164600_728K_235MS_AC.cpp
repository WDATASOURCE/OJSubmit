#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define M 10010
using namespace std;

struct play{
    int d, i;
};
play a[M];
int n, m;

bool cmp(play a, play b){
    if(a.i == b.i)
        return b.d < a.d;
    else
        return b.i < a.i;
}

int main(){
    int i, j;
    while(scanf("%d%d", &n, &m)){
        if(n == 0 && m == 0)
            break;
        memset(a, 0, sizeof(a));
        int v;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++){
                scanf("%d", &v);
                a[v].d = v;
                a[v].i++;
            }
        sort(a + 1, a + M, cmp);
        i = 1;
        while(a[i].i == a[1].i)
            i++;
        j = i;
        while(a[i].i == a[j].i)
            j++;
        j--;
        for(; a[j].i == a[i].i; j--)
            printf("%d ", a[j].d);
        printf("\n");
    }
    return 0;
}