#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;
int a[20010];

int main(){
    ios_base::sync_with_stdio(false);
    int n, i;
    int v;
    while(scanf("%d", &n) != EOF){
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        long long sum = 0, cost = 0;
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
        cout << cost << endl;
    }
    return 0;
}

        
