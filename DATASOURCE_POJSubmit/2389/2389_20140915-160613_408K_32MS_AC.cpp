#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[60], b[60];
char ch1[60], ch2[60];
int ans[100];

int main(){
    int i, j;
    while(scanf("%s%s",ch1, ch2) != EOF){
        fill(a, a + 60, 0);
        fill(b, b + 60, 0);
        fill(ans, ans + 100, 0);
        int len1 = strlen(ch1);
        int len2 = strlen(ch2);
        int l = 0;
        int k = 0;
        for(i = len1 - 1; i >= 0; i--)
            a[l++] = ch1[i] - '0';
        for(i = len2 - 1; i >= 0; i--)
            b[k++] = ch2[i] - '0';
        for(i = 0; i < k; i++){
            int s, e = 0;
            int m = i;    
            for(j = 0; j < l; j++){
                s = b[i] * a[j] + e;
                ans[m++] += (s % 10);
                e = s / 10;
            }
            ans[m++] += e;
        }
        int e = 0;
        for(i = 0; i < 100; i++){
            ans[i] += e;
            e = ans[i] / 10;
            ans[i] %= 10;
        }
        j = 99;
        while(!ans[j])
        j--;
        for(i = j; i >= 0; i--)
        printf("%d", ans[i]);
        printf("\n");
    }
}
