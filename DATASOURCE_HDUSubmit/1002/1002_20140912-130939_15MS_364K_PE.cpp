/*=============================================================================
# Author:            He Shuwei
# Last modified:     2014-09-10 18:41
# Filename:         c.cpp
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
#define M (1 << 30)
using namespace std;

char c[1005], d[1005];
int a[1005], b[1005];

int main() {
    int t, di = 0;
    cin >> t;
    while(t--){
        for(int i = 0; i < 1005; i++)
            a[i] = 0, b[i] = 0;
        int j = 0, k = 0;
        cin >> c >> d;
        int len1 = strlen(c);
        int len2 = strlen(d);
        for(int i = len1 - 1; i >= 0; i--)
            a[j++] = c[i] - '0';
        for(int i = len2 - 1; i >= 0; i--)
            b[k++] = d[i] - '0';
        int s, e = 0;
        for(int i = 0; i < 1005; i++){
            s = a[i] + b[i] + e;
            a[i] = s % 10;
            e = s / 10;
        }
        j = 1004;
        while(!a[j])
            j--;
        cout << "Case " << ++di <<":"<< endl;
        cout << c <<" + "<< d <<" = ";
        for(int i = j; i >= 0; i--)
            cout << a[i];
        cout << endl << endl;
    }
    return 0; 
}
