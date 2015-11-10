/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-07-07 15:20
# Filename: 		c.cpp
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

map<string, int> ma;

int main(){
    char ch[20];
    ma.clear();
    while(scanf(" %s", ch) != EOF) ma[ch]++;
    map<string, int>::iterator iter = ma.begin();
    int num = 0;
    for(; iter != ma.end(); iter++){
        //cerr <<"iter -> first = "<< iter -> first <<", iter -> second = "<< iter -> second << endl;
        if((iter -> second) & 1) num++;
    }
    //cerr <<"num = "<< num << endl;
    if(num > 2) printf("Impossible\n");
    else printf("Possible\n");
    return 0;
}
