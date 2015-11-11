#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 1008
using namespace std;

int n,m;
char s[maxn], ans[maxn];

int f(char x) {
    if(x <= '9' && x >= '0') return x - '0';
    else return x - 'a' + 10;
}

char fx(int x) {
    if(x <= 9 && x >= 0) return x + '0';
    else return x - 10 + 'a';
}

void add(char *a, char *b) {
    int la = strlen(a);
    int lb = strlen(b);
    int i = la - 1;
    int j = lb - 1;
    if(la > lb)
    while(i >= 0 && j >= 0) {
        a[i] = fx((f(a[i]) + f(b[j])) % m);
        i --; j --;
    }
    else {
        while(i >= 0 && j >= 0) {
            b[j] = fx((f(a[i]) + f(b[j])) % m);
            i --; j --;
        }
        strcpy(a, b);
    }
}

int main() {
    while(~scanf("%d%d",&n,&m)) {
        scanf("%s",ans);
        for(int i = 1; i < n; i++){
            scanf("%s",s);
            add(ans, s);
        }
        int i = 0;
        while(ans[i] == '0' && ans[i]) i ++;
        if(!ans[i]) puts("0");
        else printf("%s\n",ans + i);
    }
}
