/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-10-03 14:37
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
map <string, int> ma;
map <string, int>::iterator iter;
char ch[MAXN];
int m, l;
 
int main(){
    while(~scanf("%d%d", &m, &l)){
        scanf(" %s", ch);
        int len = strlen(ch);
        int ans = 0;
        for(int i = 0; i < l; i++){
            ma.clear();
            int start = 0;
            if(i + m * l > len) break;
            for(int j = 0; ; j++){
                string str = "";
                //cerr <<"i = "<< i <<", j = "<< j << ", end = "<< i + j * l + l << endl;
                if(i + j * l + l > len) break;
                for(int k = i + j * l; k < i + j * l + l; k++)
                    str += ch[k];
                //cerr <<"i = "<< i <<", j = "<< j << endl;
                //cerr <<"str = "<< str << endl;
                //cerr << endl;
                iter = ma.find(str);
                if(iter != ma.end()){
                    int index = ma[str];
                    //cerr <<"i = "<< i <<", j = "<< j << ", index = "<< index << endl;
                    if(index < start){ 
                        ma.erase(iter);
                        if(j - start + 1 == m ){ 
                            ans++;
                            start++;
                        //cerr <<"i = " << i <<", j = "<< j << endl;
                        //cerr <<"id1 = "<< i + j * l + l << endl;;
                        }
                    }else {
                        start = index + 1;
                        ma[str] = j;
                    }
                }else{
                    ma[str] = j; 
                    if(j - start + 1 == m){
                        ans++;
                        start++;
                        //cerr <<"i = " << i <<", j = "<< j << endl;
                        //cerr <<"id2 = "<< i + j * l + l << endl;;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
