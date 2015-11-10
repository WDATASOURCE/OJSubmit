/*************************************************************************
	> File Name: a.cpp
	> Author: He Shuwei
	> Mail: 
	> Created Time: 2014年08月08日 星期五 22时57分34秒
 ************************************************************************/

 #include <iostream>
 #include <cmath>
 #include <cstdio>
 using namespace std;
const double PI=acos(double(-1)); 
const double e=exp(double(1)); 
int main() {    
    int N,num;
    cin>>num;
    while(num--){
        cin>> N;
        int len = 0;
        //len = int((N*log(N) - N + 0.5 * log(2*N*PI) ) / log(10)) + 1; 
        len = int(log10(sqrt(2*PI*N))+N*log10(N/e))+1;
        printf("%d\n",len);  
     }
    return 0;
}
