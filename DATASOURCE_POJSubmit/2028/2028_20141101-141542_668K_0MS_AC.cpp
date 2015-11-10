/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-11-01 12:23
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
#define nMax 110
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

int hash[nMax];
int N,Q;

int main() {
	int m;
	int date;
	while (1) {
		scanf("%d %d", &N, &Q);
		if (N == 0 && Q == 0)
			break;
        fill(hash, hash + nMax, 0);
		for (int i = 0; i < N; ++ i) {
			scanf("%d", &m);
			for (int j = 0; j < m; ++ j) {
				scanf("%d", &date);
				hash[date] ++;
			}
		}
		int max = -1, k;
		for (int i = 0; i < nMax; ++ i) {
			if (max < hash[i]) {
				k = i;
				max = hash[i];
			}
		}
		if (max < Q)
			printf("0\n");
		else
			printf("%d\n", k);
	}
	return 0;
}
