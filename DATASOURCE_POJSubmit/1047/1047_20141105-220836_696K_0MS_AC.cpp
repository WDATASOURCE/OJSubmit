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

char ch[8][100] = {"142857", "0588235294117647", "052631578947368421", "0434782608695652173913", "0344827586206896551724137931", "0212765957446808510638297872340425531914893617", "0169491525423728813559322033898305084745762711864406779661", "016393442622950819672131147540983606557377049180327868852459"};
char s[100];

int main(){  
    while(scanf("%s", s) != EOF){
        int f = 0;
        for(int i = 0; i < 8; i++){
            if(strcmp(ch[i], s) == 0){
                f = 1;
                break;
            }
        }
        if(f) printf("%s is cyclic\n", s);
        else printf("%s is not cyclic\n", s);
    }
    return 0;
}   
