#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#define M 300
using namespace std;

char ch[M];

int main(){
    int i, sum;
    while(1){
        cin.getline(ch, M);
        if(strcmp(ch, "#") == 0)
            break;
        sum = 0;
        int len = strlen(ch);
        for(i = 0; i < len; i++){
            if(ch[i] == ' ')
                continue;
            else
                sum += (ch[i] - 'A' + 1) * (i + 1);
        }
        cout << sum << endl;
    }
    return 0;
}
