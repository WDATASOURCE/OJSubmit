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

/*
void getNext(){
    int k = nxt[0] = -1;
    for(int i = 1; i < len; i++){
        if(k != -1 && ch[i] != ch[k + 1]) k = nxt[k];
        if(ch[i] == ch[k + 1]) k++;
        nxt[i] = k + 1;
    }
}
*/

void getNext()
{
 int i=0,j=-1;
 nxt[0]=-1;
 while (i<len)
 {
     if (j==-1||ch[i]==ch[j])
     {
         i++;
         j++;
         nxt[i]=j;
     }
     else j=nxt[j];
 }
}

void MiDis(){

    /*
    char * str = ch;
    int n = len;
    int p = 0, q = 1;
    while (p < n && q < n) {
        if (str[p] < str[q]) {
            q++;
        } else if (str[p] > str[q]) {
            p = q;
            q++;
        } else {
            int i, l = p, r = q;
            for (i = 0; i < n; i++) {
                int ll = l % n, rr = r % n;
                if (str[ll] < str[rr]) {
                    q = r;
                    break;
                } else if (str[ll] > str[rr]) {
                    p = q;
                    q = rr;
                    break;
                }
                l++; r++;
            }
            if (i == n) {
                break;
            }
        }
    }
    mi = p + 1;
    //return p;
    */

       int i = 0, j = 1, k;
       while(i < len && j < len){
           if(ch[i] < ch[j]) j++;
           else if(ch[i] > ch[j]) i = j, j++;
           else{
               for(k = 1; ch[(i + k) % len] == ch[(j + k) % len] && k < len; k++);
               if(k == len) break;
               if(ch[(i + k) % len] > ch[(j + k) % len]) i = i + k + 1;
               else j = j + k + 1;
               if(i == j) j++;
           }
       }
       mi = i + 1;
}

void MaDis(){
    /*
    char * str = ch;
    int n = len;
    int p = 0, q = 1;
    while (p < n && q < n) {
        if (str[p] > str[q]) {
            q++;
        } else if (str[p] < str[q]) {
            p = q;
            q++;
        } else {
            int i, l = p, r = q;
            for (i = 0; i < n; i++) {
                int ll = l % n, rr = r % n;
                if (str[ll] > str[rr]) {
                    q = r;
                    break;
                } else if (str[ll] < str[rr]) {
                    p = q;
                    q = rr;
                    break;
                }
                l++; r++;
            }
            if (i == n) {
                break;
            }
        }
    }
    ma = p + 1;
    */



       int i = 0, j = 1, k;
       while(i < len && j < len){
           if(ch[i] > ch[j]) j++;
           else if(ch[i] < ch[j]) i = j, j++;
           else{
               for(k = 1; ch[(i + k) % len] == ch[(j + k) % len] && k < len; k++);
               if(k == len) break;
               if(ch[(i + k) % len] < ch[(j + k) % len]) i = i + k + 1;
               else j = j + k + 1;
               if(i == j) j++;
           }
       }
       ma = i + 1;
}

int main(){
    while(scanf("%s", ch) != EOF){
        len = strlen(ch);
        getNext();
        MiDis();
        MaDis();
        //for(int i = 0; i <= len; i++)
            //cerr <<"i = "<< i <<", nxt[i] = "<< nxt[i] << endl;
        int l = 1;
        if(len % (len - nxt[len]) == 0) l = len / (len - nxt[len]);
        printf("%d %d %d %d\n", mi, l, ma, l);
    }
    return 0;
}
