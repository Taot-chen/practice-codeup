#include<cstdio>
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        int a[2][3],b[3][2],c[2][2]={0};
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(!i&&!j) a[0][0]=x;
                else scanf("%d",&a[i][j]);
            }
        }

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<3;k++)
                {
                    c[i][j]+=a[i][k]*b[k][j];
                    //printf("%d ",c[i][j]);
                }
            }
            //printf("\n");
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                printf("%d",c[i][j]);
                if(j<2) printf(" ");
                //else printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}
