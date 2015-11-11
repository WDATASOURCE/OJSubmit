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
char ch[MAXN];
char str[MAXN];
int m, l;

struct Node{
    short p[26];
    int value;
    Node(){
        for(int i = 0; i < 26; i++) p[i] = 0;
        value = 0;
    }
};

Node node[565560];
int tot;                    // ¼ÇÂ¼ node ÖÐµÄ±àºÅ

void init(){
    tot = 1;
    memset(node, 0, sizeof(node));
}

int insertTree(char *ch, int v){
    int cur = 0;
    for(int i = 0; ch[i]; i++){
        if(node[cur].p[ch[i] - 'a'] == 0) node[cur].p[ch[i] - 'a'] = tot++; 
        cur = node[cur].p[ch[i] - 'a'];
    }
    int res = 0;
    if(node[cur].value == 0){
        node[cur].value = v;
    }else{ 
        res = node[cur].value;
        node[cur].value = v;
    }
    return res;
}
 
int main(){
    while(~scanf("%d%d", &m, &l)){
        scanf(" %s", ch);
        int len = strlen(ch);
        int ans = 0;
        for(int i = 0; i < l; i++){
            init();
            int start = 1;
            for(int j = 1; ; j++){
                if(i + j * l > len) break;
                int dx = 0;
                for(int k = i + j * l - l; k < i + j * l; k++)
                    str[dx++] = ch[k];
                str[dx] = '\0';
                int iter = insertTree(str, j);
                if(iter){
                    int index = iter;
                    //cerr <<"i = "<< i <<", j = "<< j << ", index = "<< index << endl;
                    if(index < start){ 
                        insertTree(str, 0);
                        if(j - start + 1 == m ){ 
                            ans++;
                            start++;
                        //cerr <<"i = " << i <<", j = "<< j << endl;
                        //cerr <<"id1 = "<< i + j * l + l << endl;;
                        }
                    }else {
                        start = index + 1;
                    }
                }else{
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

