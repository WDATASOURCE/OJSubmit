/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-10 20:49
# Filename:			b.cpp
# Description: 
=============================================================================*/
 
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char ch[12];
 
int main(){
    int i, t;
    scanf("%d", &t);
    while(t--){
        ch[0] = '0';
        scanf("%s", ch + 1);
        int len = strlen(ch);
        if(len == 2){
            printf("%s\n", ch + 1);
            continue;
        }
        int s, c = 0;
        for(i = len - 1; i >= 0; i--){
            s = ch[i] - '0' + c;
            if((s >= 5 && i != 1) || (s == 10)){
                ch[i] = '0';
                c = 1;
            }
            else if(i != 1 && i != 0){
                ch[i] = '0';
                c = 0;
            }
            else{
                ch[i] = s + '0';
                c = 0;
            }
        }
        c = 0;
        while(ch[c] == '0')
            c++;
        printf("%s\n", ch + c);
    }
    return 0;
}
