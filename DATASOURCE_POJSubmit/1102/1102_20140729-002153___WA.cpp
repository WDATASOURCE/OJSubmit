#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

int s;
char ch[11];
char num[10][5][4] = {{" - ","| |","   ","| |"," - "},{"   ","  |","   ","  |","   "},{" - ","  |"," - ","|  "," - "},
    {" - ","  |"," - ","  |"," - "},{"   ","| |"," - ","  |","   "},{" - ","|  "," - ","  |"," - "},
    {" - ","|  "," - ","| |"," - "},{" - ","  |","   ","  |","   "},{" - ","| |"," - ","| |"," - "},
    {" - ","| |"," - ","  |"," - "}};

void solute(){
    int i, j = 0, k, l, m;
    int len = strlen(ch);
    for(i = 0; i < 5; i++){
        if(i == 1 || i == 3){
            for(m = 1; m < s; m++){
                for(j = 0; j < len; j++){
                    for(k = 0; k < 4; k++){
                        if(k == 1)
                            for(l = 1; l < s; l++)
                                printf("%c", num[ch[j] - '0'][i][k]);
                        printf("%c", num[ch[j] - '0'][i][k]);
                    }
                    printf("%c",' ');
                }
                printf("\n");
            }
        }
        for(j = 0; j < len; j++){
            for(k = 0; k < 4; k++){
                if(k == 1)
                    for(l = 1; l < s; l++)
                        printf("%c", num[ch[j] - '0'][i][k]);
                printf("%c", num[ch[j] - '0'][i][k]);
            }
            printf("%c",' ');
        }
        printf("\n");
    }
}

int main(){
    while(scanf("%d", &s)){
        cin >> ch;
        if(s == 0)
            break;
        solute();
        printf("\n");
    }
    printf("\n");
    return 0;
}
