#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

int a[50];
int main(){
    int n, i;
    while(scanf("%d", &n) != EOF){
        int ans, k = 0;
        if(n == 0){
            printf("%d\n", 0);
            continue;
        }
        while(n != 0){
            ans = n % -2;
            i = ans >> 31;
            ans = (ans ^ i) - i;
            if(n / -2 * -2 > n)
            n = n / -2 + 1;
            else
            n = n / -2;
            a[k++] = ans;
        }
        for(i = k - 1; i >= 0; i--)
        printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}
