#include <cstdio>
#include<iostream>  
#include<vector>  
#include<queue>  
#include<stack>   
#include<cstring>  
using namespace std;  
  
const int maxn=1001;  
const int INF=0x7fffffff;  
  
struct edge   //边   
{  
    int to;  
    int cost;  
};   
  
vector<edge> myV[maxn];  //利用临界表存储图   
int numNode,numEdge;     //顶点数、边   
int minPath[maxn];       //最短路  
int source[maxn];        //source[a]=b，说明a的前驱为b   
int start,end;           //起点、终点   
bool inQ[maxn];          //是否入队   
       
void inputItial()  
{  
    int i,from,to,cost;  
      
    for(i=0;i<maxn;i++)  //清空再使用   
    {  
        myV[i].clear();  
    }  
      
    for(i=0;i<numEdge;i++)   //建图 ,无向图   
    {  
        scanf("%d%d%d",&from,&to,&cost);   
  
        edge e;  
        e.cost=cost;  
          
        e.to=to;  
        myV[from].push_back(e);  
          
        e.to=from;  
        myV[to].push_back(e);            
    }  
}  
  
  
/*
void output(int start,int end)   //输出   
{  
    if(minPath[end]==INF)  
    {  
        printf("No Such Path Exist!\n\n");  
    }   
    else if(start==end)  
    {  
        printf("From %d to %d :\n",start,end);  
        printf("Path: %d\n",start);  
        printf("Total cost : 0\n\n");  
    }  
    else  
    {   
        printf("From %d to %d :\n",start,end);    
        printf("Path: %d",start);  
          
        int tmp=end;   
        stack<int> s;  
        s.push(tmp);   
        while(source[tmp]!=start)  
        {     
            tmp=source[tmp];  
            s.push(tmp);      
        }  
        while(!s.empty())  
        {  
            printf("-->%d",s.top());  
            s.pop();  
        }   
        printf("\n");  
          
        printf("Total cost : %d\n\n",minPath[end]);  
    }   
}            
*/
       
void SPFA(int start,int end)   //最短路径快速算法 Shortest Path Faster Algorithm  
{  
    memset(inQ,false,sizeof(inQ));  
    inQ[start]=true;  
    for(int j=0;j<maxn;j++) minPath[j]=INF;  
    minPath[start]=0;  
          
    queue<int> myQ;  
    myQ.push(start);  
     
    int now,to,cost;  
    while(!myQ.empty())  
    {  
        now=myQ.front();  
        myQ.pop();  
              
        for(int k=0;k<myV[now].size();k++)  
        {  
            to=myV[now][k].to;  
            cost=myV[now][k].cost+minPath[now];  
               
            if(minPath[to]>cost)  
            {  
                source[to]=now;    //记录下to的来源为now   
                       
                minPath[to]=cost;  
                       
                if(!inQ[to])  
                {  
                    inQ[to]=true;  
                    myQ.push(to);  
                }  
            }  
        }  
              
        inQ[now]=false;  
    }  
      
    printf("%d\n", minPath[end]);
    //output(start,end);        
}  
           
int main()  {  
    while(scanf("%d%d",&numNode,&numEdge) != EOF)  {  
        inputItial();  
            SPFA(1, numNode);  
    }  
   
    //system("pause");     
    return 0;  
}  
