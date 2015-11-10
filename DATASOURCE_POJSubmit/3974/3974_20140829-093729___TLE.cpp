/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-08-27 18:43
# Filename:			b.cpp
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

char ch[2000009];

int main(){
    int i, l, r, k = 0, ans;
    while(1){
        char c;
        int len = 0;
        ans = 0;
        ch[len++] = '#';
        while((c = getchar()) != '\n'){
            ch[len++] = c;
            ch[len++] = '#';
        }
        ch[len] = '\0';
        if(strcmp(ch, "#E#N#D#") == 0)
            break;
        for(i = 1; i < len - 1; i++){
            int sum = 1;
            l = i - 1;
            r = i + 1;
            while(l >= 0 && r < len){
                if(ch[l--] == ch[r++])
                    sum += 2;
                else break;
            }
            sum /= 2;
            ans = ans > sum ? ans : sum;
        }
        printf("Case %d: %d\n", ++k, ans);
    }
    return 0;
}
