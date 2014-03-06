/**
 * Algorithm: Union Set & Floyd Warshall shortest path
 * Date: 2014.3.6
 * Copyright: Hong Sun
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=100001;
int type[MAXN];
int father[MAXN];
int c[501];
int d[501][501];
int from[501];

/*
 * Find father of a vertex
 * If u and v have the same father, there is a zero weight path between them
*/
int getFather(int u)
{
    if (father[u]==u)
    {
        return u;
    }
    father[u]=getFather(father[u]);
    return father[u];
}
int main()
{
    int n,m,k;
    int u,v,x;
    while (3==scanf("%d%d%d",&n,&m,&k))
    {
        int start = 0;
        int typeNum = 0;
        for (int i=0;i<k;i++)
        {
            scanf("%d",&c[i]);
            from[typeNum]=start;
            for (int j=0;j<c[i];j++)
            {
                type[start]=typeNum;
                father[start]=start;
                start++;
            }
            typeNum++;
        }
        memset(d,0xff,sizeof(d));
        for (int i=0;i<k;i++)
        {
            d[i][i] = 0;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&x);
            u--; v--;
            int a = type[u];            
            int b = type[v];
            d[a][b]=(d[a][b]<0)?x:min(d[a][b],x);
            d[b][a]=d[a][b];
            if (x==0)
            {
                int fu = getFather(u);
                int fv = getFather(v);
                if (fu!=fv)
                {
                    if (u<v) father[fv]=fu;
                    else father[fu]=fv;
                }
            }
        }
        bool valid = true;
        for (int i=0;i<n;i++)
        {
            if (getFather(i)!=getFather(from[type[i]]))
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            printf("No\n");
        }else{
            printf("Yes\n");
            for (int t=0;t<k;t++)
            {
                for (int i=0;i<k;i++)
                {
                    if (i==t) continue;
                    for (int j=0;j<k;j++)
                    {
                        if (j==t || j==i) continue;
                        if (d[i][t]<0 || d[t][j]<0) continue;
                        int len = d[i][t] + d[t][j];
                        if (d[i][j]<0 || d[i][j]>len) d[i][j]=len;
                    }
                }
            }
            for (int i=0;i<k;i++)
            {
                printf("%d",d[i][0]);
                for (int j=1;j<k;j++)
                {
                    printf(" %d",d[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
