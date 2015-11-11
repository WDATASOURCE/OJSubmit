#include <cstdio>
#include <algorithm>
#define N 1000050
using namespace std;

int a[6];

int main(){
    int sum, v, t;
    scanf("%d", &t);
    while(t--){
        sum = 0;
        for(int i = 0; i < 6; i++){
            scanf("%d", &v);
            sum += v;
            a[i] = v;
        }
        sort(a, a + 6);
        if((a[5] + a[4]) <= (sum - a[5] - a[4] - a[0])) printf("What a sad story!\n");
        else printf("Grandpa Shawn is the Winner!\n");
    }
    return 0;
}
