/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-12-14 00:07
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
#define N 2010
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

char a[N];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)
            scanf(" %c", &a[i]);
        int s = 0, e = n - 1;
        int count = 0;
        while(s <= e){
            if(a[s] < a[e]) printf("%c", a[s++]), count++;
            else if(a[s] > a[e]) printf("%c", a[e--]), count++;
            else{
                int dx = s + 1;
                int dy = e - 1;
                while(dx < dy && a[dx] == a[dy]) dx++, dy--;
                if(a[dx] < a[dy]) printf("%c", a[s++]), count++;
                else printf("%c", a[e--]), count++;
            }
            if(count == 80) printf("\n"), count = 0;
            //cerr << 2 << endl;
        }
    }
    return 0;
}
