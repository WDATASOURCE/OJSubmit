#include<iostream>
using namespace std;

int main(){
int a, b, c, t, i;
cin >> t;
while(t--){
a = 0;
cin >> c;
for(i = 0; i < c; i++){
cin >> b;
a += b;
}
cout << a << endl;
if(t != 0)
cout << endl;
}
return 0;
}