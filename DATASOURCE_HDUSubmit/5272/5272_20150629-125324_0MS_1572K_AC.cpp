/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-06-26 22:57
# Filename:         a.cpp
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

stack <int> sta;

int main(){
    int t;
    long long n;
    scanf("%d", &t);
    while(t--){
        scanf("%I64d", &n);
        //cerr <<"n = "<< n << endl;
        while(!sta.empty()) sta.pop();
        while(n){
            int t = n % 2;
            //cerr <<"t = "<< t << endl;
            sta.push(t);
            n /= 2;
        }

        int ans = 0;
        int a = 0;
        while(!sta.empty()){
            int t = sta.top();
            //cerr <<"t = "<< t << endl;
            sta.pop();
            if(!a && t) ans++;
            a = t;
        }
        printf ("%d\n", ans);
    }
    return 0;
}
