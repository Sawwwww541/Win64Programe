#include<iostream>

typedef struct Treenode
{
    int value;
    struct Treenode *left=nullptr;
    struct Treenode *right=nullptr;

}Treenode;

void front(Treenode *root);
void mid(Treenode *root);
void behind(Treenode *root);

int main()
{
        Treenode *root=new Treenode;
        Treenode *lchild1=new Treenode;
        Treenode *rchild1=new Treenode;
        Treenode *lchild1_lchild2=new Treenode;
        Treenode *lchild1_rchild2=new Treenode;
        Treenode *rchild1_lchild2=new Treenode;
        Treenode *rchild1_rchild2=new Treenode;
    
    root->left=lchild1;
    root->right=rchild1;
    lchild1->left=lchild1_lchild2;
    lchild1->right=lchild1_rchild2;
    rchild1->left=rchild1_lchild2;
    rchild1->right=rchild1_rchild2;

    root->value=5;
    lchild1->value=8;
    rchild1->value=3;
    lchild1_lchild2->value=4;
    lchild1_rchild2->value=7;
    rchild1_lchild2->value=2;
    rchild1_rchild2->value=1;

    front(root);
    std::cout<<"\n";
    mid(root);
    std::cout<<"\n";
    behind(root);

    return 0;
}

// 前序遍历
void front(Treenode *root){
    if(root==nullptr)
        return;
    std::cout<<root->value;
    front(root->left);
    front(root->right);
}

//中序遍历
void mid(Treenode *root){
    if(root==nullptr)
        return;
    
    mid(root->left);
    std::cout<<root->value;
    mid(root->right);

}

//后序遍历
void behind(Treenode *root){
    if(root==nullptr)
        return;
    behind(root->left);
    behind(root->right);
    std::cout<<root->value;

}
