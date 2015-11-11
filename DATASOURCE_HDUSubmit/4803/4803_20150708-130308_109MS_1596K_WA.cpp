#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std ;

const double eps = 1e-9;
int main()
{
    double x ,y  ;
    while(~scanf("%lf %lf",&x,&y)) {
        if(x > y)
        {
            printf("-1\n") ;
            continue ;
        }
        double price = (y+1-eps)/x ;//ÒÔ×îÖÕµÄÌâÄ¿ÖÐÒªÇóµÄÁ½¸öÊýx£¬yÀ´Ëã£¬×îÖÕµ¥¼ÛÓ¦¸ÃÊÇs
        double sum = 1.0 ;
        int ans = int(x-1) ;//ÊýÁ¿±äµÄ»°£¬×Ü¼ÛÊÇ²»»á±äµÄ£¬ËùÒÔÒª±äµ½×îÖÕµÄx£¬ÖÁÉÙÒ²Òª±äx-1´Î
        for(int i = 1 ; i <= int(x) ; i++){
            double totalprice = i*price ;//ÒÔpriceÎª×îÖÕµ¥¼Û£¬ÄÇÃ´ÒÔÏÖÔÚµÄÊýÁ¿Ó¦¸ÃÓµÓÐµÄ×Ü¼ÛÊÇ¶àÉÙ
            int k = (int)(totalprice-sum) ;//»¹²î¶àÉÙµ½ÒÔ¸Ãµ¥¼Ûµ½´ïµÄ×Ü¼Û
            ans += k ;//¼ÓÉÏÏà²îµÄÄÇÐ©
            sum += k ;//Ôö³¤ÊýÁ¿µÄÊ±ºò×Ü¼ÛÒ²ÊÇÔö³¤µÄ
            sum = sum * ((i+1)*1.0/i) ;
        }
        printf("%d\n",ans) ;
    }
    return 0 ;
}