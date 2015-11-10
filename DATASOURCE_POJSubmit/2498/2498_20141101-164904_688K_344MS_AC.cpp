/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-11-01 12:23
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

char ch[10];
int a[] = {9, 3, 7};

int main(){
    int t;
    int id = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%s", ch);
        int len = strlen(ch);
        int sum = 0;
        int p;
        for(int i = len - 1; i >= 0; i--){
            if(ch[i] != '?')
                sum += (ch[i] - '0') * a[(len - i - 1) % 3];
            else p = i;
        }
        for(int i = 0; i < 10; i++){
            if(p == 0 && i == 0)
                continue;
            if((sum + i * a[(len - p - 1) % 3]) % 10 == 0){
                ch[p] = i + '0';
                break;
            }
        }
        printf("Scenario #%d:\n%s\n\n", ++id, ch);
    }
    return 0;
}
