#include <iostream>
#include <cstdio>
#define N 100010
#define M -0x3f3f3f3f
using namespace std;

int n, a[N], lef[N], righ[N], sum[N];
int c, b;

int solute(int x, int y){
    int i, j, k;
    int ans = M, temp = 0;
    for(i = x; i <= y; i++){
        lef[i] = i;
        righ[i] = i;
    }
    for(i = x; i <= y; i++){
        k = i;
        while(a[i] <= a[k - 1]) 
            lef[i] = lef[k - 1], k = lef[k - 1];
    }
    for(i = y; i >= x; i--){
        j = i;
        while(a[i] <= a[j + 1])
            righ[i] = righ[j + 1], j = righ[j + 1];
    }
    for(i = x; i <= y; i++)
        cerr << lef[i] <<" "<< righ[i] << endl;
    for(i = x; i <= y; i++){
        temp = (sum[righ[i]] - sum[lef[i] - 1]);
        if(ans <= temp){
            ans = temp;
            c = lef[i];
            b = righ[i];
        }
    }
    return ans;
}

int main(){
    int i, x, su, v, sum1, sum2, sum3, ans = 0;
    while(scanf("%d", &n) && n != 0){
        ans = 0;
        su = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &v);
            a[i] = v;
            su += v;
            sum[i] = su;
        }
        a[0] = a[n + 1] = M;
        sum1 = solute(1, n);
        cerr <<"sum1 "<< sum1 << endl;
        cerr << c <<" "<< b << endl;
        x = b;
        a[c] = M;
        if(c != 1)
            sum2 = solute(1, c - 1);
        else sum2 = M;
        cerr <<"sum2 "<< sum2 <<endl;
        a[x] = M;
        if(x != n)
            sum3 = solute(x + 1, n);
        else sum3 = M;
        cerr <<"sum3 "<< sum3 << endl;
        if(sum2 == M && sum3 == M)
            ans = 0;
        else
            ans = sum2 > sum3 ? sum2 : sum3;
        ans += sum1;
        printf("%d\n", ans);
    }
    return 0;
}
