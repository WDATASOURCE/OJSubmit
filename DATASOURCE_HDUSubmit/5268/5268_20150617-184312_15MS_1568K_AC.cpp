#include <cstdio>
#include <iostream>
using namespace std;
int s[]={1000, 1500, 2000, 2500};
int a[10];
int b[10];

int main(){
    int t;
    scanf("%d", &t);
    for(int di = 1; di <= t; di++){
        for(int i = 0; i < 4; i++)
            scanf("%d%d", &a[i], &b[i]);
        int ans = 0;
        for(int i = 0; i < 4; i++){
            int t = s[i] / 250 * (250 - a[i]) - 50 * b[i];
            if(t < s[i] / 100 * 40) t = s[i] / 100 * 40;
            ans += t;
        }
        printf("Case #%d: %d\n", di, ans);
    }
    return 0;
}
