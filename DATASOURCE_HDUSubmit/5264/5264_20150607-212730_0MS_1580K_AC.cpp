#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char ch[110];
char a[110];
char b[110];

int main(){
    int t;
    scanf("%d", &t);
    getchar();
    while(t--){
        scanf("%s", ch);
        int len = strlen(ch);
        int dx = 0, dy = 0;
        int i = 0;
        while(i < len){
            a[dx++] = ch[i++];
            b[dy++] = ch[i++];
        }
        a[dx] = b[dy] = 0;
        int len1 = strlen(b);
        printf("%s\n", a);
        for(int i = len1 - 1; i >= 0; i--)
            printf("%c", b[i]);
        printf("\n");
    }
    return 0;
}
