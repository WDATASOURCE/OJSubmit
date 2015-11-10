#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#define M 300
using namespace std;

char ch[M];

int main(){
    int i, j;
    while(1){
        cin.getline(ch, M);
        if(strcmp(ch, "#") == 0)
            break;
        int len = strlen(ch);
        for(i = 0; i < len; i++){
            if(ch[i] == ' '){
                cout << "%20";
                continue;
            }
            else if(ch[i] == '!'){
                cout << "%21";
                continue;
            }
            else if(ch[i] == '$'){
                cout << "%24";
                continue;
            }
            else if(ch[i] == '%'){
                cout << "%25";
                continue;
            }
            else if(ch[i] == '('){
                cout << "%28";
                continue;
            }
            else if(ch[i] == ')'){
                cout << "%29";
                continue;
            }
            else if(ch[i] == '*'){
                cout << "%2a";
                continue;
            }
            else
                cout << ch[i];
        }
        cout << endl;
    }
    return 0;
}
