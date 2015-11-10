#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
    int i;
    int k = 0;
    int p, e, n, d;
    while(scanf("%d%d%d%d", &p, &e, &n, &d) != EOF){
        if(p == -1 && e == -1 && n == -1 && d == -1)
            break;
        int v = p > e ? p : e;
        i = v > n ? v : n;
        if(i == 0)
            i = 21252;
        for(; ; i++)
            if((i - p) % 23 == 0 && (i - e) % 28 == 0 && (i - n) % 33 == 0)
                break;
        printf("Case %d: the next triple peak occurs in %d days.\n", ++k, (i - d));
    }
    return 0;
}
