//�������������
//1.���¸�һ����վ/�յ���600���Ͼ��룬��������ʻ��Զ����
//2.��600������վ��
//(1)600��û�бȵ�ǰ��վ�����˵��ͣ�������ʻ��600����Ա��˵���վ
//(2)600���бȵ�ǰ��վ�����˵��ͣ�������ǡ������ʻ��
//3.�������վ/·����վ����Ϊ0�����Ӷ�����

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
    double c,d,da;//c������������d�Ǻ��ݵ��յ�ľ��룬da�������ĵ�λ�ͺ���ʻ���룬n�Ǽ���վ������
    scanf("%lf%lf%lf%d",&c,&d,&da,&n);

    //����������ܵ����յ�����
    if(n==0)
    {
        printf("The maximum travel distance = %.2f\n",0);//����վ����Ϊ0���޷�����������Ϊ0��
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
        printf("The maximum travel distance = %.2f\n",0);//�뺼������ļ���վ���뺼�ݲ�Ϊ0���޷�����������Ϊ0��
        return 0;
    }

    //���濪ʼ�����ܹ��ﵽ�յ�����
    double tdis=0;//����ʻ���룻
    double cost=0;//�ܵķ���
    bool arr=0;//�Ƿ񵽴��յ�
    int nowdis=0;//��ǰ����վλ��
    double maxdis=c*da;//�����������ʻ����
    double nowprice=sta[0].price;//��ǰ�ͼ�
    double legas=0;//ʣ������
    while(!arr)
    {
        bool flag=0;//�����Ƿ��м���վ
        bool cheap=0;//�����Ƿ��м۸�����˵ļ���վ
        double cheapprice=10000;//�������˼���վ�ļ۸�
        int cheapdis;//�������˼���վ��λ��
        for(int i=nowdis+1;i<n;i++)
        {
            if(maxdis>=sta[i].dis-sta[nowdis].dis)//�����м���վ
            {
                flag=1;
                if(sta[i].price<nowprice)//�����и����˵ļ���վ
                {
                    cheap=1;
                    double negas=(sta[i].dis-sta[nowdis].dis)/da-legas;
                    cost+=negas*nowprice;
                    nowprice=sta[i].price;
                    nowdis=i;
                    legas=0;
                    break;
                }
                if(cheapprice>sta[i].price)//����û�и����˵ļ���վ,���Ҹ���Ա��˵ļ��ɣ�����cheapprice�ͼ���
                {
                    cheapprice=sta[i].price;
                    cheapdis=i;
                }
            }
            else break;//����û�м���վʱ����Ҫ����ܾ������㻨�ѣ������ټ���
        }
        if(!cheap&&(d-sta[nowdis].dis)<=maxdis)//�����и����˵ļ���վ����ô���ڵ�ǰ����վ�����������ܹ�����ļ���վ�����ڸü���վ�ӵ��պÿ��Ե����յ�
        {
            double negas=(d-sta[nowdis].dis)/da-legas;
            cost+=negas*nowprice;
            printf("%.2f\n",cost);
            return 0;
        }
        if(!cheap&&flag)//����û�и����˵ļ���վ����ô���ڵ�ǰ����վ�������ڸ����ܴﵽ�ļ���վ
        {
            double negas=c-legas;
            cost+=negas*nowprice;
            legas=c-(sta[cheapdis].dis-sta[nowdis].dis)/da;
            nowprice=sta[cheapdis].price;
            nowdis=cheapdis;
        }
        if(!flag)//����û�м���վ
        {
            printf("The maximum travel distance = %.2f\n",sta[nowdis].dis+maxdis);
            return 0;
        }
    }
    return 0;
}
