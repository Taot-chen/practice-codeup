#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
//判断字符串是普通浮点型数据还是科学计数法的数字，若是前者，返回false，后者返回true
bool judge(string s)
{
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='e'||s[i]=='E')
        {
            return true;
            break;
        }
    }
    return false;
}
//把字符串转换成浮点型数据，方便运算
double change(string s)
{
    if(!judge(s))
    {
        int n=s.length();
        //printf("%d\n",n);
        //cout<<s<<endl;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='\0')
            {
                s.erase(s.begin()+i,s.end());
                break;
                //printf("%d ",i);
            }
        }
        //printf("\n");
        int m=s.length();
        /*for(int i=0;i<m;i++)
        {
            printf("%c",s[i]);
        }
        printf("\n");*/
        //printf("%d\n",m);
        //cout<<s<<endl;
        double a=0,b=0;
        for(int i=0;i<m;i++)
        {
            if(s[i]!='.')
            {
                a=a*10+(s[i]-'0');
            }
            else break;
        }
        for(int i=m-1;i>=0;i--)
        {
            //printf("%d",s[i]-'0');
            if(s[i]!='.')
            {
                b=b/10+(s[i]-'0')*1.0/10;
                //printf("%f ",b);
            }
            else break;
        }
        //printf("%f %f\n",a,b);
        double sum=a+b;
        //printf("%f\n",sum);
        return sum;
    }
}
//把计算的浮点型结果转换成科学计数法形式的字符串输出
string rechange(double a)
{
    int x=(int)a;
		double y=a-x;
		//cout<<x<<y<<endl;
		y*=10;
		while((int)y%10)
		{
			y*=10;;
		}
		y/=10;
		int c=(int)x;
		int d=(int)y;
		//cout<<c<<d<<endl;
		char res[100]={'\0'};
		int e=0;
		int f=c;
		int g=1;
		while(f/10)
		{
			e++;
			f/=10;
			g*=10;
		}
		//cout<<e<<g<<endl;
		double h=a/g;
		printf("%.4fe%d\n",h,e);
}
int main()
{
    string s1;
    double s2;
    s1.resize(20);
    while(scanf("%s%lf",&s1[0],&s2)!=EOF)
    {
        //cin>>s1>>s2;
        double a=change(s1);
        double b=s2;
        double sum=a+b;
        rechange(sum);
    }
    return 0;
}
