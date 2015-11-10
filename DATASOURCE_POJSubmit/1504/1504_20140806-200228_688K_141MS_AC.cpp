#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

char ch[10], s[10];

int main(){
    int i, k, t;
    scanf("%d", &t);
    while(t--){
        fill(ch, ch + 10, '0');
        fill(s, s + 10, '0');
        scanf("%s%s", ch, s);
        int len = strlen(ch);
        ch[len] = '0';
        len = strlen(s);
        s[len] = '0';
        int c = 0, ans;
        for(i = 0; i < 10; i++){
            ans = ch[i] - '0' + s[i] - '0' + c;
            ch[i] = ans % 10 + '0';
            c = ans / 10;
        }
        k = 0;
        i = 9;
        while(ch[i] == '0' && i >= 0)
            i--;
        while(ch[k] == '0' && k <= 9)
            k++;
        if(i == -1 && k == 10)
            printf("%c\n", '0');
        else{
            for(int j = k; j <= i; j++)
                printf("%c", ch[j]);
            printf("\n");
        }
    }
    return 0;
}
