#include<iostream>
using namespace std;

int func(int x){
    if(x == 1 || x == 0) return 1;
    else return x * func(x - 1);
}

int main(){
    int n, i;
    double key, sum = 0;
    ios_base::sync_with_stdio(false);
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    for(i = 0; i <=9; i++){
        n = func(i);
        key = 1.0 / n + sum;
        sum = key;
        cout << i <<" "<< key <<endl;
    }
    return 0;
}
