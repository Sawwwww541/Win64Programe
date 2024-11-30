#include<iostream>
#include<vector>

void ForEach(const std::vector<int>& func1,void(*funcp)(int))
{
    for(int value : func1)//每一次迭代，局部变量都会被赋予该容器的下一个值，：表示对于容器中的每一个元素，func1是被遍历的容器。
        funcp(value);
}
void HelloWorld(int a)
{
    std::cout<<"Hello World! Value:"<<a<<std::endl;

}
void Printvalue(int a)
{
    std::cout<<"Value:"<<a<<std::endl;
}

int main()
{
    std::vector<int> func1={1,1,7,0,9,1,9,9,6,7};
    ForEach(func1,Printvalue);
    //lambda--临时函数的使用
    /*ForEach(func1,[](int value)Printvalues {std::cout<<"Value:"<<value<<std::endl;})*/
    //运用上面的做法可以达到与将Printvalue函数直接输入指针并访问同样的效果
    //即直接在参数表里实现一个函数定义并调用；
    //需要一个函数指针才能使用lambda
    //[] 捕获，用于引用或者传值 [=] 传递所有值 [&] 引用所有值
    std::cin.get();

}