#include <ctime>
#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
int n;

long long bfs(){
    queue<long long> p;
    while(!p.empty())
        p.pop();
    p.push(1);
    while(1){
        long long sum = p.front();
        if(sum % n == 0)
            return sum;
        p.pop();
        p.push(10 * sum);
        p.push(10 * sum + 1);
    }
}

int main(){
    //clock_t start = clock();
    while(scanf("%d", &n) != EOF){
        printf("%I64d\n", bfs());
    }
    //clock_t stop = clock();
    //cerr <<"time = "<< (double)(stop - start) <<"MS"<< endl;
    return 0;
}
