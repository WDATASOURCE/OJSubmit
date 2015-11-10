/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-09-17 16:56
# Filename:			b.cpp
# Description: 
=============================================================================*/

#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char ch[100000010];

int func(){
    int i;
    int f = 1;
    int len = strlen(ch);
    for(i = 1; i <= len; i++){
        if(len % i)
            continue;
        f = 1;
        for(int j = i; j < len; j++){
            if(ch[j] != ch[j % i]){
                f = 0;
                break;
            }
        }
        if(f)
            return i;
    }
}

int main(){
    while(scanf("%s", ch) != EOF){
        int len = strlen(ch);
        if(len == 1 && ch[0] == '.')
            break;
        int l = func();
        printf("%d\n", len / l);
    }
    return 0;
}
