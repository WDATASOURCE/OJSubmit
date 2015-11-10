/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-11 16:02
# Filename:			b.cpp
# Description: 
=============================================================================*/
#include <cstdio>
#include <cstring>
char ch[9];
int main(){
    int a = 11, k, b = 0;
    while(scanf("%d", &k) && k){
        getchar();
        gets(ch);
        if(strcmp(ch, "too high") == 0)
            a = a < k ? a : k;
        if(strcmp(ch, "too low") == 0)
            b = b > k ? b : k;
        if(strcmp(ch, "right on") == 0){
            if(k <= b || k >= a)
                printf("Stan is dishonest\n");
            else if(a <= b)
                printf("Stan is dishonest\n");
            else
                printf("Stan may be honest\n");
            a = 11;
            b = 0;
        }
    }
    return 0;
}
