#include <cstdio>
#include <cstdlib>

int main(){
    int n, i;
    while(scanf("%d", &n) != EOF){
        if(n == 0)
        break;
        int a[15];
        for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
        for(int b = 0; b < n; b++)
        for(int c = b + 1; c < n; c++)
        for(int d = c + 1; d < n; d++)
        for(int e = d + 1; e < n; e++)
        for(int f = e + 1; f < n; f++)
        for(int g = f + 1; g < n; g++)
        printf("%d %d %d %d %d %d\n\n", a[b], a[c], a[d], a[e], a[f], a[g]);
    }
    return 0;
}
