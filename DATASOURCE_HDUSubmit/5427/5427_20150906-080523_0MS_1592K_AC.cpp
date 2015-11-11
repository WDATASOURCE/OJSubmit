/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-09-06 07:59
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

struct People{
    char ch[100];
    int age;

    friend bool operator < (const People &a, const People &b){
        return a.age > b.age;
    }
}a[110];
 
int main(){
    int t;
    scanf("%d", &t);
    getchar();
    while(t--){
        int n;
        scanf("%d", &n);
        getchar();
        for(int i = 0; i < n; i++)
            gets(a[i].ch);

        for(int i = 0; i < n; i++){
            int len = strlen(a[i].ch);
            a[i].age = 0;
            a[i].age = (a[i].ch[len - 4] - '0') * 1000 + (a[i].ch[len - 3] - '0') * 100 + (a[i].ch[len - 2] - '0') * 10 + (a[i].ch[len - 1] - '0');
            a[i].ch[len - 5] = '\0';
        }

        sort(a, a + n);
        for(int i = 0; i < n; i++)
            puts(a[i].ch);
    }
    return 0;
}
