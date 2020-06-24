#include<cstdio>
struct node
{
    int data;
    node *next;
};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            printf("list is empty\n");
            break;
        }
        node *head=new node;
        head->next=NULL;
        node *p=head;
        for(int i=0;i<n;i++)
        {
            node *temp=new node;
            scanf("%d",&temp->data);
            printf("%d ",temp->data);
            temp->next=p->next;
            p->next=temp;
        }
        printf("\n");
        node *t=head->next;
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t=t->next;
        }
        printf("\n");
    }
    return 0;
}
