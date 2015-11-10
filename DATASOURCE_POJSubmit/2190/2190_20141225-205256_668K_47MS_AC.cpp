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
#define N 3010 
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
using namespace std;

char ch[20];

int main(){
    while(scanf("%s", ch) != EOF){
        int p = 0;
        int sum = 0;
        for(int i = 0; i < 10; i++){
            if(ch[i] == '?') p = i;
            else if(ch[i] == 'X') sum += 10 * (10 - i);
            else sum += (ch[i] - '0') * (10 - i);
        }
        //cerr <<"sum = "<< sum <<" p = "<< p << endl;
        int f = 0;
        int m = (p == 9 ? 10 : 9);
        for(int i = 0; i <= m; i++){
            if((sum + (10 - p) * i) % 11 == 0){
                if(i < 10) printf("%d\n", i);
                else printf("X\n");
                f = 1;
                break;
            }
        }
        if(!f) printf("-1\n");
    }
	return 0;
}
