#include"StudentMessage.hpp"

int main()
{
    
    int n=0;

       //初始化链表头指针
    Student *head=new Student;
    head->next=nullptr;

    Guide();
    while(1)
    {
        std::cin>>n;
        switch (n)
        {
        case 1:
            //增加学生信息
            AddStudent(head);

            break;
        case 2:
            //删除学生信息
            DelStudent(head);

        
            break;
        case 3:
            //修改学生信息
            ChangeMessage(head);

            break;
        case 4:
            //查找学生信息
            while(1)
            {   
                int num=0;
                Select_guide();
                getchar();
                std::cin>>n;
                switch(num)
                {
                    case 1:
                        //按名字
                        SeleStudent_name(head);
                        break;
                    case 2:
                        //按学号
                        SeleStudent_id(head);
                        break;
                    case 3:
                        //按分数
                        SeleStudent_score(head);
                        break;
                    case 4:
                    
                        break;
                    default:
                        std::cout<<"请输入有效指令";
                        break;
                
                }
            }

            break;
        case 5:
            //打印所有学生信息
            PrintStudent(head);
            
        
            break;

        case 6:
            return 0;
            break;
        default:
            std::cout<<"请输入有效指令\n";
            break;
        }
    }

}



