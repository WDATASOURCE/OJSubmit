#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        int i, ans = 0;
        int aa = a, bb = b;
        if(a > b){
            b ^= a;
            a ^= b;
            b ^= a;
        }
        for(i = a; i <= b; i++){
            int ip = 1, t = i;
            while(t != 1){
                ip++;
                if(t & 1)
                    t = t * 3 + 1;
                else
                    t >>= 1;
            }
            ans = ans > ip ? ans : ip;
        }
        printf("%d %d %d\n", aa, bb, ans);
    }
    return 0;
}
