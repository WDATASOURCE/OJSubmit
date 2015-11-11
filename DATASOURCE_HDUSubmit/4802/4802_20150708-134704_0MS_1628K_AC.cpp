/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-08 08:54
# Filename:         b.cpp
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
#include <iomanip>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

map<string, double> ma;

void init(){
    ma["A"] = 4.0;
    ma["A-"] = 3.7;
    ma["B+"] = 3.3;
    ma["B"] = 3.0;
    ma["B-"] = 2.7;
    ma["C+"] = 2.3;
    ma["C"] = 2.0;
    ma["C-"] = 1.7;
    ma["D"] = 1.3;
    ma["D-"] = 1.0;
    ma["F"] = 0.0;
    ma["p"] = 0.0;
    ma["N"] = 0.0;
}
 
int main(){
    int n;
    init();
    while(scanf("%d", &n) != EOF){
        int v;
        double ans = 0;
        string ch;
        char str[10];
        double sum = 0.0;
        double suc = 0.0;
        for(int i = 0; i < n; i++){
            scanf("%d %s", &v, str);
            //cerr <<"v = "<< v <<", str = "<< str << endl;
            ch = str;
            if(ch.compare("P") == 0 || ch.compare("N") == 0) continue;
            sum += (v * ma[ch]);
            suc += v;
        }
        //cerr <<"suc = "<< suc << endl;
        if(suc == 0) printf("0.00\n");
        else{
            ans = sum / suc; printf("%.2lf\n", ans);
        }
    }
    return 0;
}