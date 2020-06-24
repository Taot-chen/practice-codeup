#include<cstdio>
#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        node *head=new node;
        head->next=NULL;
        node *p=head;
        for(int i=0;i<m;i++)
        {
            node *temp=new node;
            scanf("%d",&temp->data);
            p->next=temp;
            temp->next=head;
            p=p->next;
        }
        int n;
        scanf("%d",&n);
        node *head1=new node;
        head1->next=NULL;
        node *p1=head1;
        for(int i=0;i<n;i++)
        {
             node *temp1=new node;
            scanf("%d",&temp1->data);
            p1->next=temp1;
            temp1->next=head1;
            p1=p1->next;
        }//至此，两个链表输入完毕
        p->next=head1->next;
        p1->next=head;
        delete(head1);
        node *q=head->next;
        while(q!=head)
        {
            if(q->next==head)
            {
                //printf("&");
                printf("%d\n",q->data);
            }
            else
            {
                printf("%d ",q->data);
            }
            q=q->next;
        }
    }
    return 0;
}
