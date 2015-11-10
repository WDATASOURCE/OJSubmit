/*=============================================================================
# Author: He Shuwei
# Last modified:	2014-08-10 18:44
# Filename:		b.cpp
# Description: 
=============================================================================*/
 
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
    int n,m,p,c;
    while(scanf("%d%d%d%d",&n,&m,&p,&c)&&n&&m&&p&&c){
        if(p>m)
            printf("%d\n",p-m+n);
        else
            printf("%d\n",n+p-m);
    }

    return 0;
}
