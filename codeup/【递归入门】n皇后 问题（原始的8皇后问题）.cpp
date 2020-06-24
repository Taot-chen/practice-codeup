#include<cstdio>
int n,cnt;
int res[15];
void nqueen(int index)
{
    if(index==n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d",res[i]+1);
            if(i<n)
            {
                printf(" ");
            }
        }
        printf("\n");
        cnt++;
    }
    bool flag[15]={false};
    for(int i=0;i<index;i++)
    {
        flag[res[i]]=true;//选择了res[i];
        //接下来标记res[i]两个对角线下一列的位置不可放置
        if(res[i]+i-index>=0)
        {
            flag[res[i]+i-index]=true;
        }
        if(res[i]-i+index<n)
        {
            flag[res[i]-i+index]=true;
        }
    }
    for(int i=0;i<n;i++)//遍历每一列，未被标记的可以选择
    {
        if(!flag[i])
        {
            res[index]=i;//选择第i列
            nqueen(index+1);//进入下一层
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        nqueen(0);
        if(!cnt)
        {
            printf("no solute!\n");
        }
        //printf("%d\n",cnt);
    }
    return 0;
}
