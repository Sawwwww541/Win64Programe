#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define bool char
#define ture 1
#define fales 0
#define maxsize 50

typedef int element;
typedef struct stack{
    element data[maxsize];//栈数组
    int top;//栈指针
}Stack;

void initStack(Stack *s);
bool checkStack(Stack *s);
void pushStack(Stack *s);
void popStack(Stack *s);


int main(){
    int n=0,i=0,j=0;
    Stack *s=(Stack*)malloc(sizeof(Stack));

    initStack(s);
    std::cout<<"请输入入栈元素个数："<<std::endl;
    std::cin>>n;
    for(i=0;i<n;i++){
        pushStack(s);
    }
    std::cout<<"请输入出栈元素个数："<<std::endl;
    std::cin>>j;
    for(i=0;i<j;i++){
        popStack(s);
    }
    return 0;
}



//栈初始化
void initStack(Stack *s){
    s->top=-1;
}
//检查栈
bool checkStack(Stack *s){
    if(s->top==sizeof(s->data)/sizeof(s->data[0])) return fales;
    else return ture;
}
//入栈
void pushStack(Stack *s){
    bool num=checkStack(s);
    element ele;
    if(num==ture){
        std::cout<<"输入您要入栈的数：";
        std::cin>>ele;
        s->data[++(s->top)]=ele;
    }else std::cout<<"栈已满\n";
}
//出栈
void popStack(Stack *s){
    element temp;
    if(s->top!=-1){
        temp=s->data[s->top];
        s->data[(s->top)--]=0;
        std::cout<<"弹出的数为："<<temp<<"\n";
    }else std::cout<<"栈已空\n";
}


