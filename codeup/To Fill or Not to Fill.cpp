//分析所有情况：
//1.离下个一个油站/终点在600以上距离，即加满行驶最远距离
//2.在600内有油站，
//(1)600内没有比当前油站更便宜的油，加满行驶至600内相对便宜的油站
//(2)600内有比当前油站更便宜的油，加油至恰好能行驶到
//3.起点无油站/路线油站个数为0，车子动不了

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=510;
struct gasstation
{
    double price;
    double dis;
} sta[maxn];
bool cmp(gasstation a,gasstation b)
{
    return a.dis<b.dis;
}
int main()
{
    int n;
    double c,d,da;//c是油箱容量，d是杭州到终点的距离，da是汽车的单位油耗行驶距离，n是加油站数量；
    scanf("%lf%lf%lf%d",&c,&d,&da,&n);

    //下面表述不能到达终点的情况
    if(n==0)
    {
        printf("The maximum travel distance = %.2f\n",0);//加油站数量为0，无法出发，距离为0；
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&sta[i].price,&sta[i].dis);
    }
    sort(sta,sta+n,cmp);
    /*for(int i=0;i<n;i++)
    {
        printf("%f %f\n",sta[i].price,sta[i].dis);
    }*/
    if(sta[0].dis!=0)
    {
        printf("The maximum travel distance = %.2f\n",0);//离杭州最近的加油站距离杭州不为0，无法出发，距离为0；
        return 0;
    }

    //下面开始计算能够达到终点的情况
    double tdis=0;//总行驶距离；
    double cost=0;//总的费用
    bool arr=0;//是否到达终点
    int nowdis=0;//当前加油站位置
    double maxdis=c*da;//油箱加满后行驶距离
    double nowprice=sta[0].price;//当前油价
    double legas=0;//剩余油量
    while(!arr)
    {
        bool flag=0;//附近是否有加油站
        bool cheap=0;//附近是否有价格更便宜的加油站
        double cheapprice=10000;//附近便宜加油站的价格
        int cheapdis;//附近便宜加油站的位置
        for(int i=nowdis+1;i<n;i++)
        {
            if(maxdis>=sta[i].dis-sta[nowdis].dis)//附近有加油站
            {
                flag=1;
                if(sta[i].price<nowprice)//附近有更便宜的加油站
                {
                    cheap=1;
                    double negas=(sta[i].dis-sta[nowdis].dis)/da-legas;
                    cost+=negas*nowprice;
                    nowprice=sta[i].price;
                    nowdis=i;
                    legas=0;
                    break;
                }
                if(cheapprice>sta[i].price)//附近没有更便宜的加油站,就找个相对便宜的即可，即比cheapprice低即可
                {
                    cheapprice=sta[i].price;
                    cheapdis=i;
                }
            }
            else break;//附近没有加油站时，需要结合总距离来算花费，后面再计算
        }
        if(!cheap&&(d-sta[nowdis].dis)<=maxdis)//附近有更便宜的加油站，那么就在当前加油站加满到附近能够到达的加油站，并在该加油站加到刚好可以到达终点
        {
            double negas=(d-sta[nowdis].dis)/da-legas;
            cost+=negas*nowprice;
            printf("%.2f\n",cost);
            return 0;
        }
        if(!cheap&&flag)//附近没有更便宜的加油站，那么就在当前加油站加满，在附近能达到的加油站
        {
            double negas=c-legas;
            cost+=negas*nowprice;
            legas=c-(sta[cheapdis].dis-sta[nowdis].dis)/da;
            nowprice=sta[cheapdis].price;
            nowdis=cheapdis;
        }
        if(!flag)//附近没有加油站
        {
            printf("The maximum travel distance = %.2f\n",sta[nowdis].dis+maxdis);
            return 0;
        }
    }
    return 0;
}
