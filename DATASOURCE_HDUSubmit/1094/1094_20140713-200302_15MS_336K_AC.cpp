#include<iostream>
using namespace std;

int main(){
int a, b, n, i;
while(cin >> n){
a = 0;
for(i = 0; i < n; i++){
cin >> b;
a += b;
}
cout << a << endl;
}
return 0;
}