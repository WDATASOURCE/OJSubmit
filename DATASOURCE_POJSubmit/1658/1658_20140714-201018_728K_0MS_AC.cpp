#include<iostream>
using namespace std;

int main(){
    int a, b, c, d, t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        if(c == 2 * b - a && d == c + b - a)
            cout << a <<" "<< b <<" "<< c <<" "<< d <<" "<< d + b - a << endl;
        else
            cout << a <<" "<< b <<" "<< c <<" "<< d <<" "<< d * b / a << endl;
    }
    return 0;
}
