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
            cerr << c << endl;
            if(c == 'u' || c == 'd')
                ans += u + d;
            if(c == 'f')
                ans += 2 * f;
            cerr << ans << endl;
            if(ans <= m)
                di++;
        }
        printf("%d\n", di);
    }
    return 0;
}
