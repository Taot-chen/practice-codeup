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
vector<int>pre,in,post,origin;//三者分别存储前中后序序列和题目给定的数据
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
void postorder(node *root,vector<int>&res)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->lchild,res);
    postorder(root->rchild,res);
    res.push_back(root->data);
}
int main()
{
    int n,data;
    while(scanf("%d",&n)!=EOF)
    {
        node *root=NULL;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&data);
            origin.push_back(data);
            inser(root,data);
        }
        preorder(root,pre);
        inorder(root,in);
        postorder(root,post);
        for(int i=0;i<n;i++)
        {
            printf("%d ",pre[i]);
        }
        printf("\n");
        for(int i=0;i<n;i++)
        {
            printf("%d ",in[i]);
        }
        printf("\n");
        for(int i=0;i<n;i++)
        {
            printf("%d ",post[i]);
        }
        printf("\n");
        origin.clear();
        pre.clear();
        in.clear();
        post.clear();
    }
    return 0;
}
