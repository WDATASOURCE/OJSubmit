/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-07-24 08:28
# Filename:         a.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <set>
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

int n;
set <string> se;
char ch[10010][110];

void change(int dx){
    int len = strlen(ch[dx]);
    int i = 0, j = 1;
    while(i < len && j < len){
        if(ch[dx][i] < ch[dx][j]) j++;
        else if(ch[dx][i] > ch[dx][j]) i = j, j++;
        else{
            int k = 1; 
            for(k = 1; k < len && ch[dx][(i + k) % len] == ch[dx][(j + k) % len]; k++);
            if(k == len) break;
            if(ch[dx][(i + k) % len] > ch[dx][(j + k) % len]) i = j, j++;
            else j = j + k + 1;
        }
    }
    char str[110];
    str[len] = '\0';
    for(int k = 0; k < len; k++){
        str[k] = ch[dx][(k + i) % len];
    }
    strcpy(ch[dx], str);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    while(cin >> n){
        se.clear();
        for(int i = 0; i < n; i++)
            cin >> ch[i];
        for(int i = 0; i < n; i++)
            change(i);
        string str;
        for(int i = 0; i < n; i++){
            str = ch[i];
            se.insert(str);
        }
        cout << se.size() << endl;
    }
    return 0;
}
