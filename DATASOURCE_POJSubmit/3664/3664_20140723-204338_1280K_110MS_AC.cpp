#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#define N 50010

using namespace std;

struct ss{
    int data;
    int a, b;
};
ss s[N];
int n, k;

bool cmp1(ss a, ss b){
    return a.a > b.a;
}

bool cmp2(ss a, ss b){
    return a.b > b.b;
}

int main() {
    while(scanf("%d%d", &n, &k) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d %d", &s[i].a, &s[i].b);
            s[i].data = i + 1;
        }
        sort(s, s + n, cmp1);
        sort(s, s + k, cmp2);
        cout << s[0].data<< endl;
    }
	return 0;
}
