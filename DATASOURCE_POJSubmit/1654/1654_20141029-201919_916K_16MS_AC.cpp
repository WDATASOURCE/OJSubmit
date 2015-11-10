/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-10-29 20:01
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
 
int dx[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1};

char s[1000005];

int main(){
	int T, x, y, i, dir;
	long long area;
	scanf("%d\n", &T);
    getchar();
	while(T--) {
		gets(s);
		x = y = 0;
		area = 0;
		for(i = 0; s[i]; i++){
			dir = s[i] - '1';
			area += x * dy[dir] - y * dx[dir];
			x += dx[dir];
			y += dy[dir];
		}
		if(area < 0) area = -area;
		if(area & 1) printf("%lld.5\n", area >> 1);
		else printf("%lld\n", area >> 1);
	}
	return 0;
}
