/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-06-26 22:57
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
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int sn = 0;
        int be = 0;
        int tt = 1;
        int f = 1;
        while(sn < n && f){
            be++;
            tt = 1;
            while(tt <= be){ 
                sn += (int)log10(tt) + 1; 
                if(sn >= n){f = 0; break;}
                tt++;
            }
        }
        int cha = sn - n;
        //cerr <<"cha = "<< cha << endl;
        if(cha >= 1) while(cha--) tt /= 10;
        printf("%d\n", tt % 10);
    }
    return 0;
}
