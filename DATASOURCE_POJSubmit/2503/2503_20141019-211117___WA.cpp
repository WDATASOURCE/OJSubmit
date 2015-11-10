#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ls rt * 2 + 1                             // 左二子的下标;
#define rs rt * 2 + 2                             // 右儿子的下标; 
#define lson l, mid, rt * 2 + 1                   // 递归左二子;
#define rson mid, r, rt * 2 + 2                   // 递归右儿子;
#define M 1000010
using namespace std;

map <string, string> mp;

int main(){
    char str[20];
    char ch[20];
    char sh[20];
    string s1, s2;
    while(gets(str)){
        if(strlen(str) == 0)
            break;
        sscanf(str, "%s%s", ch, sh);
        s1 = ch;
        s2 = sh;
        mp[s2] = s1;
    }
    
    while(gets(ch)){
        s2 = ch;
        if(mp[s2].length() == 0)
            printf("eh\n");
        else printf("%s\n", mp[s2].c_str());
    }
    return 0;
}

