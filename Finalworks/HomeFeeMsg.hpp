/*注意：乱码是因为vscode默认的文件编码格式是UTF-8，而Windows的终端默认编码格式是gbk，两种格式冲突导致乱码；
解决办法就是修改vscode默认设置，与Windows终端同步即可*/
#include <iostream>
#include <memory>
#include <string>

//日期类
class Date
{
    public:
        Date():year(0),month(0),day(0){}
        int year;
        int month;
        int day;
};

//成员类
class Homemember : public Date
{
    public:
        Homemember():ID("none"),amount(0.0),type("none"),method("none"),
        site("none"),detail("none"),next(nullptr){}

        void entermsgs(Homemember *temp)
        {
            //启动一下菜单

            //录入数据
            std::cout<<"请输入消费日期（例：xxxx x x）："<<std::endl;
            std::cin>>temp->year>>temp->month>>temp->day;

            std::cout<<"请输入成员信息："<<std::endl;
            std::cin>>temp->ID;

            std::cout<<"请输入消费金额："<<std::endl;
            std::cin>>temp->amount;

            std::cout<<"请输入消费品类："<<std::endl;
            std::cin>>temp->type;

            std::cout<<"请输入支出方式："<<std::endl;
            std::cin>>temp->method;

            std::cout<<"请输入消费场所："<<std::endl;
            std::cin>>temp->site;

            std::cout<<"请输入商品详情："<<std::endl;
            std::cin>>temp->detail;

        }
    
        std::string ID;
        double amount;
        std::string type;
        std::string method;
        std::string site;
        std::string detail;
        Homemember *next;
};

void usrmenu();
void findmenu();
void summenu();
void findtotal(Homemember *head);
void find1(Homemember *head);
void find2(Homemember *head);
void find3(Homemember *head);
void find4(Homemember *head);
Homemember* rank(Homemember *head);
Homemember* midsearch(Homemember *head);
Homemember* merge(Homemember *head1,Homemember *head2);
void sumtotal(Homemember *head);
double sum1(Homemember *head);
double sum2(Homemember *head);
double sum3(Homemember *head);
void printmsgs(Homemember *target);
void save(Homemember *head);

//初始用户界面--一级菜单
void usrmenu()
{
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"欢迎使用家庭消费管理系统，请根索引选择对应服务"<<std::endl;
    std::cout<<"1----查询 2----排序 3----统计 4----录入 5----更新 6----退出"<<std::endl;
    std::cout<<"**************************************************************************"<<std::endl;
}


//查询菜单--二级菜单
void findmenu()
{
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"11----按日期区间段查询              12----按交易金额查询"<<std::endl;
    std::cout<<"13----按家庭成员加日期区间查询      14----按消费品类加日期区间查询"<<std::endl;
    std::cout<<"15----返回上级菜单"<<std::endl;
    std::cout<<"**************************************************************************"<<std::endl;
}


//统计菜单--二级菜单
void summenu() 
{
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"31----给定时间段家庭消费总额统计        32----特定成员在给定时间段消费总额统计"<<std::endl;
    std::cout<<"33----特定品类在给定时间段消费总额统计     34----返回上级菜单"<<std::endl;
    std::cout<<"**************************************************************************"<<std::endl;
}

//录入函数群(录入并保存到文件)
void add(Homemember *head)
{
    //移动指针，利用尾插法增添链表节点
    auto *temp=new Homemember;
    auto *move=head;

    while(move->next!=nullptr) 
    {
        move=move->next;
    }

    temp->entermsgs(temp);
    move->next=temp;
                
}

