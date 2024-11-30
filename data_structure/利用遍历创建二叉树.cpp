#include<iostream>

class Treenode{
    public:
        int value;
        Treenode *left;
        Treenode *right;
};

int main(){


}

//前序遍历
void frontcreate(Treenode *T){

    char judge=0;
    std::cin>>judge;

    if(judge=='#')
        return;

    else{
        T=new Treenode;
        if(!T){
            std::cout<<"Error";
            return;
        }
        frontcreate(T->left);
        frontcreate(T->right);


        
    }
    


}