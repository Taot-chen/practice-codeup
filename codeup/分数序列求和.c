#include <stdio.h>
int main()
{
    int i,n=20;
    double sum=0,z,m,zSave;//z,m�ֱ𱣴���ӷ�ĸ
    //printf("������ֵn:");
    //scanf("%d",&n);
    z=2;m=1;
    for(i=0;i<n;i++)
    {
        sum=sum+z/m;
        //printf("+%.0lf/%.0lf",z,m);
        zSave=z;
        z=z+m;
        m=zSave;
    }
    printf("%.6lf\n",sum);
    return 0;
}
