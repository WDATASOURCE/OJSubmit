/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-10 20:49
# Filename:			b.cpp
# Description: 
=============================================================================*/
 
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char ch[22][3][22];
 
int main(){
    int l, n, i;
    while(scanf("%d%d", &l, &n) != EOF){
        int f = 0;
        char s[25];
        for(i = 0; i < l; i++)
            scanf("%s %s", ch[i][0], ch[i][1]);
        while(n--){
            f = 0;
            scanf("%s", s);
            for(i = 0; i < l; i++)
                if(strcmp(ch[i][0], s) == 0){
                    printf("%s\n", ch[i][1]);
                    f = 1;
                    break;
                }
            if(f == 1)
                continue;
            int len = strlen(s);
            if(s[len - 1] == 'y' && s[len - 2] != 'a' && s[len - 2] != 'e' && s[len - 2] != 'i' && s[len - 2] != 'o' && s[len - 2] != 'u'){
                s[len - 1] = 'i';
                s[len] = 'e';
                s[len + 1] = 's';
                s[len + 2] = '\0';
            }
            else if(s[len - 1] == 'o' || s[len - 1] == 's' || (s[len - 2] == 'c' && s[len - 1] == 'h') || (s[len - 2] == 's' && s[len - 1] == 'h') || s[len - 1] == 'x'){
                s[len] = 'e';
                s[len + 1] = 's';
                s[len + 2] = '\0';
            }
            else{
                s[len] = 's';
                s[len + 1] = '\0';
            }
            printf("%s\n", s);
        }
    }
    return 0;
}
