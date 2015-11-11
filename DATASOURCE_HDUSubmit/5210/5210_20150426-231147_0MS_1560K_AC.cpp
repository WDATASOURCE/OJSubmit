#include <set>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a[110];
bool vis[110];

int main() {
    int n;
    while(scanf("%d", &n) != EOF){
        fill(vis, vis + 110, false);
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < n;i++){
            scanf("%d", &a[i]);
            if(!vis[a[i]]){
                cnt1++;
                vis[a[i]] = true;
            }else cnt2++;
        }
        int k;
        scanf("%d", &k);
        if(k <= cnt2) printf("%d\n", cnt1);
        else printf("%d\n", cnt1 - (k - cnt2));
    }
    return 0;
}
