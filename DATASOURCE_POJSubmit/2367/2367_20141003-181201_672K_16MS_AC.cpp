/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-03 17:07
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
#define M 110
using namespace std;

vector <int> vec[M];
int ingree[M];
int ans[M];
int n;

bool TOSort(){
    int i, j;
    int top = -1;
    int count = 0;
    fill(ingree, ingree + M, 0);
    for(i = 1; i <= n; i++){
        int end = vec[i].size();
        for(j = 0; j < end; j++)
            ingree[vec[i][j]]++;
    }
    for(i = 1; i <= n; i++)
        if(ingree[i] == 0){
            ingree[i] = top;
            top = i;
        }
    while(top != -1){
        int t = top;
        top = ingree[t];
        ans[count++] = t;
        int end = vec[t].size();
        for(i = 0; i < end; i++){
            ingree[vec[t][i]]--;
            if(ingree[vec[t][i]] == 0){
                ingree[vec[t][i]] = top;
                top = vec[t][i];
            }
        }
    }
    if(count < n)
        return false;
    return true;
}
 
int main(){
    int i, v;
    while(scanf("%d", &n) != EOF){
        for(i = 1; i <= n; i++){
            while(1){
                scanf("%d", &v);
                if(v == 0)
                    break;
                else
                    vec[i].push_back(v);
            }
        }
        TOSort();
        for(i = 0; i < n; i++)
            printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}























/*
#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
#include<cstring>
#define M 110
using namespace std ;

int in[M] , p[M] ; 
queue<int>q ;
vector<int>qe[M] ;
bool vi[M] ; // 有些 点可能没有 进入 关系网
int main(){
    int i, j, n, m, mun, h;
    while(scanf("%d", &n) != EOF){
        for(i = 1; i <= n; i++)
            qe[i].clear(); 
        mun = 0;
        h = 1;
        while(!q.empty())
            q.pop() ;
        fill(vi, vi + M, false);
        for(i = 1; i <= n; i++){
            while(1){
                scanf("%d", &m);
                if(m == 0) break;
                qe[m].push_back(i);
                in[i]++;
            }   
        }
        for(i = 1; i <= n; i++)
            if(in[i] == 0){
                p[h++] = i;//找出 没有 儿子的点 加入队列
                q.push(i);
                vi[i] = 1;
                mun++; 
            }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(i = 0; i < qe[f].size(); i++)
                if(--in[qe[f][i]] == 0){   // 删除和f 相连的边 
                    p[h++] = qe[f][i];
                    q.push(qe[f][i]); 
                    vi[qe[f][i]] = 1;
                    mun++;
                }
        }
        if(mun == n){
            for(i = h - 1; i > 1; i--)
                cout << p[i] << " " ;
            cout << p[1] << endl; 
        }
        else {
            for( i = 1 ;i <= n ;i++)
                if( vi[i] == 0 )
                    cout << i << " " ;
            for( i = h - 1 ; i > 1 ;i-- )
                cout << p[i] << " " ;
            cout << p[1] << endl ;

        }
    }
}
*/
