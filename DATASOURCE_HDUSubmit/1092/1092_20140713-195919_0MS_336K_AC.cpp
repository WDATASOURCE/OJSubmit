#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<math.h>
#include<string.h>
#define N 205
#define M 0x3f3f3f3f
using namespace std;

int main(){
    int a, b, t, i;
    while(1){
        cin >> t;
        if(t == 0)
            break;
        a=0;
        for(i = 0; i < t; i++){
            cin >> b;
            a +=b;
        }
        cout<< a<< endl;
    }
    return 0;
}
