#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char str[100][100];

int main(){
    int cnt = 0;
    for(int i = 3;i <= 10;i++){
        for(int j = 0;j < i;j++){
            for(int k = 0;k < i;k++)
                str[j][k] = ' ';
            str[j][i] = 0;
        }
        for(int j = 0;j < i;j++){
            str[j][0] = 'a' + cnt;
            cnt = (cnt+1)%26;
        }
        for(int j = i-2;j > 0;j--){
            str[j][i-1-j] = 'a' + cnt;
            cnt = (cnt+1)%26;
        }
        for(int j = 0;j < i;j++){
            str[j][i-1] = 'a' + cnt;
            cnt = (cnt+1)%26;
        }
        for(int j = 0;j < i;j++)
            printf("%s\n",str[j]);
    }
    return 0;
}
