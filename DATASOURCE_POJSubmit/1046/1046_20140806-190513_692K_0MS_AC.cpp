#include <iostream>
#include <cstdio>
#define M 1 << 30
using namespace std;

struct color{
    int r, g, b;
};

color a[17];

int main(){
    int i, r, g, b;
    for(i = 0; i < 16; i++)
        scanf("%d%d%d", &a[i].r, &a[i].g, &a[i].b);
    while(scanf("%d%d%d", &r, &g, &b) != EOF){
        if(r == -1 && g == -1 && b == -1)
            break;
        int ans = M, ansp = -1;
        for(i = 0; i < 16; i++){
            int d = (a[i].r - r) * (a[i].r - r) + (a[i].g - g) * (a[i].g - g) + (a[i].b - b) * (a[i].b - b);
            if(d < ans)
                ans = d,ansp = i;
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, a[ansp].r, a[ansp].g, a[ansp].b);
    }
    return 0;
}
