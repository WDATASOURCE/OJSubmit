#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int m, t, u, f, d;
    while(scanf("%d%d%d%d%d", &m, &t, &u, &f, &d) != EOF){
        int ans = 0, di = 0;
        char c;
        while(t--){
            scanf("\n%c", &c);
            if(c == 'u' || c == 'd')
                ans += u + d;
            else if(c == 'f')
                ans += 2 * f;
            if(ans <= m)
                di++;
        }
        printf("%d\n", di);
    }
    return 0;
}
