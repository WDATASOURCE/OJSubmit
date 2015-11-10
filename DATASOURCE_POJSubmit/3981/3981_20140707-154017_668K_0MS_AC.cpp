#include<iostream>
#include<string.h>
using namespace std;
char ch[1005],s[30];

void change(){
    int i, len, j = 0;
    len = strlen(ch);
    for(i = 0; i < len; i++){
        while(ch[i] != ' ' && i < len){
            s[j] = ch[i];
            j++;
            i++;
        }
        s[j] = 0;
        if(strcmp(s,"you") == 0)
            cout << "we" ;
        else
            cout << s ;
        if(i < len)
        cout << ch[i];
        j = 0;
    }
}

int main(){
    while(cin.getline(ch,1005)){
        change();
        cout << endl;
    }
    return 0;
}



