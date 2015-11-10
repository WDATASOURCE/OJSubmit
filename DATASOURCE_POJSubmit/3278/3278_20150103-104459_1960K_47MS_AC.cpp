/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2015-01-03 09:26
# Filename: 		a.cpp
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
#define N 200010
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;
const int MAX (1 << 30);

queue <int> qu;
int step[N];

void bfs(int s, int t, int di){
    step[s] = 0;
    if(s == t) return;
    qu.push(s);
    while(!qu.empty()){
        s = qu.front();
        qu.pop();
        if(s == t) break;
        int s1 = s + 1;
        int s2 = s - 1;
        int s3 = s * 2;
        if(s1 >= 0 && step[s1] > step[s] && s < t){
            step[s1] = step[s] + 1;
            qu.push(s1);
        }
        if(s2 >= 0 && step[s2] > step[s]){
            step[s2] = step[s] + 1;
            qu.push(s2);
        }
        if(s3 >= 0  && s3 < t * 2 && step[s3] > step[s]){
            step[s3] = step[s] + 1;
            qu.push(s3);
        }
    }
}

int main(){
    int s, t;
    //clock_t start = clock();
    while(scanf("%d%d", &s, &t) != EOF){
        fill(step, step + N, MAX);
        while(!qu.empty()) qu.pop();
        bfs(s, t, 0);
        printf("%d\n", step[t]);
    }
    //clock_t stop = clock();
    //cerr <<"time = "<< (double)(stop - start) <<"MS"<< endl;
    return 0;
}
