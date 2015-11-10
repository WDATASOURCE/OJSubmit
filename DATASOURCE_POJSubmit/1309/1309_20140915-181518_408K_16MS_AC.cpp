#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;

bool istrue(int x){
    int i;
    int nn = n;
    for(i = 0; i < x; i++){
        nn--;
        if(nn % x)
        return false;
        nn /= x;
        nn *= (x - 1);
    }
    if(nn % x)
    return false;
    else
    return true;
}

int find(){
    int i;
    for(i = n; i > 1; i--)
    if(istrue(i))
    break;
    return i;
}

int main(){
    int i, j;
    while(scanf("%d", &n) != EOF){
        if(n == -1)
            break;
        int ans = find();
        if(ans == 1)
            printf("%d coconuts, no solution\n", n);
        else
            printf("%d coconuts, %d people and 1 monkey\n", n, ans);
    }
    return 0;
}
