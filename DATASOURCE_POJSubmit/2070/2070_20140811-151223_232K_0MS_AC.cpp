#include<iostream>
using namespace std;
int main()
{
   double pl[3],a[3][3]={{4.5,150,200},{6,300,500},{5,200,300}};
   char b[3][15]={"Wide Receiver ","Lineman ","Quarterback "};
   int flag;
   while(cin>>pl[0]>>pl[1]>>pl[2],(pl[0]||pl[1]||pl[2]))
   {
       flag=0;
       for(int i=0;i<3;i++)
           if(pl[0]<=a[i][0]&&pl[1]>=a[i][1]&&pl[2]>=a[i][2]){cout<<b[i];flag=1;}
       if(flag==1)cout<<endl;
       else cout<<"No positions"<<endl;
   }
   return 0;
}