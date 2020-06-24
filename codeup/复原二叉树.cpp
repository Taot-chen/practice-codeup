#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100;
char pre[maxn],in[maxn],post[maxn];
int n;
struct node
{
    char charactor;
    node *lchild;
    node *rchild;
};
node* creat(int preL,int preR,int inL, int inR)
{
    if(preL>preR)
    {
        return NULL;
    }
    node *root=new node;
    root->charactor=pre[preL];
    int k;
    for(k=inL;k<inR;k++)
    {
        if(in[k]==pre[preL])
        {
            break;
        }
    }
    int numleft=k-inL;
    //下面开始分别建立左子树和右子树
    //左子树在中序序列中的范围是[inL,k-1],在先序序列中的范围是[preL+1,preL+numleft]
    //右子树在中序序列中的范围是[k+1,inR],在先序序列中的范围是[preL+numleft+1,preR]
    root->lchild=creat(preL+1,preL+numleft,inL,k-1);
    root->rchild=creat(preL+numleft+1,preR,k+1,inR);
    return root;
}
void postorder(node *root)
{
    if(root==NULL)
    {
        //printf("\n");
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%c",root->charactor);
}
int main()
{
    while(scanf("%s",pre)!=EOF)
    {
        //getchar();
        scanf("%s",in);
        node *root=creat(0,strlen(pre)-1,0,strlen(in)-1);
        postorder(root);
        printf("\n");
    }
    return 0;
}
