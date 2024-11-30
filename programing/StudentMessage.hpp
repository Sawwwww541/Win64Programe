#include<iostream>
#include<string>
#include<vector>

typedef struct _Student
{
    std::string name;
    std::string id;
    int age;
    std::string grade;
    double score;
    struct _Student *next;
}Student;

//初始交互页面
void Guide()
{
    std::cout<<"欢迎使用学生信息管理系统\n";
    std::cout<<"请根据指引选择您需要的服务\n";
    std::cout<<"输入“1”增加学生信息\n";
    std::cout<<"输入“2”删除学生信息\n";
    std::cout<<"输入“3”修改学生信息\n";
    std::cout<<"输入“4”查找学生信息\n";
    std::cout<<"输入“5”打印所有学生信息\n";
    std::cout<<"输入“6”结束程序\n";

}

//增
void AddStudent(Student *head)
{
    Student *move=head;
    Student *fresh=new Student;
    fresh->next=nullptr;
    
    std::cout<<"请输入学生姓名：";
    std::cin>>fresh->name;
    std::cout<<"请输入学生学号：";
    std::cin>>fresh->id;
    std::cout<<"请输入学生年龄：";
    std::cin>>fresh->age;
    std::cout<<"请输入学生年级：";
    std::cin>>fresh->grade;
    std::cout<<"请输入学生期末考试成绩：";
    std::cin>>fresh->score;
    std::cout<<"信息录入成功，即将返回主菜单\n";

    while(move->next!=nullptr)
        {
            move=move->next;
        }
    move->next=fresh;
    system("pause");
    system("cls");
    Guide();
}

//删
void DelStudent(Student *head)
{
    Student *move=head->next;
    Student *prior=nullptr;
    std::string name;
    std::string id;
    char judge='n';
    int num=0;

    std::cout<<"请输入要删除学生的姓名：";
    std::cin>>name;
    std::cout<<"请输入要删除学生的学号：";
    std::cin>>id;

    while(move!=nullptr)
    {   
        prior=move;
        
        if(move->name==name&&move->id==id)
        {
            num=1;

            std::cout<<"为您找到如下学生信息";
            std::cout<<"\n姓名："<<move->name<<"\n学号："<<move->id<<"\n年龄："<<move->age<<"\n年级："<<move->grade<<"\n成绩："<<move->score;
            
            std::cout<<"确定删除以上学生信息？[y/n]";
            std::cin>>judge;

            if(judge=='y')
            {
                prior->next=move->next;
                delete(move);
                move=nullptr;
                system("cls");

            }else return;

            break;

        }
        move=move->next;
    }

    if(num==0)
    {
        std::cout<<"\n未找到学生信息，即将返回引导界面";
        system("pause");
        system("cls");
    }

    Guide();
}

//修改学生信息
void ChangeMessage(Student *head)
{
    Student *move=head->next;
    std::string name;
    std::string id;

    std::cout<<"请输入您要修改的学生的姓名：";
    std::cin>>name;
    std::cout<<"请输入您要修改的学生的学号：";
    std::cin>>id;

    while(move!=nullptr)
    {
        if(name==move->name&&id==move->id)
        {
            std::cout<<"为您找到如下学生信息：";
            std::cout<<"\n姓名："<<move->name;
            std::cout<<"\n学号："<<move->id;
            std::cout<<"\n年龄："<<move->age;
            std::cout<<"\n年级："<<move->grade;
            std::cout<<"\n期末考试成绩："<<move->score;

            std::cout<<"请输入修改后的信息：";
            std::cout<<"\n姓名：";
            std::cin>>move->name;
            std::cout<<"\n学号：";
            std::cin>>move->id;
            std::cout<<"\n年龄：";
            std::cin>>move->age;
            std::cout<<"\n年级：";
            std::cin>>move->grade;
            std::cout<<"\n期末考试成绩：";
            std::cin>>move->score;

            std::cout<<"\n信息修改完毕!";

            break;
        }
        move=move->next;
    }
    if(move==nullptr)
        std::cout<<"\n未找到学生信息，请您确认信息是否正确。";

    std::cout<<"即将返回";
    system("pause");
    system("cls");
    Guide();

}

//查找有点问题记得改
//查找表
void Select_guide()
{
    std::cout<<"欢迎来到学生查找系统";
    std::cout<<"\n输入“1”按名称查找";
    std::cout<<"\n输入“2”按学号查找";
    std::cout<<"\n输入“3”按成绩查找";
    std::cout<<"\n输入“4”返回主菜单";

}

//按名称查找
void SeleStudent_name(Student *head)
{
    Student *move=head->next;
    std::string name;
    char judge=0;

    std::cout<<"\n请输入查找的学生名称";
    std::cin>>name;

    while(move!=nullptr)
    {
        
        if(move->name==name)
        {
            std::cout<<"\n为您找到如下学生信息";
            std::cout<<"\n姓名："<<move->name<<"\n学号："<<move->id<<"\n年龄："<<move->age<<"\n年级："<<move->grade<<"\n成绩："<<move->score;
            judge=1;

        }
        move=move->next;
    }

    if(judge==0)
    {
        std::cout<<"\n未找到学生信息，即将返回";
        system("pause");
        system("cls");
    }

}

//按学号查找
void SeleStudent_id(Student *head)
{
    Student *move=head->next;
    std::string id;
    char judge=0;

    std::cout<<"\n请输入查找的学生学号";
    std::cin>>id;

    while(move!=nullptr)
    {
        
        if(move->id==id)
        {
            std::cout<<"\n为您找到如下学生信息";
            std::cout<<"\n姓名："<<move->name<<"\n学号："<<move->id<<"\n年龄："<<move->age<<"\n年级："<<move->grade<<"\n成绩："<<move->score;
            judge=1;

        }
        move=move->next;
    }

    if(judge==0)
    {
        std::cout<<"\n未找到学生信息，即将返回";
        system("pause");
        system("cls");
    }

}

//按成绩查找
void SeleStudent_score(Student *head)
{
    Student *move=head->next;
    std::string id;
    char judge=0;

    std::cout<<"\n请输入查找的学生学号";
    std::cin>>id;

    while(move!=nullptr)
    {
        
        if(move->id==id)
        {
            std::cout<<"为您找到如下学生信息";
            std::cout<<"\n姓名："<<move->name<<"\n学号："<<move->id<<"\n年龄："<<move->age<<"\n年级："<<move->grade<<"\n成绩："<<move->score;
            judge=1;

        }
        move=move->next;
    }

    if(judge==0)
    {
        std::cout<<"\n未找到学生信息，即将返回";
        system("pause");
        system("cls");
    }

}

//打印
//如果链表为空，此时打印将乱码。根本原因在于野指针
void PrintStudent(Student *head)
{
    Student *move=head->next;
    while(move!=nullptr)
    {
        std::cout<<"名字："<<move->name;
        std::cout<<"\n学号："<<move->id;
        std::cout<<"\n年龄："<<move->age;
        std::cout<<"\n年级："<<move->grade;
        std::cout<<"\n期末考试分数："<<move->score<<"\n";
        move=move->next;
        
    }
        system("pause");
        system("cls");
        Guide();
        
}

