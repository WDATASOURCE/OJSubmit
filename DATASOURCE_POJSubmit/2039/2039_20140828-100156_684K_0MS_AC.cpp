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

char ch[100][100];
char s[209];

int main(){
    int i, j, k, n;
    while(scanf("%d", &n) != EOF && n){
        getchar();
        scanf("%s", s);
        int a = 0, b = 0;
        k = 0;
        while(s[k]){
            while(s[k] && b < n)
                ch[a][b++] = s[k++];
            a++, b--;
            while(s[k] && b >= 0)
                ch[a][b--] = s[k++];
            if(b < 0)
                a++, b++;
        }
        for(j = 0; j < n; j++)
            for(i = 0; i < a; i++)
                printf("%c", ch[i][j]);
        printf("\n");
    }
    return 0;
}
