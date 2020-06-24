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
        int num;
        node *head=new node;
        head->next=NULL;
        node *p=head;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            printf("%d ",num);
            if(p==head)
            {
                node *temp=new node;
                temp->data=num;
                temp->next=NULL;
                p->next=temp;
                p=p->next;
            }
            else
            {
                if(p->data!=num)
                {
                    node *temp=new node;
                    temp->data=num;
                    temp->next=NULL;
                    p->next=temp;
                    p=p->next;
                }
            }
        }
        printf("\n");
        node *it=head->next;
        while(it!=NULL)
        {
            printf("%d ",it->data);
            it=it->next;
        }
        printf("\n");
    }
    return 0;
}

