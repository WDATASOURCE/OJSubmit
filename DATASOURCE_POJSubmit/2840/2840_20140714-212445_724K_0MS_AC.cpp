#include<iostream>
using namespace std;

int main(){
    int t, h, m;
    char ch;
    cin >> t;
    while(t--){
        cin >> h >> ch >> m;
        if(m != 0)
            cout << 0 << endl;
        else if(h < 13)
            cout << h + 12 << endl;
        else
            cout << h - 12 << endl;
    }
    return 0;
}
