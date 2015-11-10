/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-16 21:17
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

map <string, int> mp;
 
int main(){
    int n, m, i, v;
    string s;
    while(scanf("%d", &n) != EOF){
        getchar();
        for(i = 0; i < n; i++){
            getline(cin, s);
            mp[s] = 0;
        }
        scanf("%d", &m);
        while(m--){
            for(i = 0; i < n; i++){
                scanf("%d ", &v);
                getline(cin, s);
                mp[s] += v;
            }
            map <string, int>::iterator it;
            int rate = 1;
            s = "Li Ming";
            int c = mp[s];
            for(it = mp.begin(); it != mp.end(); it++)
                if(it -> second > c)
                    rate++;
            printf("%d\n", rate);
        }
    }
    return 0;
}
