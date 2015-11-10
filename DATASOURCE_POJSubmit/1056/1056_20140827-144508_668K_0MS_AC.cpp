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

char ch[15][15];

int main(){
    int i, j, cnt, ans = 0;
    while(1){
        ans++;
        cnt = 0;
        int f = 0;
        while(1){
            if(scanf("%s", ch[cnt++]) == EOF)
                return 0;
            if(ch[cnt - 1][0] == '9')
                break;
        }
        for(i = 0; i < cnt; i++){
            for(j = i + 1; j < cnt; j++){
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
            printf("Set %d is not immediately decodable\n", ans);
        else
            printf("Set %d is immediately decodable\n", ans);
    }
    return 0;
}
    
