#include <cstdio>
int a[505][105];

int main(){
    int n, d, i, j;
    while(scanf("%d%d", &d, &n) != EOF){
        if(n == 0 && d == 0)
        break;
        for(i = 0; i < n; i++)
            for(j = 0; j < d; j++)
                scanf("%d", &a[i][j]);
        int f = 1;
        for(j = 0; j < d; j++){
            int sum = 0;
            for(i = 0; i < n; i++)
            sum += a[i][j];
            if(sum == n){
                printf("yes\n");
                f = 0;
                break;
            }
        }
        if(f)
        printf("no\n");
    }
    return 0;
}
