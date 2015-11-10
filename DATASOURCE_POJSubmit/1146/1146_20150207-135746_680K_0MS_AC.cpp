#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char ch[100];

int main(){
    while(gets(ch) != NULL){
        if(strcmp(ch, "#") == 0) break;
        int len = strlen(ch);
        while(next_permutation(ch, ch + len)){
            printf("%s\n", ch);
            goto A;
        }
        printf("No Successor\n");
A: ;
    }
    return 0;
}
