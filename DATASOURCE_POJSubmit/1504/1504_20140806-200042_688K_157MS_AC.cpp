#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

char ch[20], s[20];

int main(){
    int i, k, t;
    scanf("%d", &t);
    while(t--){
        fill(ch, ch + 20, '0');
        fill(s, s + 20, '0');
        scanf("%s%s", ch, s);
        int len = strlen(ch);
        ch[len] = '0';
        len = strlen(s);
        s[len] = '0';
        int c = 0, ans;
        for(i = 0; i < 20; i++){
            ans = ch[i] - '0' + s[i] - '0' + c;
            ch[i] = ans % 10 + '0';
            c = ans / 10;
        }
        k = 0;
        i = 19;
        while(ch[i] == '0' && i >= 0)
            i--;
        while(ch[k] == '0' && k <= 19)
            k++;
        if(i == -1 && k == 20)
            printf("%c\n", '0');
        else{
            for(int j = k; j <= i; j++)
                printf("%c", ch[j]);
            printf("\n");
        }
    }
    return 0;
}
