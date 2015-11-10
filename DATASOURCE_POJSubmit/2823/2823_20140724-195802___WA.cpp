#include<iostream>
#include<cstdio>
#include<queue>
#define M 1000010
using namespace std;

int a[M];
int n, k;

struct cmp{
    bool operator()(int x, int y){
        return x > y;
    }
};

priority_queue<int, vector<int>, cmp> pq1;
priority_queue<int> pq2;

int main(){
    int i;
    while(scanf("%d%d", &n, &k) == 2){
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("%d ", a[0] < (a[1] < a[2] ? a[1] : a[2]) ? a[0] : (a[1] < a[2] ? a[1] : a[2]));
        for(i = 3; i < n; i++)
            printf("%d ", a[i - 2] < (a[i - 1] < a[i] ? a[i - 1] : a[i]) ? a[i - 2] : (a[i - 1] < a[i] ? a[i - 1] : a[i]));
        printf("\n");
        printf("%d ", a[0] > (a[1] > a[2] ? a[1] : a[2]) ? a[0] : (a[1] > a[2] ? a[1] : a[2]));
        for(i = 3; i < n; i++)
            printf("%d ", a[i - 2] > (a[i - 1] > a[i] ? a[i - 1] : a[i]) ? a[i - 2] : (a[i - 1] > a[i] ? a[i - 1] : a[i]));
        printf("\n");
    }
    return 0;
}
