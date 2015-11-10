#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct stu{
    int a, b, c;
    int v;
    char ch[10];
};
stu a[10];

int main(){
    int n, i, j, ma, map, mi, mip;
    while(scanf("%d", &n) != EOF){
        if(n == -1)
        break;
        ma = 0, mi = (1 << 30);
        for(i = 0; i < n; i++){
            scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
            a[i].v = a[i].a * a[i].b * a[i].c;
            getchar();
            scanf("%s", a[i].ch);
        }
        for(i = 0; i < n; i++){
            if(a[i].v < mi){
                mi = a[i].v;
                mip = i;
            }
            if(a[i].v > ma){
                ma = a[i].v;
                map = i;
            }
        }
        printf("%s took clay from %s.\n", a[map].ch, a[mip].ch);
    }
    return 0;
}
