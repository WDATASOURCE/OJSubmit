#include<iostream>
#define PI 3.14159
using namespace std;

int main(){
    double r, area, g1, a, b;
    int t, i = 0, y;
    cin >> t;
    while(t--){
        cin >> a >> b;
        r = a * a + b * b;
        i++;
        area = PI * r;
        g1 = area / 50.0 / 2.0;
        y = area / 50 / 2;
        if(area - y < 1e-5)
           cout << "Property "<< i <<": This property will begin eroding in year "<< y <<"."<< endl;
        else
           cout << "Property "<< i <<": This property will begin eroding in year "<< y + 1 <<"."<< endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}
