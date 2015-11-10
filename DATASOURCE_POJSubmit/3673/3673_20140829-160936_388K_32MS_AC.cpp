#include <cstdio>
#include<cstring>
using namespace std;
char a[2][999];
int main() {
    int len1,len2,res;
    while(~scanf("%s%s", a[0], a[1])) {
            res=0;
            len1=strlen(a[0]);
            len2=strlen(a[1]);
            for(int i=0;i<len1;i++)
                for(int j=0;j<len2;j++)
                    res=res+(a[0][i] -0x30)*(a[1][j] -0x30);
            printf("%d\n", res);
        }
}
