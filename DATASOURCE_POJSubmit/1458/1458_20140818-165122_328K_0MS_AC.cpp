#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 210
using namespace std;

int mp[N][N];
char s1[N], s2[N];

int main(){
    int i, j;
    while(scanf("%s%s", s1, s2) != EOF){
        fill(mp[0], mp[N], 0);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        for(i = 1; i <= len1; i++)
        for(j = 1; j <= len2; j++)
        if(s1[i - 1] == s2[j - 1])
        mp[i][j] = mp[i - 1][j - 1] + 1;
        else
        mp[i][j] = max(mp[i - 1][j], mp[i][j - 1]);
        printf("%d\n", mp[len1][len2]);
    }
    return 0;
}
