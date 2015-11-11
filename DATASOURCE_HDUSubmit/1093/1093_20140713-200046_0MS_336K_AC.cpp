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
    int a, b, t, s,i;
    cin >> t;
    while(t--){
        cin >> s;
        a = 0;
        for(i = 0; i < s; i++){
            cin >> b;
            a += b;
        }
        cout << a << endl;
    }
    return 0;
}
