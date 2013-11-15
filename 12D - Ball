/*
  Algorithm - Interval Tree
/*
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN=500001;
class Point
{
public:
    int x,y,z;
};
class Node
{
public:
    int left,right;
    int height;
};
Point p[MAXN];
Node node[1<<20];
int y[MAXN];

int cmp_point(const void *t1,const void *t2)
{
    Point *a,*b;
    a=(Point*)t1;
    b=(Point*)t2;
    if (a->x==b->x)
    {
        return a->y-b->y;
    }else{
        return b->x-a->x;
    }
}
int cmp_int(const void *t1,const void *t2)
{
    int a,b;
    a=*(int*)t1;
    b=*(int*)t2;
    return a-b;
}
int compress(int a[],int size)
{
    qsort(a,size,sizeof(int),cmp_int);
    int index=1;
    for (int i=1;i<size;i++)
    {
        if (a[i]!=a[i-1]) a[index++]=a[i];
    }
    return index;
}
int bsearch(int value,int a[],int size)
{
    int low,mid,high;
    low=0; high=size-1;
    while (low<=high)
    {
        mid=low+(high-low)/2;
        if (a[mid]==value) return mid;
        if (a[mid]<value) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
void build(int rootIndex,int start,int end)
{
    node[rootIndex].height=0;
    node[rootIndex].left=start;
    node[rootIndex].right=end;
    if (start==end) return;
    int mid=(start+end)/2;
    int leftIndex=2*rootIndex+1;
    int rightIndex=2*rootIndex+2;
    build(leftIndex,start,mid);
    build(rightIndex,mid+1,end);
}
void update(int rootIndex,int pos,int H)
{
    if (node[rootIndex].left==node[rootIndex].right)
    {
        node[rootIndex].height=max(node[rootIndex].height,H);
        return;
    }
    int leftIndex=2*rootIndex+1;
    int rightIndex=2*rootIndex+2;
    if (pos<=node[leftIndex].right)
    {
        update(leftIndex,pos,H);
    }
    if (pos>=node[rightIndex].left)
    {
        update(rightIndex,pos,H);
    }
    node[rootIndex].height=max(node[leftIndex].height,node[rightIndex].height);
}
int query(int rootIndex,int start,int end)
{
    if (start>end) return 0;
    if (start<=node[rootIndex].left 
       && end>=node[rootIndex].right)
    {
        return node[rootIndex].height;
    }
    int leftIndex=2*rootIndex+1;
    int rightIndex=2*rootIndex+2;
    int A=0,B=0;
    if (node[leftIndex].right>=start)
    {
        A=query(leftIndex,start,end);
    }
    if (node[rightIndex].left<=end)
    {
        B=query(rightIndex,start,end);
    }
    return max(A,B);
}
int main()
{
    int N,M;
    while (1==scanf("%d",&N))
    {
        for (int i=0;i<N;i++) scanf("%d",&p[i].x);
        for (int i=0;i<N;i++)
        {
            scanf("%d",&p[i].y);
            y[i]=p[i].y;
        }
        for (int i=0;i<N;i++) scanf("%d",&p[i].z);
        qsort(p,N,sizeof(Point),cmp_point);
        M=compress(y,N);
        build(0,0,M-1);
        int result=0;
        for (int i=0;i<N;i++)
        {
            p[i].y=bsearch(p[i].y,y,M);
            update(0,p[i].y,p[i].z);
            int H=query(0,p[i].y+1,M-1);
            if (H>p[i].z)
            {
                result++;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
