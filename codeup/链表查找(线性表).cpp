#include<cstdio>
struct node
{
    int data;
    node *next;
};
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        int n;
        scanf("%d",&n);
        node *head=new node;
        head->next=NULL;
        node *p=head;
        for(int i=0;i<n;i++)
        {
            node *temp=new node;
            scanf("%d",&temp->data);
            p->next=temp;
            temp->next=NULL;
            p=p->next;
        }//ÊäÈëÍê±Ï
        node *pre=head;
        p=head->next;
        while(p->data<x)
        {
            pre=p;
            p=p->next;
        }
        if(p->data==x)
        {
            node *s=p->next;
            p->next=pre->next;
            p->next=s->next;
            node *it=head->next;
            while(it!=NULL)
            {
                printf("%d ",it->data);
                it=it->next;
            }
            printf("\n");
        }
        else
        {
            printf("no\n");
            node *t=new node;
            t->data=x;
            t->next=p;
            pre->next=t;
            node *it=head->next;
            while(it!=NULL)
            {
                printf("%d ",it->data);
                it=it->next;
            }
            printf("\n");
        }
    }
    return 0;
}
