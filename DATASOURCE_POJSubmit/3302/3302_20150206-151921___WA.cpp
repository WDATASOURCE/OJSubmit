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
        scanf(" %s %s", c, s);
        int len1 = strlen(c);
        int len2 = strlen(s);
        int f = 1;
        int di = 0;
        for(int i = 0; i < len2; i++){
            while(c[di] != s[i] && di < len1) di++;
            if(di == len1){ 
                f = 0;
                break;
            }
            di++;
        }
        //cerr <<"f = "<< f << endl;
        if(!f){
            f = 1, di = len1 - 1;
            for(int i = 0; i < len2; i++){
                while(c[di] != s[i] && di >= 0) di--;
                if(di == -1){
                    f = 0;
                    break;
                }
                di--;
            }
        }
        if(f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
