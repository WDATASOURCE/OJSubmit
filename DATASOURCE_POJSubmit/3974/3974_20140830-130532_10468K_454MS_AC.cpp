#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char ch[2000009];
int p[2000009];

int main(){
    int i, ans, k = 0, mx, id;
    while(1){
        char c;
        int len = 0;
        ans = 0;
        ch[len++] = '$';
        ch[len++] = '#';
        while((c = getchar()) != '\n'){
            ch[len++] = c;
            ch[len++] = '#';
        }
        ch[len] = '\0';
        if(strcmp(ch, "$#E#N#D#") == 0)
            break;
        mx = 0, id = 0;
        fill(p, p + 2000009, 0);
        for (i = 1; ch[i] != '\0'; i++) {
            p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
            while (ch[i + p[i]] == ch[i - p[i]]) p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        for(i = 0; i < 2000009; i++)
            ans = max(ans, p[i]);
        printf("Case %d: %d\n", ++k, ans - 1);
    }
    return 0;
}