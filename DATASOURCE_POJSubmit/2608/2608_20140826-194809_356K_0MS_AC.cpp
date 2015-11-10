#include <cstdio>
#include <cstring>
char ch[25];

int main(){
    while(scanf("%s", ch) != EOF){
        int len = strlen(ch);
        int ans, l = 0;
        for(int i = 0; i < len; i++){
            switch(ch[i]){
                case 'B':
                case 'F':
                case 'P':
                case 'V': ans = 1;
                break;
                case 'C':
                case 'G':
                case 'J':
                case 'K':
                case 'Q':
                case 'S':
                case 'X':
                case 'Z': ans = 2;
                break;
                case 'D':
                case 'T': ans = 3;
                break;
                case 'L': ans = 4;
                break;
                case 'M':
                case 'N': ans = 5;
                break;
                case 'R': ans = 6;
                break;
                default: ans = 0;
            }
            if(ans == l || ans == 0){
                l = ans;
                continue;
            }
            else
            printf("%d", ans);
            l = ans;
        }
        printf("\n");
    }
    return 0;
}
