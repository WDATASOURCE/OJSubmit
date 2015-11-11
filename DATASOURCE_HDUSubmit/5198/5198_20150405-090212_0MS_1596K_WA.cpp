#include <cstdio>
#include <cstring>
char ch[100];

int main(){
    while(gets(ch) != NULL){
        int len = strlen(ch);
        int f = 1, ff = 0, fff = 0;
        for(int i = 1; i < len; i++){
            if(ch[i] == ch[i - 1]) f++;
            else if(ff) fff++;
            else ff++;
        }
        if(ff == f && f == fff) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
