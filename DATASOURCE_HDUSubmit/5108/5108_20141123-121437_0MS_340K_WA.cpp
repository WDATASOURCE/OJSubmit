#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 1){
            printf("0\n");
            break;
        }
        int ans = 0, nn = n;
        for(int i = 2; i * i <= nn; i++){
            while(n % i == 0){
                ans = max(ans, i);
                n /= i;
            }
        }
        ans = max(ans, n);
        printf("%d\n", nn / ans);
    }
    return 0;
}
