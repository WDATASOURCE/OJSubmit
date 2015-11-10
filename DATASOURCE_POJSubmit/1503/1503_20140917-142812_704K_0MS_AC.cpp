#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int ans[110];
char ch[110];

int main(){
    int i;
    fill(ans, ans + 110, 0);
    while(gets(ch) != NULL){
        if(strlen(ch) == 1 && ch[0] == '0')
            break;
        int len = strlen(ch);
        int s, e = 0;
        int j = 0;
        for(int i = len - 1; i >= 0; i--){
            s = ans[j] + ch[i] - '0' + e;
            ans[j++] = s % 10;
            e = s / 10;
        }
        while(e){
            s = ans[j] + e;
            ans[j++] = s % 10;
            e = s / 10;
        }
    }
    int j = 109;
    while(!ans[j])
        j--;
    for(i = j; i >= 0; i--)
        printf("%d", ans[i]);
    printf("\n");
    return 0;
}
