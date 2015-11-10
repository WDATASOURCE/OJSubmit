#include <cmath>
#include <cstdio>

int main(){
    double mi, i, j, ansx, ansy, n, k;
    while(scanf("%lf%lf", &k, &n) != EOF){
        mi = k + 1;
        i = 1;
        j = 1;
        ansx = i;
        ansy = j;
        for(;i <= n && j <= n;){
            if(i / j > k){
                if(i / j - k < mi){
                    mi = i / j - k;
                    ansx = i;
                    ansy = j;
                }
                j++;
            }
            else{
                if(k - i / j < mi){
                    mi = k - i / j;
                    ansx = i;
                    ansy = j;
                }
                i++;
            }
        }
        printf("%d %d\n", (int)ansx, (int)ansy);
    }
}
