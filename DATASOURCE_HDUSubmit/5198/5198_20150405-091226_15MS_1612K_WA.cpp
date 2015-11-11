#include <cstdio>
#include <cstring>
char ch[100];
int a[100];

int main(){
    while(scanf("%s", ch) != EOF){
        for(int i = 0; i < 100; i++) a[i] = 0;
        int len = strlen(ch);
        for(int i = 0; i < len; i++)
            a[ch[i] - 'a']++;
        bool fffff = 1;
        int k = 0, f = 0;
        for(int i = 0; i < 100; i++){
            if(a[i] && !f) k++, f = a[i];
            else if(a[i] && f){
                k++;
                if(f != a[i]) fffff = 0;
            }
        }
        if(k == 3 && fffff) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
