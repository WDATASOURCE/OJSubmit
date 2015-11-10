/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-11 23:45
# Filename: 		a.cpp
# Description: 
=============================================================================*/
 
#include <map>
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
#define lson l, mid, lp
#define rson mid, r, rp
#define lp (rt << 1) + 1
#define rp (rt << 1) + 2
#define e 2.718281828459045 
using namespace std;

char ch1[100];
char ch2[100];

int main(){
    while(scanf("%s%s", ch1, ch2) != EOF){
        int len1 = strlen(ch1);
        if(len1 == 1 && ch1[0] == 'E')
            break;
        int a1 = 0, a2 = 0;
        for(int i = 0; i < len1; i++){
            if((ch1[i] == 'R' && ch2[i] == 'S') || (ch1[i] == 'P' && ch2[i] == 'R') || (ch1[i] == 'S' && ch2[i] == 'P'))
                a1++;
            else if((ch2[i] == 'R' && ch1[i] == 'S') || (ch2[i] == 'P' && ch1[i] == 'R') || (ch2[i] == 'S' && ch1[i] == 'P'))
                a2++;
        }
        printf("P1: %d\nP2: %d\n", a1, a2);
    }
    return 0;
}
