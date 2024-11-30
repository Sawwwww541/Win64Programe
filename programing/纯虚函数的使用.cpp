#include<iostream>

class primer
{
    public:
        int A;
        primer(int a=0):A(a){}
        virtual void swap(int *x,int *y)=0;//用作接口的纯虚函数

};

class passby:public primer
{
    public:
        void swap(int *x,int *y) override
        {
            int temp=*x;
            *x=*y;
            *y=temp;
            std::cout<<"x="<<*x;
            std::cout<<"\ny="<<*y;
        }

};
//有无override其实都一样，用统一接口在不同类下覆写的函数实例互不干扰
class passby2:public passby
{
    public:
        void swap(int *x,int *y)
        {

            std::cout<<"\nx2="<<*x;
            std::cout<<"\ny2="<<*y;

        }


};
//接口与函数重载最大的区别就在于无需修改任何东西即可实现同名函数的不同定义
int main()
{   
    int x=1,y=2;
    int *px=&x,*py=&y;
    passby first;
    passby2 second;
    first.swap(px,py);
    second.swap(px,py);
    first.swap(px,py);

}