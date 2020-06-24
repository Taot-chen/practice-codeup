#include<stdio.h>
#include<string.h>
int main()
{
    int N;
    //scanf("%d",&N);
    while(scanf("%d",&N)!=EOF)
    {
        char str[N][5];
    for(int i=0;i<N;i++)
    {
        gets(str[i]);
    }
    /*for(int i=0;i<=N;i++)
    {
        puts(str[i]);
    }*/
    char a[5]={'C',' ','J'},b[5]={'C',' ','B'},c[5]={'C',' ','C'};
    char d[5]={'B',' ','C'},e[5]={'B',' ','J'},f[5]={'B',' ','B'};
    char g[5]={'J',' ','C'},h[5]={'J',' ','J'},l[5]={'J',' ','B'};
    int x=0,y=0,z=0;
    for(int i=0;i<N;i++)
    {
        if(strcmp(str[i],a)==0||strcmp(str[i],l)==0||strcmp(str[i],d)==0)
            x++;
        else if(strcmp(str[i],c)==0||strcmp(str[i],f)==0||strcmp(str[i],h)==0)
            y++;
        //else  z++;
    }
    z=10-x-y;
     printf("%d %d %d\n%d %d %d\n",x,y,z,z,y,x);
     int w1=0,w2=0,w3=0,w4=0,w5=0,w6=0;
    for(int i=0;i<N;i++)
    {
        if(strcmp(str[i],a)==0) w1++;
        if(strcmp(str[i],l)==0) w2++;
        if(strcmp(str[i],d)==0) w3++;
        if(strcmp(str[i],c)==0) w4++;
        if(strcmp(str[i],f)==0) w5++;
        if(strcmp(str[i],h)==0) w6++;
    }
    if(w1>=w2&&w1>w3)
    {
        printf("C ");
    }
    else if(w2>w1&&w2>w3)
    {
        printf("J ");
    }
    else if(w3>=w1&&w3>=w2)
    {
        printf("B ");
    }
    if(w4>w5&&w4>=w6)
    {
        printf("C\n");
    }
    else if(w5>=w4&&w5>=w6)
    {
        printf("B\n");
    }
    else if(w6>=w4&&w6>=w5)
    {
        printf("J\n");
    }
    }

    return 0;
}
