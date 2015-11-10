#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int m, t, u, f, d;
    while(cin >> m >> t >> u >> f >> d){
        int ans = 0, di = 0;
        char c;
        while(t--){
            cin >> c;
            if(c == 'u' || c == 'd')
                ans += u + d;
            else if(c == 'f')
                ans += 2 * f;
            if(ans <= m)
                di++;
        }
        cout << di << endl;
    }
    return 0;
}
