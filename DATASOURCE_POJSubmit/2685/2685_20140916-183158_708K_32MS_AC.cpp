/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-09-16 16:41
# Filename: 		b.cpp
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
using namespace std;
char ch1[10], ch2[10], ans[10];
char ch[4] = {'i', 'x', 'c', 'm'};
int data[26];
 
int main(){
    int i, j, t;
    data[12] = 1000;
    data[2] = 100;
    data[23] = 10;
    data[8] = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%s%s", ch1, ch2);
        int a = 0, b = 0;
        int t = 0;
        for(i = 0; ch1[i]; i++){
            if(ch1[i] >= '0' && ch1[i] <= '9'){
                t *= 10;
                t += ch1[i] - '0';
            }
            else{
                t = max(t * data[ch1[i] - 'a'], data[ch1[i] - 'a']);
                a += t;
                t = 0;
            }
        }
        t = 0;
        for(i = 0; ch2[i]; i++){
            if(ch2[i] >= '0' && ch2[i] <= '9'){
                t *= 10;
                t += ch2[i] - '0';
            }
            else{
                t = max(t * data[ch2[i] - 'a'], data[ch2[i] - 'a']);
                b += t;
                t = 0;
            }
        }
        a += b;
        j = 9;
        for(i = 0; i < 4; i++){
            if(a % 10){
                ans[j--] = ch[i];
                if(a % 10 != 1)
                    ans[j--] = a % 10 + '0';
            }
            a /= 10;
        }
        for(i = j + 1; i < 10; i++)
            printf("%c", ans[i]);
        printf("\n");
    }
    return 0;
}
