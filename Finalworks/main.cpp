/*所有功能模块都将被封装成函数，放置在头文件中
源文件的主要功能是构建程序运行时的基本框架，即代码的运行逻辑和模块间的排列组合方式*/
#include "HomeFeeMsg.hpp"

int main()
{
    Homemember *head=new Homemember;

    while(1){
        
        //为了维持初始主界面的死循环
        int n=0,num=0,judgement=0;
        char isprint='n';
        usrmenu();
        std::cin>>n;

        switch (n)
        {
        case 1:
        //查找
        /*为了实现二级菜单的滞留与可返回性，使用函数封装一个菜单死循环,
         *这样在需要返回初始菜单时return当前函数即可*/
            findtotal(head);
            break;
        case 2:
        //排序
            head=rank(head);
            printall(head,isprint);
            system("pause");
            system("cls");
            break;
        case 3:
        //统计
        //这里选择与查找函数群类似的结构
            sumtotal(head);
            break;
        case 4:
        //增加
            std::cout<<"请输入要增加的条目数："<<std::endl;
            std::cin>>num;
            for(int i=0;i<num;i++)
            {
                add(head);
            }
        //保存数据
            save(head);
            break;
        case 5:
        //更新
            std::cout<<"更改(输入0)还是删除(输入1)？"<<std::endl;
            std::cin>>judgement;
            change(head,judgement);
            break;
        case 6:
            return 0;
            break;
        default:
            std::cout<<"请输入有效指令"<<std::endl;
        }
    }

    return 0;
}
