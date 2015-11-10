/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-01 20:46
# Filename: 		b.cpp
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
using namespace std;

struct let{
    char ch[100];
    int a;
};

let a[110];
 
int main(){
    int n, m, i;
    while(scanf("%d%d", &n, &m) != EOF){
        getchar();
        for(i = 0; i < m; i++)
            scanf("%s", a[i].ch);
        for(i = 0; i < m; i++){
            int sum = 0;
            for(int j = 0; j < n; j++)
                for(int k = j + 1; k < n; k++)
                    if(a[i].ch[j] > a[i].ch[k])
                        sum++;
            a[i].a = sum;
        }
        let t;
        for(int i = 0; i < m; i++)
            for(int j = i + 1; j < m; j++)
                if(a[i].a > a[j].a){
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
        for(i = 0; i < m; i++)
            printf("%s\n", a[i].ch);
    }
    return 0;
}
