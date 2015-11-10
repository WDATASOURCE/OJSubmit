/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-11 12:56
# Filename:			b.cpp
# Description: 
=============================================================================*/
#include <cstdio>
#include <cstring>
char met[28], ch[90]; 

int main(){
    gets(met);
    gets(ch);
    int len = strlen(ch);
    printf("%s\n%s\n", met, ch);
    for(int i = 0; i < len; i++){
        if(ch[i] >= 'a' && ch[i] <= 'z')
            printf("%c", met[(ch[i] - 'a')]);
        else if(ch[i] >= 'A' && ch[i] <= 'Z')
            printf("%c", met[(ch[i] - 'A')] - 'a' + 'A');
        else printf("%c", ch[i]);
    }
    printf("\n");
    return 0;
}
