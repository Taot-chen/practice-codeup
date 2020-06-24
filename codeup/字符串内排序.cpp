#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=210;
int main()
{
    char str[maxn];
    while(gets(str))
    {
        int n=strlen(str);
        sort(str,str+n);
        for(int i=0;i<n;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
