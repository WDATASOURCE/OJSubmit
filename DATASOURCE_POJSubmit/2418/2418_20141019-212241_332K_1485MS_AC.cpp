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

map <string, int> mp;

int main(){
    char str[36];
    int i = 0;
    string s1;
    while(gets(str) != NULL){
        i++;
        s1 = str;
        mp[s1]++;
    }
    map<string, int>::iterator ite;
    for(ite = mp.begin(); ite != mp.end(); ite++)
        printf("%s %.4f\n", ite -> first.c_str(), ite -> second /(i / 1.0) * 100);
    return 0;
}

