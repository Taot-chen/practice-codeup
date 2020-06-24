#include<cstdio>
#include<cstring>
const int maxn=10010;
int hashtable[1000];
int main()
{
    char s1[maxn],s2[maxn],result[maxn];
    while(gets(s1))
    {
        gets(s2);
        int n1=strlen(s1);
        int n2=strlen(s2);
        memset(hashtable,0,sizeof(hashtable));
        for(int i=0;i<n2;i++)
        {
            hashtable[s2[i]-'A']++;
        }
        for(int i=0;i<n1;i++)
        {
            if(hashtable[s1[i]-'A']==0)
            {
                printf("%c",s1[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
