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
        flag[res[i]]=true;//ѡ����res[i];
        //���������res[i]�����Խ�����һ�е�λ�ò��ɷ���
        if(res[i]+i-index>=0)
        {
            flag[res[i]+i-index]=true;
        }
        if(res[i]-i+index<n)
        {
            flag[res[i]-i+index]=true;
        }
    }
    for(int i=0;i<n;i++)//����ÿһ�У�δ����ǵĿ���ѡ��
    {
        if(!flag[i])
        {
            res[index]=i;//ѡ���i��
            nqueen(index+1);//������һ��
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
