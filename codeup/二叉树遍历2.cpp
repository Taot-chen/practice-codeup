#include<cstdio>
#include<iostream>
char pre[300];
int i;
struct node
{
    char charactor;
    node *lchild;
    node *rchild;
};
void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->lchild);
    printf("%c ",root->charactor);
    inorder(root->rchild);
}
node *creat()
{
    //int i=0;
    if(pre[i]=='#')
    {
        i++;
        return NULL;
    }
    node *root=new node;
    root->charactor=pre[i];
    i++;
    root->lchild=creat();
    root->rchild=creat();
    return root;
}
int main()
{
    while(scanf("%s",pre)!=EOF)
    {
        i=0;
        node *root=creat();
        inorder(root);
        printf("\n");
    }
    return 0;
}
