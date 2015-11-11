#include <cstdio>
#include <algorithm>
#define N 100
using namespace std;

void solve(int n){
    int a[5] = {1, 2, 4, 7, 15};
    for(int i = 4; i >= 0; i--)
        if(n - a[i] > 0) printf("%d%c", n - a[i], i == 0 ? '\n' : ' ');
}
 
int main(){
    int n;
    while(~scanf("%d", &n)) solve(n);
    return 0;
}
