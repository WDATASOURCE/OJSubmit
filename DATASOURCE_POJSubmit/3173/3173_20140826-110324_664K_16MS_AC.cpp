/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-08-26 10:53
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
#define M (1 << 30)
using namespace std;
char ch[21][21];

int main(){
    int i, j;
    int n, s;
    while(scanf("%d%d", &n, &s) != EOF){
        fill(ch[0], ch[21], ' ');
        for(j = 0; j < n; j++)
            for(i = 0; i <= j; i++){
                s %= 9; 
                if(s == 0)
                    s = 9;
                ch[i][j] = s + '0';
                s++;
            }
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++){
                printf("%c", ch[i][j]);
                if(j == n - 1)
                    printf("\n");
                else
                    printf(" ");
            }
    }
    return 0;
}
