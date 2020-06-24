#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int heap[maxn];
 void downajust(int low,int high)
 {
     int i=low;
     int j=2*i;
     while(j<=high)
     {
         if(j+1<=high&&heap[j+1]>heap[j])
         {
             j=j+1;
         }
         if(heap[j]>heap[i])
         {
             swap(heap[j],heap[i]);
             i=j;
             j=j*2;
         }
         else
         {
             break;
         }
     }
 }
void createheap(int n)
{
    for(int i=n/2;i>=1;i--)
    {
        downajust(i,n);
    }
}
void heapsort(int n)
{
    createheap(n);
    for(int i=n;i>1;i--)
    {
        swap(heap[i],heap[1]);
        downajust(1,i-1);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&heap[i]);
        }
        heapsort(n);
        for(int i=1;i<=n;i++)
        {
            printf("%d ",heap[i]);
        }
        printf("\n");
    }
    return 0;
}
