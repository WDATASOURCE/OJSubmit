#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a[7];
    int sum = 0;
    while(1){
        sum = 0;
        for(int i = 0; i < 6; i++)
            cin >> a[i];
        sort(a, a + 6);
        if(a[0] && a[5]){
            for(int i = 1; i < 5; i++)
                sum += a[i];
            double ave = sum / 4.0;
            cout << ave << endl;
        }
        else
            break;
    }
    return 0;
}
