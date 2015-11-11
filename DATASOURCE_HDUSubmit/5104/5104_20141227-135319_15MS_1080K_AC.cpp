#include <cstdio>
#include <algorithm>
#define N 100
using namespace std;

int a[10000];
bool is[11000];

void solve(){
    fill(is, is + 11000, false);
    int di = 0;
    is[0] = is[1] = true;
    for(int i = 2; i < 11000; i++){
        if(!is[i]) a[di++] = i;
        for(int j = 0; j < di && a[j] * i < 11000; j++){
            is[a[j] * i] = true;
            if(i % a[j] == 0) break;
        }
    }
}
 
int main(){
    solve();
    int n;
    while(scanf("%d", &n) != EOF){
        int ans = 0;
        for(int i = 0; a[i] < n; i++){
            for(int j = i; a[i] + a[j] < n; j++){
                int tt = n - a[i] - a[j];
                if(tt >= a[j] && !is[tt]) ans++;
                if(tt < a[j]) break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
