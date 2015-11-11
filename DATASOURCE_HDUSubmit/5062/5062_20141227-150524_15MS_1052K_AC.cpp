#include <cstdio>
#include <algorithm>
#define N 1000050
using namespace std;

int a[7] = {1, 9, 18, 54, 90, 174, 258};

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}
