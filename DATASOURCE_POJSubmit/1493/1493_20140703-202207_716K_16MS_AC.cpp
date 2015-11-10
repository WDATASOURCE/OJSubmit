#include<iostream>
using namespace std;

void func(char s[][26] , int n){
    int i , j , m , sum = 0;
    int l[13] = { 0 };
    for(i = 0 ; i < n ; i++)
        for(j = 0 ; j < 25 ; j++){
            if(s[i][j] == ' ')
                l[i]++;
        }
    m = l[0];
    for(i = 0 ; i < n ; i++)
       if(m > l[i])
          m = l[i]; 
    for(i = 0 ; i < n ; i++)
            sum += l[i] - m ;
        cout << sum << endl;
}
        


int main(){
    ios::sync_with_stdio(false);
    int n , i ;
    char s[13][26];
    while(cin >> n){
        if(n == 0)
            return 0;
        cin.ignore();
        for(i = 0 ; i < n ; i++)
           cin.getline(s[i] , 26);
            func(s , n);
    }
}
