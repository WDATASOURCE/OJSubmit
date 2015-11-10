#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    long long a, b;
    int sum;
    while(1){
        cin >> a >> b;
        sum = 0;
        int c = 0;
        if(!a && !b)
            break;
        for(int i = 11; i >= 0; i--){
            c = (a % 10 + b % 10 + c) >= 10 ? 1 : 0;
            sum += c;
            a /= 10;
            b /= 10;
        }
        if(sum == 0)
            cout <<"No carry operation."<< endl;
        else if(sum == 1)
            cout <<"1 carry operation." << endl;
        else
            cout << sum <<" carry operations."<< endl;
    }
    return 0;
}
