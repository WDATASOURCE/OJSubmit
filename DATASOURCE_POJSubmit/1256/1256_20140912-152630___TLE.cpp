/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-09-10 18:41
# Filename: 		c.cpp
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

char as[130];
char sa[60] = {"0AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"};
char ch[15];

void permutation(char *str,int length) {
    sort(str, str + length);     
    do{
        for(int i = 0; i < length; i++)
            printf("%c", sa[str[i] - '0']);
        printf("\n");
    }while(next_permutation(str, str + length));      
} 

int main() {
    int j = 1;
    int k = 2;
    for(int i = 0; i < 130; i++){
        if(i >= 65 && i <= 90)
            as[i] = j + '0', j += 2;
        else if(i >= 97 && i <= 122)
            as[i] = k + '0', k += 2;
        else as[i] = '$';
    }
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%s", ch);
        n = strlen(ch);
        for(int i = 0; i < n; i++)
            ch[i] = as[(int)ch[i]];
        permutation(ch, n);
    }
    return 0; 
}
