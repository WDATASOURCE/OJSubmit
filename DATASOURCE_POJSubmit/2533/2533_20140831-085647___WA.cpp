#include <cstdio>

int a[1005];
int b[1005];

int main(){
    int n, i, j, ma, ans;
    while(~scanf("%d", &n)){
        ans = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        b[0] = 1;
        ma = 0;
        for(i = 1; i < n; i++){                         // 每次求以第 i 个数的最长的上升字串的长度;
            ma = 0;                                     // 用于记录满足条件的, 第 j 个数左边的上升字串的最大长度;
            for(j = 0; j < i; j++)                      // 查看以第 j 个数的最长的上升字串;
                if(a[j] < a[i] && ma < b[j])
                    ma = b[j];
            b[i] = ma + 1;
            ans = ans > b[i] ? ans : b[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
