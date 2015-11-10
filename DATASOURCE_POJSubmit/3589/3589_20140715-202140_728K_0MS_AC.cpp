#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#define M 5
using namespace std;

char a[M], b[M];

int main(){
    int t, A, B;
    cin >> t;
    while(t--){
        cin >> a;
        cin >> b;
        A = 0;
        B = 0;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(a[i] == b[j] && i != j)
                    B++;
        for(int i = 0; i < 4; i++)
            if(a[i] == b[i])
                A++;
        cout << A <<"A"<< B <<"B"<<endl;
    }
    return 0;
}

