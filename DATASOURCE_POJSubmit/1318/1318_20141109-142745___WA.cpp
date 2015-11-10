/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-11-09 13:29
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
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

char ch[110][100];
int len[110];

int main(){
    int id = 0;
    while(scanf("%s", ch[id]) != EOF){
        len[id] = strlen(ch[id]);
        id++;
        do{
            scanf("%s", ch[id]);
            len[id] = strlen(ch[id]);
            id++;
        }
        while(strcmp(ch[id - 1], "XXXXXX") != 0);
        id--;
        char s[100];
        int t;
        for(int i = 0; i < id; i++)
            for(int j = i + 1; j < id; j++)
                if(strcmp(ch[i], ch[j]) > 0){
                    strcpy(s, ch[i]);
                    t = len[i];
                    strcpy(ch[i], ch[j]);
                    len[i] = len[j];
                    strcpy(ch[j], s);
                    len[j] = t;
                }
        while(1){
            scanf("%s", s);
            if(strcmp(s, "XXXXXX") == 0)
                break;
            bool aa[100];
            int lens = strlen(s);
            bool f = true;
            for(int i = 0; i < id; i++){
                if(len[i] == lens){
                    bool ff = false;
                    fill(aa, aa + 100, false);
                    for(int j = 0; j < lens; j++)
                        aa[ch[i][j] - 'a'] = true;
                    for(int j = 0; j < lens; j++)
                        if(!aa[s[j] - 'a']){
                            ff = true;
                            break;
                        }
                    if(!ff){
                        f = false;
                        printf("%s\n", ch[i]);
                    }
                }
            }
            if(f)
                printf("NOT A VALID WORD\n");
            printf("******\n");
        }
    }
    return 0;
}
