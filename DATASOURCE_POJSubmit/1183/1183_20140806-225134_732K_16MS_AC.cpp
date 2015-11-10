#include <iostream>
#include <cstdio>
#define M 1 << 30
using namespace std;

int main(){
    long long m, a;
    while(cin >> a){
        int ans = M;
        for(m = a; m >= 1; m--)
            if((a * a + 1) % m == 0)
                ans = ans < (m + (a * a + 1) / m) ? ans : (m + (a * a + 1) / m);
        cout << ans + 2 * a << endl;
    }
    return 0;
}
