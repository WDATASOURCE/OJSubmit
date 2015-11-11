#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
    //if(a > b) return gcd(b, a);
    //else if(a == 0) return b;
    //else return gcd(b % a, a);
}

int a[1510];
int que[1510][3];

int main(){
    int t, n, q, l, r, res;
    scanf("%d", &t);
    for(int di = 1; di <= t; di++){
        scanf("%d%d", &n, &q);
        fill(a, a + 1010, 1);
        for(int i = 0; i < q; i++){
            scanf("%d%d%d", &l, &r, &res);
            que[i][0] = l, que[i][1] = r, que[i][2] = res;
            for(int j = l; j <= r; j++)
                a[j] = (long long)res * (long long)a[j] / gcd(res, a[j]);
        }
        int f = true;
        for(int i = 0; i < q; i++){
            int ll = que[i][0];
            int rr = que[i][1];
            int ans = que[i][2];
            int tt = a[ll];
            for(int j = ll + 1; j <= rr; j++)
                tt = gcd(a[j], tt);
            if(tt != ans){ 
                f = false;
                break;
            }
        }
        if(!f) printf("Stupid BrotherK!\n");
        else{
            for(int i = 1; i <= n; i++)
                printf("%d%c", a[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}