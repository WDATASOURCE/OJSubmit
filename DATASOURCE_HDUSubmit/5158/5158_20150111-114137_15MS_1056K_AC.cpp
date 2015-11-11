#include <cstdio>
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF) printf("%d\n", (m - 1) % n);
    return 0;
}
