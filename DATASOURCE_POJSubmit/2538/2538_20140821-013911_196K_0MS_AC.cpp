#include <cstdio>
#include <iostream>
using namespace std;
char ch[50] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
char s[100];

int main(){
    int i, j;
    while(cin.getline(s, 100)){
        int len = strlen(s);
        for(i = 0; i < len; i++){
            if(s[i] == ' ')
                printf("%c", s[i]);
            else{
                for(j = 0; ch[j] && s[i] != ch[j]; j++);
                if(ch[j])
                    printf("%c", ch[j - 1]);
            }
        }
        printf("\n");
    }
    return 0;
}
