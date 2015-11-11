#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
int main()
{
     char str[111],a[11],b[11];
    int cas,i,j,minlen;
    scanf("%d",&cas);
    while(cas--)
    {
        minlen=999999999;
         scanf("%s %s %s",str,a,b);
         map<string,int>mp;
         int len=strlen(str);
         for(i=1;i<=len;i++)//±íÊ¾³¤¶È  ³¤¶ÈÊÇ¿ÉÒÔÎªlenµÄ   
         {
              for(j=0;j+i<=len;j++)//ÆðÊ¼Î»ÖÃ  ×¢Òâ j+i¿ÉÒÔµÈÓÚlen
              {
                  char ans[111];
                  int cnt=0;
                  for(int k=j;k<i+j&&k<len;k++)
                      ans[cnt++]=str[k];
                  ans[cnt]='\0';
                  mp[ans]=1;
                 // if(i<minlen) minlen=i;
              }
         }
         map<string,int>::iterator it;
         
         int  flag=0;
         string ans="";
         for(it=mp.begin();it!=mp.end();it++)
         {
             if(it->first.length()<minlen)
             {
                 if(strstr(it->first.c_str(),a)&&strstr(it->first.c_str(),b))
                 {
                     minlen=it->first.length();
                     ans=it->first;flag=1;
                     //printf("%s\n",it->first.c_str());flag=1;break;
                 }
             }
         }//printf("what?");
         if(flag==0) printf("No\n");
         else printf("%s\n",ans.c_str());
    }
    return 0;
}
