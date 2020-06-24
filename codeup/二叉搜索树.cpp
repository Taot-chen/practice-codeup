#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int data;
    node *rchild;
    node *lchild;
};
vector<int>pre,in,pre1,in1;
void inser(node *&root,int x)
{
    if(root==NULL)
    {
        root=new node;
        root->data=x;
        root->lchild=NULL;
        root->rchild=NULL;
        return;
    }
    if(x==root->data)
    {
        return;
    }
    else if(x<root->data)
    {
        inser(root->lchild,x);
    }
    else
    {
        inser(root->rchild,x);
    }
}
void preorder(node *root,vector<int>&res)
{
    if(root==NULL)
    {
        return;
    }
     res.push_back(root->data);
     preorder(root->lchild,res);
     preorder(root->rchild,res);
}
void inorder(node *root,vector<int>&res)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->lchild,res);
    res.push_back(root->data);
    inorder(root->rchild,res);
}
int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        pre.clear();
        in.clear();
        char temp[20];
        scanf("%s",temp);
        int k=0;
        while(temp[k]!='\0')
        {
            k++;
        }
        int data;
        node *root=NULL;
        for(int i=0;i<k;i++)
        {
            data=temp[i]-'0';
            inser(root,data);
        }
        preorder(root,pre);
        inorder(root,in);
        for(int i=0;i<n;i++)
        {
            pre1.clear();
            in1.clear();
            char example[20];
            int m;
            node *root1=NULL;
            scanf("%s",example);
            for(int j=0;j<k;j++)
            {
                m=example[j]-'0';
                inser(root1,m);
            }
            preorder(root1,pre1);
            inorder(root1,in1);
            if(pre==pre1&&in==in1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
