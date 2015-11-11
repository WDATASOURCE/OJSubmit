#include <cstdio>
int a1[6] = {2, 10, 18, 36, 54, 86};
int a2[6] = {9, 17, 35, 53, 85};
int ref[10] = {0, 1, 3, 2, 4, 6, 5, 7, 8};
int isIn(int *a, int x)
{
    for(int i=0; i<6; i++)
    {
        if(a[i] == x)
            return 1;
    }
    return 0;
}
int cmp(int x, int y)
{
    if(1<=x && x<=2 && 1<=y && y<=2)
    {
        return ref[x]-ref[y]>0;
    }
    if(3<=x && x<=10 && 3<=y && y<=10)
    {
        return ref[x-2]-ref[y-2]>0;
    }
    if(11<=x && x<=18 && 11<=y && y<=18)
    {
        return ref[x-10]-ref[y-10]>0;
    }
    if(35<=x && x<=36 && 35<=y && y<=36)
    {
        return ref[x-34]-ref[y-34]>0;
    }
    if(53<=x && x<=54 && 53<=y && y<=54)
    {
        return ref[x-52]-ref[y-52]>0;
    }
    if(85<=x && x<=86 && 85<=y && y<=86)
    {
        return ref[x-84]-ref[y-84]>0;
    }
    return x<y;
}
int main()
{
    int x, y;
    while(scanf("%d%d", &x, &y) != EOF)
    {
        int ans = cmp(x, y);
        if(ans)
            printf ( "FIRST BIGGER\n" );
        else
            printf ( "SECOND BIGGER\n" );
    }
    return 0;
}