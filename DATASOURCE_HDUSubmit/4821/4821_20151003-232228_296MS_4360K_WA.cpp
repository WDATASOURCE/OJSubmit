/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-10-03 22:10
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAXN = 100010;

char ch[MAXN];
int m, l;
unsigned long long base;
unsigned long long nbase[MAXN];
unsigned long long Hash[MAXN];
map <unsigned long long, int> ma;
 
int main(){
    base = 31;
    nbase[0] = 1;
    for(int i = 1; i < MAXN; i++)
        nbase[i] = nbase[i - 1] * base;
    while(scanf("%d%d", &m, &l) != EOF){
        scanf(" %s", ch);
        int ans = 0;
        int len = strlen(ch);


        Hash[len] = 0;
        for(int i = len - 1; i >= 0; i--)
            Hash[i] = Hash[i + 1] * base + ch[i] - 'a' + 1;
        //printf("%lld\n", Hash[0] - Hash[3] * nbase[3]);
        //printf("%lld\n", Hash[3] - Hash[6] * nbase[3]);

        
        //Hash[0] = ch[0] - 'a' + 1;
        //for(int i = 1; i < len; i++)
            //Hash[i] = Hash[i - 1] * base + ch[i] - 'a' + 1;
        //printf("%lld\n", Hash[3] - Hash[0] * nbase[3]);
        //printf("%lld\n", Hash[6] - Hash[3] * nbase[3]);


        for(int i = 0; i < l; i++){
            ma.clear();
            int start = 1;
            for(int j = 1; ; j++){
                if(i + j * l > len) break;
                //int hv = Hash[i + j * l] - Hash[i + j * l - l] * nbase[l];
                int hv = Hash[i + j * l - l] - Hash[i + j * l] * nbase[l];
                int index = ma[hv];
                if(index == 0){
                    ma[hv] = j;
                    if(j - start + 1 == m){
                        ans++;
                        start++;
                        //cerr <<"i = "<< i <<", j = "<< j <<", dx = "<< i + j * l << endl;
                    }
                }else{
                    //cerr <<"index = "<< index <<", start = "<< start << endl;
                    if(index < start){
                        ma.erase(index);
                        if(j - start + 1 == m){
                            ans++;
                            start++;
                        //cerr <<"i = "<< i <<", j = "<< j <<", dx1 = "<< i + j * l << endl;
                        }
                    }else{
                        start = index + 1;
                        ma[hv] = j;
                        if(j - start + 1 == m){
                            ans++;
                            start++;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

