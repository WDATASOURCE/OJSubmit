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
#define maxn 10
using namespace std;

char ch[25];
char s[6];

int main(){
    int i, t;
    scanf("%d", &t);
    getchar();
    while(t--){
        scanf("%s", ch);
        for(i = 0; i < 5; i++)
            s[i] = ch[i];
        for(i = 5; i < 10; i++)
            ch[i - 5] = ch[i];
        ch[5] = '/';
        for(i = 6; i < 10; i++)
            ch[i] = s[i - 6];
        int h = (ch[11] - '0') * 10 + ch[12] - '0';
        if(h < 12)
            ch[19] = 'a', ch[20] = 'm';
        else
            ch[19] = 'p', ch[20] = 'm';
        if(h == 0)
            ch[11] = '1', ch[12] = '2';
        if(h > 12){
            int hh = h - 12;
            ch[11] = '0', ch[12] = hh + '0';
        }
        ch[21] = '\0';
        printf("%s\n", ch);
    }
    return 0;
}
