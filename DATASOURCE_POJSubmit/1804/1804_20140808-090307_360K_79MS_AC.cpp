#include <cstdio>
using namespace std;

int a[1011], n;

int main(){
    int i, k, t, j = 0;
    scanf("%d", &t);
    while(t--){
        int ans = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(i = 0; i < n; i++)
            for(k = i + 1; k < n; k++)
                if(a[i] > a[k])
                    ans++;
        printf("Scenario #%d:\n%d\n\n", ++j, ans);
    }
    return 0;
}    
