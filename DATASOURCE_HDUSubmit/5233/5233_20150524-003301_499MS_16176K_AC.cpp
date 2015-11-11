/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-05-23 00:31
# Filename:         b.cpp
# Description: 
=============================================================================*/
 
#include <set>
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
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

void read(int &x){
    x = 0;
    char ch = getchar();
    while(ch <= 32) ch = getchar();
    while(ch >= 48) x = x * 10 + ch - 48, ch = getchar();
}

void print(int x){
    if(x < 0){
        putchar('-');
        print(-x);
    }else if(x < 10) putchar('0' + x); else print(x / 10), print(x % 10);
}

int cnt[100500];
vector <int> vec[100500];
map <int, int> ma;
int mp[100500];

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < 100500; i++)
            vec[i].clear();
        ma.clear();
        int top = 1;
        for(int i = 1; i <= n; i++){
            read(mp[i]);
            if(ma.find(mp[i]) == ma.end()) ma[mp[i]] = top++;
        }
        for(int i = 1; i <= n; i++)
            vec[ma[mp[i]]].push_back(i);
        fill(cnt, cnt + 100500, 0);
        while(m--){
            int h;
            scanf("%d", &h);
            //cerr <<"h = "<< h << endl;
            h = ma[h];
            //cerr <<"h = "<< h << endl;
            if(h <= 0){
                puts("-1");
                continue;
            }
            if(cnt[h] >= vec[h].size()){
                puts("-1");
                continue;
            }
            print(vec[h][cnt[h]]);
            putchar('\n');
            cnt[h]++;
        }
    }
    return 0;
}
