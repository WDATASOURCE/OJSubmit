#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int prime[1240], j;
bool a[10023];

void makeprime(){
    int i;
    fill(a, a + 10023, false);
    prime[1] = 2;
    a[2] = true;
    j = 2;
    for(i = 2; i <= 10022; i++){
        if(!a[i])
            prime[j++] = i;
        for(int k = 1; k < j && i * prime[k] < 10023; k++){
            a[i * prime[k]] = true;
            if(i % prime[k] == 0)
                break;
        }
    }
}

int main(){
    int i, n, ans, sum, k;
    makeprime();
    while(scanf("%d", &n) != EOF && n){
        ans = 0;
        for(i = 1; i < j && prime[i] <= n; i++){
            sum = 0;
            for(k = i; k < j; k++){
                sum += prime[k];
                if(sum == n){
                    ans++;
                    continue;
                }
                if(sum > n)
                    continue;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}