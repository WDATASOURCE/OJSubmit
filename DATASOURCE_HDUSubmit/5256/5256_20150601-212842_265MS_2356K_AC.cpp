/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-05-31 14:18
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
using namespace std;
 
const int maxn=100050;
int arr[maxn],dp[maxn];
int n;

int LIS()
{
    dp[1]=arr[1];
    int i,j,low,high,mid,len=1;
    for(i=2;i<=n;++i)
    {
        low=1;high=len;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(arr[i]>=dp[mid])
            low=mid+1;
            else
            high=mid-1;
        }
        dp[low]=arr[i];
        if(low>len)
        len++;
    }
    return len;
}

int main()
{
    int i,j;
    int t;
    scanf("%d", &t);
    int xx = 0;
    while(t--)
    {
        xx++;
        scanf("%d", &n);
        for(i=1;i<=n;++i)
        {
            scanf("%d",&arr[i]);
            arr[i] -= i;
        }
        int a=LIS();
        int res = n-a;
        printf("Case #%d:\n%d\n", xx, res);
    }    
    return 0;
}