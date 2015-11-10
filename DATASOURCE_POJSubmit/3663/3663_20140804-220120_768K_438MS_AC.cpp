#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[20010];
int main(){
    int n, s, i, j;
    while(scanf("%d%d", &n, &s) != EOF){
        bool f = false;
        int ans = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for(i = 0; i < n; i++){
            f = false;
            for(j = i + 1; j < n; j++){
                if(a[i] + a[j] <= s)
                    ans++, f = true;
                else
                    break;
            }
            if(f == false)
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
