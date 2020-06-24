#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=510;
int a[maxn],ser[maxn];
struct node
{
    int data;
    int height;
    node *lchild;
    node *rchild;
};
node *newnode(int data)
{
    node *Node=new node;
    Node->data=data;
    Node->height=1;
    Node->lchild=NULL;
    Node->rchild=NULL;
    return Node;
}
int getheight(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->height;
}
int getbalancefactor(node *root)
{
    return getheight(root->lchild)-getheight(root->rchild);
}
void updateheight(node *root)
{
    root->height=max(getheight(root->lchild),getheight(root->rchild))+1;
}
void L(node *&root)
{
    node *temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateheight(root);
    updateheight(temp);
    root=temp;
}
void R(node *&root)
{
    node *temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    updateheight(root);
    updateheight(temp);
    root=temp;
}
void inser(node *&root,int x)
{
    if(root==NULL)
    {
        root=newnode(x);
        return;
    }
    if(x<root->data)
    {
        inser(root->lchild,x);
        updateheight(root);
        if(getbalancefactor(root)==2)
        {
            if(getbalancefactor(root->lchild)==1)//LL
            {
                R(root);
            }
            else if(getbalancefactor(root->lchild)==-1)//LR
            {
                L(root->lchild);
                R(root);
            }
        }
    }
    else
    {
        inser(root->rchild,x);
        updateheight(root);
        if(getbalancefactor(root)==-2)
        {
            if(getbalancefactor(root->rchild)==-1)//RR
            {
                L(root);
            }
            else if(getbalancefactor(root->rchild)==1)//RL
            {
                R(root->rchild);
                L(root);
            }
        }
    }
}
node *create(int a[],int n)
{
    node *root=NULL;
    for(int i=0;i<n;i++)
    {
        inser(root,a[i]);
    }
    return root;
}
void sear(node *root,int x)
{
    if(root==NULL)
    {
        printf("0 ");
        return;
    }
    if(x==root->data)
    {
        printf("1 ");
    }
    else if(x<root->data)
    {
        sear(root->lchild,x);
    }
    else
    {
        sear(root->rchild,x);
    }
}
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d",&ser[i]);
        }
        node *root=create(a,n);
        for(int i=0;i<k;i++)
        {
            sear(root,ser[i]);
        }
        printf("\n");
    }
    return 0;
}
