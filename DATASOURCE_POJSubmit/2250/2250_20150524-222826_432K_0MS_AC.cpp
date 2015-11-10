#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

char ch1[110][40];
char ch2[110][40];

int dp[110][110];
int path[110][110];

void print(int dx, int dy){
    if(!dx || !dy) return;
    if(path[dx][dy] == 1){
        print(dx - 1, dy - 1);
        printf("%s ", ch1[dx]);
    }else if(path[dx][dy] == 2) print(dx - 1, dy);
    else print(dx, dy - 1);
}

int main(){
    while(scanf(" %s", ch1[1]) != EOF){
        int dx = 2, dy = 1;
        while(strcmp(ch1[dx - 1], "#") != 0) scanf(" %s", ch1[dx++]);
        do{ scanf(" %s", ch2[dy++]);
        }while(strcmp(ch2[dy - 1], "#") != 0);
        dx--, dy--;
        fill(dp[0], dp[110], 0);
        for(int i = 1; i < dx; i++)
            for(int j = 1; j < dy; j++){
                if(strcmp(ch1[i], ch2[j]) == 0){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    path[i][j] = 1;
                }else{ 
                    if(dp[i - 1][j] >= dp[i][j - 1]){
                        dp[i][j] = dp[i - 1][j];
                        path[i][j] = 2;
                    }else{
                        dp[i][j] = dp[i][j - 1];
                        path[i][j] = 3;
                    }
                }
            }
        print(dx - 1, dy - 1);
        printf("\n");
    }
    return 0;
}
