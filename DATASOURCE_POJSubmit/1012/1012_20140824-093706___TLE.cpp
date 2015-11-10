/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-08-24 08:56
# Filename: 		b.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int i, k, ans, j;
    while(scanf("%d", &k) != EOF && k){
        ans = k + 1;
        while(1){
            queue < int > q;
            for(i = 1; i <= 2 * k; i++)
                q.push(i);
            i = 0;
            while(1){
                j = q.front();
                if(++i % ans){
                    q.push(j);
                    q.pop();
                }
                else if(j <= k)
                    break;
                else q.pop();
            }
            //cerr << q.size() << endl;
            if(q.size() > k){
                if(ans % (2 * k))
                    ans++;
                else
                    ans += k + 1;
            }
            else
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
