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

char ch[70][70];

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        fill(ch[0], ch[70], '0');
        int k = 0;
        int x = 0, y = 0;
        int j = n * m;
        while(k < j){
            while(y < m && k < j && ch[x][y] == '0') ch[x][y++] = 'A' + k++ % 26;
            y--, x++;
            while(x < n && k < j && ch[x][y] == '0') ch[x++][y] = 'A' + k++ % 26;
            x--, y--;
            while(y >= 0 && k < j && ch[x][y] == '0') ch[x][y--] = 'A' + k++ % 26;
            y++, x--;
            while(x >= 0 && k < j && ch[x][y] == '0') ch[x--][y] = 'A' + k++ % 26;
            x++, y++;
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                printf("%c", ch[i][j]);
                if(j == m - 1)
                    printf("\n");
                else
                    printf("   ");
            }
    }
    return 0;
}
