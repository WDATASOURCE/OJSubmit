#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MaxN = 1e3 + 10;
bool cnt[MaxN];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            cnt[x] = true;
        }
        bool isok = false;
        for (int i = 1; i <= n + 2; i++) 
            if (!cnt[i]) {
                if (!isok) printf("%d ", i), isok = true;
                else printf("%d\n", i);
            }
    }
}