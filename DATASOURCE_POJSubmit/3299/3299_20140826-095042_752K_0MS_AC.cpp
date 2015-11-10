#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


char c;
double t,d,h;
bool tt,dd,hh;
int main() {
	cout<<setprecision(1)<<fixed;
	while (true) {
		tt=dd=hh=true;
		cin>>c;
		if (c=='E') break;
		switch (c) {
			case 'T':tt=false;cin>>t;break;
			case 'H':hh=false;cin>>h;break;
			case 'D':dd=false;cin>>d;break;
		}
		cin>>c;
		switch (c) {
			case 'T':tt=false;cin>>t;break;
			case 'H':hh=false;cin>>h;break;
			case 'D':dd=false;cin>>d;break;
		}
		if (tt) {
			t=h-0.5555*(6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10.0);
		} else if (dd) {
			d=1/(1/273.16-log(((h-t)/0.5555+10)/6.11)/5417.7530)-273.16;
		} else {
			h=t+0.5555*(6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10.0);
		}
		cout<<"T "<<t<<" D "<<d<<" H "<<h<<endl;
	}
	return 0;
}