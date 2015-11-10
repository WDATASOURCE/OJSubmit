/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-11-02 14:26
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
#define E 2.718281828459045 
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

char ch[70];
int a[70];
int b[70];

int main(){  
    while(scanf("%s", ch) != EOF){
        int f = 0;
        int len = strlen(ch);
        int id = 0;
        for(int i = len - 1; i >= 0; i--)
            a[id++] = ch[i] - '0';
        int p = id;
        for(int j = 2; p == id && !f; j++){
            int s, c = 0;
            p = 0;
            for(int i = 0; i < 70; i++){
                s = a[i] * j + c;
                b[p++] = s % 10;
                c = s / 10;
            }
            while(!b[p])
                p--;
            p++;
            if(p == id){
                int c = 0, d = 0;
                while(b[c] != a[d] && c < id)
                    c++;
                if(c == id)
                    continue;
                else{
                    while(p != 0){
                        if(b[c % id] != a[d % id]){
                            f = 0;
                            break;
                        }
                        c++, d++;
                        p--;
                    }
                    if(p == 0)
                        f = 1;
                    p = id;
                }
            }
        }
        if(f)
            printf("%s is cyclic\n", ch);
        else
            printf("%s is not cyclic\n", ch);
    }
    return 0;
}   
