#include<iostream>
using namespace std;

int main(){
    int n , i , sum = 0 , l = 0; 
    ios::sync_with_stdio(false);
    while(cin >> n){
        sum=0;
        if(n == 0)
            return 0 ;
        l++;
        int *p = new int [n];
        for(i = 0 ; i < n ; i++){
            cin >> p[i];
            sum += p[i];
        }
        int ave = sum / n;
        int key = 0;
        for(i = 0 ; i < n ; i++)
            if(p[i] > ave)
                key += p[i] - ave ;
        cout<<"Set #"<<l<<endl;
        cout<<"The minimum number of moves is "<<key<<"."<<endl;
    }
}
