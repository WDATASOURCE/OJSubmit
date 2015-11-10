#include <cstdio>
#include <cstring>
#include <algorithm>
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

char ch1[110][40];
char ch2[110][40];

int dp[110][110];
char ans[110][40];

int main(){
    while(scanf(" %s", ch1[1]) != EOF){
        int dx = 2, dy = 1;
        while(strcmp(ch1[dx - 1], "#") != 0) scanf(" %s", ch1[dx++]);
        do{ scanf(" %s", ch2[dy++]);
        }while(strcmp(ch2[dy - 1], "#") != 0);

        dx--, dy--;
        int dd = 0;
        fill(dp[0], dp[110], 0);
        for(int i = 1; i < dx; i++)
            for(int j = 1; j < dy; j++){
                if(strcmp(ch1[i], ch2[j]) == 0){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if(dp[i][j] > dd) strcpy(ans[dd++], ch1[i]);
                }else dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
                if(dd < dp[i][j]) dd = dp[i][j];
            }
        //printf("%d\n", dp[dx - 1][dy - 1]);
        for(int i = 0; i < dd; i++)
            printf("%s%c", ans[i], i == dd - 1 ? '\n' : ' ');
    }
    return 0;
}
