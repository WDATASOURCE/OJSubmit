#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<queue>
#define M 1100000
using namespace std;

struct win{
    int p;
    long long d;
};

struct cmp1{
    bool operator()(win x, win y){
        return x.d > y.d;
    }
};
struct cmp2{
    bool operator()(win x, win y){
        return x.d < y.d;
    }
};

win a[M];
int n, k;

int main(){
    int i;
    while(scanf("%d%d", &n, &k) == 2){
        for(i = 0; i < n; i++){
            scanf("%I64d", &a[i].d);
            a[i].p = i;
        }
        priority_queue<win, vector<win>, cmp1> pq1;
        priority_queue<win, vector<win>, cmp2> pq2;
        if(n == 0){
            printf("%d\n%d\n", 0, 0);
            continue;
        }
        if(n <= k){
            for(i = 0; i < n; i++)
                pq1.push(a[i]);
            win b = pq1.top();
            printf("%I64d\n", b.d); 
            for(i = 0; i < n; i++)
                pq2.push(a[i]);
            win c = pq2.top();
            printf("%I64d\n", c.d);
            continue;
        }
        for(i = 0; i < n; i++){
            if(i > k - 1){
                win b = pq1.top();
                while(b.p <= i - k && !pq1.empty()){
                    pq1.pop();
                    if(!pq1.empty()) b = pq1.top();
                    else continue;
                }
            }
            pq1.push(a[i]);
            if(i < k - 1)
                continue;
            win c = pq1.top();
            printf("%I64d", c.d);
            if(i != n - 1)
                printf("%c",' ');
        }
        printf("\n");
        for(i = 0; i < n; i++){
            if(i > k - 1){
                win b = pq2.top();
                while(b.p <= i - k && !pq2.empty()){
                    pq2.pop();
                    if(!pq2.empty()) b = pq2.top();
                    else continue;
                }
            } 
            pq2.push(a[i]);
            if(i < k - 1)
                continue;
            win c = pq2.top();
            printf("%I64d", c.d);
            if(i != n - 1)
                printf("%c",' ');
        }
        printf("\n");
    }
    return 0;
}
