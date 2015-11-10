#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;
int a[20010];

int main(){
    int n, v, i;
    while(scanf("%d", &n) != EOF){
        int sum = 0;
        int cost = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &v);
            sum += v;
            a[i] = v;
        }
        for(i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(a[i] <  a[j]){
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
        cost = sum;
        for(i = 0; i < n - 2; i++){
            sum -= a[i];
            cost += sum;
        }
        printf("%d\n", cost);
    }
    return 0;
}

        
