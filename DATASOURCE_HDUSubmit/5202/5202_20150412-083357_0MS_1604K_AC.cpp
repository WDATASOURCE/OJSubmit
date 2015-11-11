#include <cstdio>
using namespace std;

int n;
char ans[1100], a[1100], S[1100];
bool ok;

void test(int k){
    if(ok) return ;
    for (int i = 0; i < n; i++) {
        if (S[i] == '?') {
            if (k == i) a[i] = 'b';
            else a[i] = 'a';
        }else a[i] = S[i];
    }
    int l = 0, r = n - 1;
    bool o = false;
    while(l < r) {
        if (a[l] != a[r]) o = true;
        l++;
        r--;
    }
    if(o) {
        ok = true;
        for (int i = 0; i < n; i++)
            ans[i] = a[i];
        ans[n] = '\0';
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        scanf("%s", S);
        sprintf(ans, "QwQ");
        ok = false;
        test(-1);
        for (int i = n - 1; i >= 0; i--){
            if(ok) break;
            test(i);
        }
        printf("%s\n", ans);
    }
}
