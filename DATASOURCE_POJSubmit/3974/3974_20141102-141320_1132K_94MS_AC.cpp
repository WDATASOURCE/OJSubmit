#include <cstdio>
#include <cstring>
char str[1000002 + 200];
int fast(char *p) {
    int ans = 1;
    for (int i = 1; p[i]; ++i) {
        int s = i, e = i, t;
        while (p[e + 1] == p[i]) ++e;
        i = e;
        while (p[s - 1] == p[e + 1]) --s, ++e;
        if ((t = e - s + 1) > ans) ans = t; }
    return ans; }
int main() {
    str[0]='$'; int id = 0;
    while (scanf("%s", str + 1) != EOF) {
        if(strcmp(str, "$END") == 0) break;
        printf("Case %d: %d\n", ++id, fast(str)); }
    return 0; }
