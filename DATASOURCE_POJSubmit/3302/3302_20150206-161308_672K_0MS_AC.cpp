#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 105
using namespace std;

char c[N];
char s[N];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        while(n--){
            scanf(" %s %s", c, s);
            //cerr <<"c = "<< c <<" s = "<< s << endl;
            int len1 = strlen(c);
            int len2 = strlen(s);
            int i = 0, j = 0;
            int f = 0;
            for(; i < len1 && j < len2; ){
                if(c[i] == s[j]) i++, j++;
                else i++;
            }
            if(j == len2) f = 1;
            i = len1 - 1, j = 0;
            for(; i >= 0 && j < len2; ){
                if(c[i] == s[j]) i--, j++;
                else i--;
            }
            if(j == len2) f = 1;
            if(f) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
