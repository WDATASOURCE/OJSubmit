#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char ch[100];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf(" %s", ch);
        int len = strlen(ch);
        for(int i = 0; i < len; i += 2){
            char c = ch[i];
            ch[i] = ch[i + 1];
            ch[i + 1] = c;
        }
        printf("%s\n", ch);
    }
    return 0;
}
