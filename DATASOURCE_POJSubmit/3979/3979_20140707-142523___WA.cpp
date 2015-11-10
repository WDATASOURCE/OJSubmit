#include<iostream>
#include<string.h>
using namespace std;
char ch[50];
int z[4];
int len, f=0;

void find(){
    int i, j = 0, a=0;
    for(i = 0; i < len; i++){
        if(ch[i] >= '0' && ch[i] <= '9'){
            a = a * 10 + ch[i] - '0';
            if(!(ch[i + 1] >= '0' && ch[i + 1] <= '9')){
                z[j] = a;
                j++;
                a = 0;
            }
        }
        if(ch[i] == '-')
            f = 1;
    }
}

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
    if(f == 0){
        fz = z[0] * z[3] + z[1] * z[2];
        fm = z[1] * z[3];
    }
    else {
        fz = z[0] * z[3] - z[1] * z[2];
        if(fz != 0)
        cout << "-" ;
        fm = z[1] * z[3];
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
    int i;
    while(cin.getline(ch, 50)){
        len = strlen(ch);
        find();
        cal();
    }
    return 0;
}
