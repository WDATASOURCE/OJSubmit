#include<iostream>
#include<string.h>
using namespace std;
char ch[202];

void change(){
    int i, len;
    len = strlen(ch);
    for(i = 0; i < len; i++){
        if(ch[i] <= 'Z' && ch[i] >= 'A'){
            if(ch[i] >= 'F')
                cout << (char)(ch[i] - 5);
            else
                cout<< (char)(ch[i] + 21);
        }
        else
            cout << ch[i];
    }
}


int main(){
    char s1[30];
    while(1){
        cin.getline(s1, 30);
        if(strcmp(s1,"START") == 0){
            cin.getline(ch, 202);
            change();
            cout<<endl;
        }
        else if(strcmp(s1,"ENDOFINPUT") == 0)
            break;
    }
    return 0;
}