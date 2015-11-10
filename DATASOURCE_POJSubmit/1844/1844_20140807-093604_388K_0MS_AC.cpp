#include <cstdio>

int main(){
    int s, ans;
    while(scanf("%d", &s) != EOF){
        ans = 0;
        for(int i = 0; ; i++){
            ans += i;
            if(ans - s >= 0 && (ans - s) % 2 == 0){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
