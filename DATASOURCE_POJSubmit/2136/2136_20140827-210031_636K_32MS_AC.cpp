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

char ch[4][80];
int a[27];

int main(){
    int i, j;
    while(gets(ch[0]) != NULL){
        gets(ch[1]);
        gets(ch[2]);
        gets(ch[3]);
        fill(a, a + 27, 0);
        for(i = 0; i < 4; i++)
            for(j = 0; ch[i][j]; j++)
                if(ch[i][j] >= 'A' && ch[i][j] <= 'Z')
                    a[ch[i][j] - 'A']++;
        int mxp, mx = 0;
        for(i = 0; i < 26; i++)
            if(a[i] > mx){
                mx = a[i];
                mxp = i;
            }
        for(i = 0; i < 26; i++)
            a[i] = mx - a[i];
        int f = 1;
        while(f){
            j = 25;
            f = 0;
            while(a[j] > 0)
                j--;
            for(i = 0; i < 26; i++){
                if(i <= j){
                    if(a[i] > 0)
                        printf(" ");
                    else
                        printf("*");
                    if(i != j)
                        printf(" ");
                    else
                        printf("\n");
                }
                a[i]--;
            }
            if(a[mxp] != 0 - mx)
                f = 1;
        }
        for(i = 0; i < 26; i++){
            printf("%c", 'A' + i);
            if(i == 25)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}

