#include<cstdio>
#include<iostream>
using namespace std;
struct node
{
    int id,grade;
    node *next;
};
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)//在输入的同时进行排序
    {
        node *head=new node;
        head->next=NULL;

        for(int i=0;i<n+m;i++)
        {
            node *pre=head;
            node *p=head->next;
            int a,b;
            node *temp=new node;
            scanf("%d%d",&a,&b);
            temp->id=a;
            temp->grade=b;
            while(p!=NULL)
            {
                if(temp->id<p->id)
                {
                    break;
                }
                else
                {
                    pre=p;
                    p=p->next;
                }
            }
            temp->next=pre->next;
            pre->next=temp;
        }
        node *it=head->next;
        while(it!=NULL)
        {
            printf("%d %d\n",it->id,it->grade);
            it=it->next;
        }
    }
    return 0;
}
