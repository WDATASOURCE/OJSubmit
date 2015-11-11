/*=============================================================================
# Author:            Datasource
# Last modified:     2015-10-03 22:10
# Filename:         4821.cpp
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

struct Hash{

    unsigned long long Base;
    unsigned long long nbase[MAXN];
    unsigned long long Has[MAXN];

    void init(char *s){
        Base = 131;
        nbase[0] = 1;
        Has[0] = 0;
        int len = strlen(s);
        for(int i = 1; i <= len; i++){
            nbase[i] = nbase[i - 1] * Base;
            Has[i] = Has[i - 1] * Base + s[i - 1] - 'a' + 1;
        }
    }

    unsigned long long getHash(int l, int r){
        return (Has[r] - Has[l] * nbase[r - l]);
    }
}_hash;

int m, l;
char ch[MAXN];
map <unsigned long long, int> ma;

int main(){
    while(scanf("%d%d", &m, &l) != EOF){
        scanf(" %s", ch);
        _hash.init(ch);
        int ans = 0;
        int len = strlen(ch);

        for(int i = 0; i < l; i++){
            ma.clear();
            if(i + m * l >= len) break;
            for(int j = i; j < i + m * l; j += l){
                unsigned long long hv = _hash.getHash(j, j + l);
                ma[hv]++;
            }
            if(ma.size() == m) ans++;
            for(int j = i + m * l; j + l <= len; j += l){
                unsigned long long behv = _hash.getHash(j - l * m, j - m * l + l);
                ma[behv]--;
                if(ma[behv] == 0) ma.erase(behv);
                unsigned long long hv = _hash.getHash(j, j + l);
                ma[hv]++;
                if(ma.size() == m) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