//查询函数群(1.起止日期2.金额3.某人+起止日期4.某物+起止日期)
void findtotal(Homemember *head) 
{

    int choice=0;

    while(1){

        findmenu();
        std::cin>>choice;

        switch (choice)
        {
        case 11 :
            find1(head);
            break;
        case 12 :
            find2(head);
            break;
        case 13 :
            find3(head);
            break;
        case 14 :
            find4(head);
            break;
        case 15 :
            system("cls");
            return;
            break;
        default:
            std::cout<<"请输入有效指令"<<std::endl;
            break;
        }
    }

}
//日期
void find1(Homemember *head)
{
    auto *move=head->next;
    int year=0,month=0,day=0,temp=0;

    std::cout<<"请输入消费日期（例：xxxx x x）："<<std::endl;
    std::cin>>year>>month>>day;

    while(move!=nullptr)
    {
        if(year==move->year&&month==move->month&&day==move->day)
        {
            //打印消费记录
            printmsgs(move);
            temp++;
        }

        move=move->next;
    }
    if(temp==0)
    {
        //输出错误
        std::cout<<"未找到相关消费记录，即将返回查找导航菜单"<<std::endl;
        system("pause");
        system("cls");
    }
}
//金额
void find2(Homemember *head)
{
    auto *move=head->next;
    double amount=0.0;
    int temp=0;

    std::cout<<"请输入消费金额："<<std::endl;
    std::cin>>amount;

    while(move!=nullptr)
    {
        if(amount==move->amount)
        {
            //打印
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //输出错误
        std::cout<<"未找到相关消费记录，即将返回查找导航菜单"<<std::endl;
        system("pause");
        system("cls");
    }

}
//人+日期
void find3(Homemember *head)
{
    auto *move=head->next;
    std::string ID;
    int year=0,month=0,day=0,temp=0;

    std::cout<<"请输入消费日期（例：xxxx x x）："<<std::endl;
    std::cin>>year>>month>>day;
    std::cout<<"请输入成员信息："<<std::endl;
    std::cin>>ID;

    while(move!=nullptr)
    {
        if(year==move->year&&month==move->month&&day==move->day&&ID==move->ID)
        {
            //打印消费记录
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //输出错误
        std::cout<<"未找到相关消费记录，即将返回查找导航菜单"<<std::endl;
        system("pause");
        system("cls");
    }
}
//物+日期
void find4(Homemember *head)
{
    auto *move=head->next;
    std::string type;
    int year=0,month=0,day=0,temp=0;

    std::cout<<"请输入消费日期（例：xxxx x x）："<<std::endl;
    std::cin>>year>>month>>day;
    std::cout<<"请输入消费品类："<<std::endl;
    std::cin>>type;

    while(move!=nullptr)
    {
        if(year==move->year&&month==move->month&&day==move->day&&type==move->type)
        {
            //打印消费记录
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //输出错误
        std::cout<<"未找到相关消费记录，即将返回查找导航菜单"<<std::endl;
        system("pause");
        system("cls");
    }

}
//排序函数群(按交易日期升序)
//采用归并排序
Homemember* rank(Homemember *head) 
{
    if(head==nullptr||head->next==nullptr) return head;

    Homemember *head1=head;
    Homemember *head2=midsearch(head);

    head1=rank(head1);
    head2=rank(head2);

    return merge(head1,head2);

}
//查找链表中点
Homemember* midsearch(Homemember *head)
{
    Homemember *slow=head,*fast=head->next;

    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    Homemember *mid=slow->next;
    slow->next=nullptr;         //切断中点与另一半的链接

    return mid;
}

Homemember* merge(Homemember *head1,Homemember *head2)
{
    Homemember *temp=new Homemember(),*p=temp;

    while(head1!=nullptr&&head2!=nullptr)
    {
        if(head1->year<=head2->year)
        {
            if(head1->month<=head2->month)
            {
                if(head1->day<=head2->day)
                {
                    p->next=head1;
                    head1=head1->next;
                }
                else
                {
                    p->next=head2;
                    head2=head2->next;
                }
            }
            else
            {
                p->next=head2;
                head2=head2->next;
            }
        }
        else
        {
            p->next=head2;
            head2=head2->next;
        }
        p=p->next;
    }

    if(head1!=nullptr) p->next=head1;
    else p->next=head2;

    Homemember *ret=temp->next;
    delete temp;
    temp=nullptr;
    return ret;

}

//统计函数群(求某一条件下的总金额)
void sumtotal(Homemember *head) 
{
    int choice=0;
    
    while(1)
    {
        summenu();
        double sumamount=0.0;
        std::cin>>choice;
        switch (choice)
        {
        case 31 :
            sumamount=sum3(head);
            break;
        case 32 :
            sumamount=sum1(head);
            break;
        case 33 :
            sumamount=sum2(head);
            break;
        case 34 :
            system("cls");
            return;
            break;
        default:
            std::cout<<"请输入有效指令"<<std::endl;
        }

        std::cout<<"统计完毕，符合条件的消费金额总数为："<<sumamount<<"元"<<std::endl;
    }
}

//谁+时间段
double sum1(Homemember *head)
{
    auto *move=head->next;
    Date begin,end;
    std::string ID;
    double sumamount=0.0;

    std::cout<<"请输入家庭成员："<<std::endl;
    std::cin>>ID;
    std::cout<<"请输入起始时间："<<std::endl;
    std::cin>>begin.year>>begin.month>>begin.day;
    std::cout<<"请输入终止时间："<<std::endl;
    std::cin>>end.year>>end.month>>end.day;

    while(move!=nullptr)
    {
        if(move->ID==ID&&move->year>=begin.year&&move->month>=begin.month&&move->day>=begin.day&&
            move->year<=end.year&&move->month<=end.month&&move->day<=end.day)
            {
                printmsgs(move);
                sumamount+=move->amount;
            }
        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"未找到对应消费记录"<<std::endl;
    
    return sumamount;
}

//品类+时间段
double sum2(Homemember *head)
{
    auto *move=head->next;
    Date begin,end;
    std::string type;
    double sumamount=0.0;

    std::cout<<"请输入消费品类："<<std::endl;
    std::cin>>type;
    std::cout<<"请输入起始时间："<<std::endl;
    std::cin>>begin.year>>begin.month>>begin.day;
    std::cout<<"请输入终止时间："<<std::endl;
    std::cin>>end.year>>end.month>>end.day;

    while(move!=nullptr)
    {
        if(move->type==type&&move->year>=begin.year&&move->month>=begin.month&&move->day>=begin.day&&
            move->year<=end.year&&move->month<=end.month&&move->day<=end.day)
            {
                printmsgs(move);
                sumamount+=move->amount;
            }
        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"未找到对应消费记录"<<std::endl;

    return sumamount;
}

//时间段
double sum3(Homemember *head)
{
    auto *move=head->next;
    Date begin,end;
    double sumamount=0.0;

    std::cout<<"请输入起始时间："<<std::endl;
    std::cin>>begin.year>>begin.month>>begin.day;
    std::cout<<"请输入终止时间："<<std::endl;
    std::cin>>end.year>>end.month>>end.day;

    while(move!=nullptr)
    {
        if(move->year>=begin.year&&move->month>=begin.month&&move->day>=begin.day&&
            move->year<=end.year&&move->month<=end.month&&move->day<=end.day)
            {
                printmsgs(move);
                sumamount+=move->amount;
            } 
        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"未找到对应消费记录"<<std::endl;

    return sumamount;
}


//更新函数群(修改并保存到文件,或者删除某一结点)
//可以内联一些函数
void change(Homemember *head,int& judgement) 
{
    std::string ID,type;
    double amount;
    int year=0,month=0,day=0;
    auto *target=head->next,*slow=head;
    char yesorno='n';

    //更详细的搜索模块，防止修改到一个以上的条目

    std::cout<<"请输入相关信息，以便定位您要修改的条目"<<std::endl;
    std::cout<<"请输入消费日期（例：xxxx x x）："<<std::endl;
    std::cin>>year>>month>>day;    
    std::cout<<"成员身份："<<std::endl;
    std::cin>>ID;
    std::cout<<"消费金额："<<std::endl;
    std::cin>>amount;
    std::cout<<"消费品类："<<std::endl;
    std::cin>>type;

    while(target!=nullptr)
    {
        if(year==target->year&&month==target->month&&day==target->day&&ID==target->ID
        &&amount==target->amount&&type==target->type)
        {
            //打印消费记录
            printmsgs(target);
            break;
        }
        slow=target;
        target=target->next;
    }
    if(target==nullptr)
    {
        //输出错误
        std::cout<<"未找到相关消费记录，即将返回"<<std::endl;
        system("pause");
        system("cls");
        return;
    }

    if(judgement==0)
    {
        std::cout<<"请输入更改后的数据"<<std::endl;
        target->entermsgs(target);
        std::cout<<"修改成功"<<std::endl;
    }
    else
    {
        std::cout<<"确认删除？[y/n]"<<std::endl;
        std::cin>>yesorno;
        if(yesorno=='y')
        {
            slow->next=target->next;
            delete target;
            target=nullptr;
        }else
        {
            std::cout<<"取消删除，即将返回"<<std::endl;
            system("pause");
            system("cls");
            return;
        }
    }

}

//信息打印函数
void printmsgs(Homemember *target)
{
    std::cout<<"-------------------------------------"<<std::endl;
    std::cout<<"消费日期："<<target->year<<" "<<target->month<<" "<<target->day<<std::endl;
    std::cout<<"成员身份："<<target->ID<<std::endl;
    std::cout<<"消费金额："<<target->amount<<std::endl;
    std::cout<<"消费品类："<<target->type<<std::endl;
    std::cout<<"支出方式："<<target->method<<std::endl;
    std::cout<<"消费场所："<<target->site<<std::endl;
    std::cout<<"商品详情："<<target->detail<<std::endl;
    std::cout<<"-------------------------------------"<<std::endl;
}
//用于排序后的打印函数，封装起来好看一点
void printall(Homemember *head,char& isprint)
{
    std::cout<<"已按消费日期升序，是否打印信息？[y/n]"<<std::endl;
    std::cin>>isprint;
    if(isprint=='y')
    {
        Homemember *move=head->next;
        while(move!=nullptr)
        {
            printmsgs(move);
            move=move->next;
        }
    }
    return;
}

//文件IO
void save(Homemember *head)
{
    FILE *file=fopen("./fee.dat","w+");
    if(file==nullptr) 
    {
        std::cout<<"文件打开失败"<<std::endl;
        return;
    }
    Homemember *move=head->next;
    while(move!=nullptr) 
    {
        if(fwrite(&move,sizeof(Homemember),1,file)!=1) 
        {
            std::cout<<"写入失败"<<std::endl;
            return;
        }
        move=move->next;
    }
    fclose(file);
}
