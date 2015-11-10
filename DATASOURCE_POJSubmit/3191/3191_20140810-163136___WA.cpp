#include <cstdio>
#include <stack>
using namespace std;
stack <int> sta;

int main(){
    int n, i;
    while(scanf("%d", &n) != EOF){
        int ans;
        if(n == 0){
            printf("%d\n", 0);
            continue;
        }
        while(n != 0){
            ans = n % -2;
            i = ans >> 31;
            ans = (ans ^ i) - i;
            if(n < 0)
            n = n / -2 + 1;
            else
            n = n / -2;
            sta.push(ans);
        }
        while(!sta.empty()){
            printf("%d", sta.top());
            sta.pop();
        }
        printf("\n");
    }
    return 0;
}
