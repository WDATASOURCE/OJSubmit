/*=============================================================================
# Author:           He Shuwei
# Last modified:     2015-07-24 20:09
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
int mi, ma, len;
char ch[1000100];
int nxt[1000100];

void getNext(){
    int k = nxt[0] = -1;
    for(int i = 1; i < len; i++){
        while(k != -1 && ch[i] != ch[k + 1]) k = nxt[k];
        if(ch[i] == ch[k + 1]) k++;
        nxt[i] = k + 1;
    }
}

void MiDis(){
    int i = 0, j = 1;
    while(i < len && j < len){
        if(ch[i] < ch[j]) j++;
        else if(ch[i] > ch[j]) i = j, j++;
        else{
            int k = 1; 
            for(k = 1; ch[(i + k) % len] == ch[(j + k) % len] && k < len; k++);
            if(k == len) break;
            if(ch[(i + k) % len] > ch[(j + k) % len]) i = j, j++;
            else j = j + k + 1;
        }
    }
    mi = i + 1;
}

void MaDis(){
    int i = 0, j = 1;
    while(i < len && j < len){
        if(ch[i] > ch[j]) j++;
        else if(ch[i] < ch[j]) i = j, j++;
        else{
            int k = 1; 
            for(k = 1; ch[(i + k) % len] == ch[(j + k) % len] && k < len; k++);
            if(k == len) break;
            if(ch[(i + k) % len] < ch[(j + k) % len]) i = j, j++;
            else j = j + k + 1;
        }
    }
    ma = i + 1;
}
 
int main(){
    while(scanf("%s", ch) != EOF){
        len = strlen(ch);
        getNext();
        for(int i = 0; i < len; i++)
            cerr <<"i = "<< i <<", xnt[i] = "<< nxt[i] << endl;;
        MiDis();
        MaDis();
        int l = 1;
        if(len % (len - nxt[len - 1]) == 0) l = len / (len - nxt[len - 1]);
        printf("%d %d %d %d\n", mi, l, ma, l);
    }
    return 0;
}
