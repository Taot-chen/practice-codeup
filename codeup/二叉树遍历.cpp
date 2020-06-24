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
    //���濪ʼ�ֱ�����������������
    //�����������������еķ�Χ��[inL,k-1],�����������еķ�Χ��[preL+1,preL+numleft]
    //�����������������еķ�Χ��[k+1,inR],�����������еķ�Χ��[preL+numleft+1,preR]
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
