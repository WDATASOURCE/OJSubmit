/*=============================================================================
# Author:			He Shuwei
# Last modified:	2014-09-17 16:56
# Filename:			b.cpp
# Description: 
=============================================================================*/

#include <map>
#include <ctime>
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
char ch[600000];

void solute(int l, int r){
    if(r - l < 3)
        return;
    int i, mid = (l + r) / 2;
    int count = (r - l - 1) / 3;
    for(i = 0; i <= count / 2; i++){
        ch[mid + i] = ch[mid - i] = ' ';
    }
    solute(l, mid - i + 1);
    solute(mid + i, r);
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int l = 0;
        int r = (int)pow(3.0, n);
        fill(ch, ch + r + 1, '-');
        ch[r] = '\0';
        solute(l, r);
        printf("%s\n", ch);
    }
    return 0;
}
