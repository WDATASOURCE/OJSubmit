#include <cstdio>
int n, m;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}

void work(){
    int temp = gcd(n + m, n * m);
    printf("%d/%d\n", n * m / temp, (n + m) / temp);
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
