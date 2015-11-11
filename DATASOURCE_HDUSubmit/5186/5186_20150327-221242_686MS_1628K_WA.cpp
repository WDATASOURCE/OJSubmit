#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char ch[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'Z'};
map <char, int> maa;
char in[1000];
char ini[1009];
char ans[1000];
int n, b;

void add(){
    int len1 = strlen(ini);
    for(int i = len1 - 1; i >= 0; i--)
        in[len1 - 1 - i] = ini[i];
    for(int i = 0; i < len1; i++){
        int a = maa[in[i]];
        int ab = maa[ans[i]];
        int aa = (a + ab) % b;
        ans[i] = ch[aa];
    }
}
  
int main(){
    for(int i = 0; i < 36; i++)
        maa[ch[i]] = i;
    while(scanf("%d%d", &n, &b) != EOF){
        fill(ans, ans + 1000, '0');
        for(int i = 0; i < n; i++){
            scanf(" %s", ini);
            add();
        }
        int j = 1000 - 1;
        while(ans[j] == '0' && j >= 0) j--;
        if(j == -1){
            printf("0\n");
            continue;
        }
        ans[j + 1] = '\0';
        int i = 0;
        while(i < j) swap(ans[i++], ans[j--]);
        printf("%s\n", ans);
    }
    return 0;
}
