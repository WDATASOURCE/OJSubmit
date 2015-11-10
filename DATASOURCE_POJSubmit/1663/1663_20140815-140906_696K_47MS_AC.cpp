#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int t, a, b;
    scanf("%d", &t);
    while(t--){
        int ans;
        scanf("%d%d", &a, &b);
        if(a == b){
            int di = a % 2;
            ans = 4 * (a / 2);
            if(di)
            ans += 1;
            printf("%d\n", ans);
        }
        else if(b == a - 2 && a >= 2){
            int di = a % 2;
            ans = 4 * (a / 2);
            if(di)
            ans += 1;
            ans -= 2;
            printf("%d\n", ans);
        }
        else
        printf("No Number\n");
    }
   return 0;
}
