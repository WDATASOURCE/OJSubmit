#include<iostream>
using namespace std;
int a, b, c, d;
char ch, s;

int yueshu(int a, int b){
    int t,n;
    if(b>a)
    {
        t=a;
        a=b;
        b=t;
    }
    n=a%b;
    while(n!=0)
    {
        a=b;
        b=n;
        n=a%b;
    }
    return b;
}

void cal(){
    int fz, fm, y;
    if(ch != '-'){
        fz = a * d + b * c; 
        fm = b * d;
    }
    else {
        fz = a * d - b * c;
        if(fz != 0)
        cout << "-" ;
        fm = b * d;
        if(fz < 0)
            fz = -fz;
    }
    if(fz == 0){
        cout << 0 << endl;
        return ;
    }
    y = yueshu(fz, fm);
    cout << fz / y <<"/"<< fm / y <<endl;
    return;

}


int main(){
    ios_base::sync_with_stdio(false);
    while(cin >> a){
        cin >> s;
        cin >> b;
        cin >> ch;
        cin >> c;
        cin >> s;
        cin >> d;
        cal();
    }
    return 0;
}
