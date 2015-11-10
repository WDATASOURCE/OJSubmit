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

int a[100000];

inline int func(int n){
    int be = a[n - 1];
    int ans = be + (int)log10(n) + 1;
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int ans = 0;
        int i;
        a[0] = 0;
        for(i = 1; ;i++){
            a[i] = func(i);
            if(ans + a[i] > n) break;
            else ans += a[i];
        }
        int cha = n - ans;
        if(cha == 0) printf("%d\n", (i - 1) % 10);
        else{
            for(i = 1; ; i++) if(cha <= a[i]) break;
            cha = a[i] - cha;
            //cerr <<"cha = "<< cha << endl;
            if(cha == 0) printf("%d\n", i % 10);
            else{
                int aa = (int)log10(i) + 1;
                //cerr <<"aa = "<< aa <<", i = "<< i << endl;
                aa -= cha;
                //cerr <<"aa = "<< aa << endl;
                while(aa > 0) i /= 10, aa--;
                printf("%d\n", i % 10);
            }
        }
    }

    return 0;
}
