#include <iostream>
#include <cstdio>
using namespace std;

struct point{
    int x, y;
};

point a[1100];

int main(){
    int n, i;
    while(scanf("%d", &n) != EOF){
    for(i = 0; i < n; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    int t, ans = 0;
    for(i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){
            t = 2;
            for(int k = j + 1; k < n; k++)
                if((a[k].y - a[i].y) * (a[j].x - a[i].x) == (a[j].y - a[i].y) * (a[k].x - a[i].x))
                    t++;
            ans = ans > t ? ans : t;
        }
    printf("%d\n", ans);
    }
    return 0;
}
