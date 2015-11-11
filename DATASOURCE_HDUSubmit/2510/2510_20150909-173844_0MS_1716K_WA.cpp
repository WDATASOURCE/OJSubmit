#include <cstdio>
const int r[] = {0, 0, 0, 4, 6, 0, 0, 12, 40, 0, 0, 171, 410, 0, 0, 1896, 5160, 0, 0, 32757, 59984, 0, 0, 431095, 822229, 0};

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(!n) break;
        printf("%d\n", r[n]);
    }
    return 0;
}
