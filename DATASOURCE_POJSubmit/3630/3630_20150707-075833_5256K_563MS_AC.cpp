/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-07-07 07:32
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

string ch[100010];

int main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> ch[i];
        sort(ch, ch + n);
        int f = 1;
        for(int i = 0; i < n - 1; i++){
            int len = ch[i].size();
            int len1 = ch[i + 1].size();
            if(len > len1) continue;
            if(ch[i].compare(0, len, ch[i + 1], 0, len) == 0){
                //cerr << ch[i] <<"   "<< ch[i + 1] << endl;
                f = 0;
                break;
            }
        }
        if(f) printf("YES\n");
        else printf("NO\n");
    }
 
    return 0;
}
