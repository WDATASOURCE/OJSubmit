/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-08-26 22:36
# Filename: 		c.cpp
# Description: 
=============================================================================*/

#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char ch[10005][15];

int main(){
    int i, j, t, n, f;
    scanf("%d", &t);
    getchar();
    while(t--){
        f = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%s", ch[i]);
        for(i = 0; i < n; i++){
            for(j = i + 1; j < n; j++){
                int len = strlen(ch[i]);
                if(strncmp(ch[i], ch[j], len) == 0){
                    f = 1;
                    break;
                }
                if(f)
                    break;
            }
            if(f)
                break;
        }
        if(f)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
    
