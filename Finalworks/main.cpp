/*���й���ģ�鶼������װ�ɺ�����������ͷ�ļ���
Դ�ļ�����Ҫ�����ǹ�����������ʱ�Ļ�����ܣ�������������߼���ģ����������Ϸ�ʽ*/
#include "HomeFeeMsg.hpp"

int main()
{
    Homemember *head=new Homemember;

    while(1){
        
        //Ϊ��ά�ֳ�ʼ���������ѭ��
        int n=0,num=0,judgement=0;
        char isprint='n';
        usrmenu();
        std::cin>>n;

        switch (n)
        {
        case 1:
        //����
        /*Ϊ��ʵ�ֶ����˵���������ɷ����ԣ�ʹ�ú�����װһ���˵���ѭ��,
         *��������Ҫ���س�ʼ�˵�ʱreturn��ǰ��������*/
            findtotal(head);
            break;
        case 2:
        //����
            head=rank(head);
            printall(head,isprint);
            system("pause");
            system("cls");
            break;
        case 3:
        //ͳ��
        //����ѡ������Һ���Ⱥ���ƵĽṹ
            sumtotal(head);
            break;
        case 4:
        //����
            std::cout<<"������Ҫ���ӵ���Ŀ����"<<std::endl;
            std::cin>>num;
            for(int i=0;i<num;i++)
            {
                add(head);
            }
        //��������
            save(head);
            break;
        case 5:
        //����
            std::cout<<"����(����0)����ɾ��(����1)��"<<std::endl;
            std::cin>>judgement;
            change(head,judgement);
            break;
        case 6:
            return 0;
            break;
        default:
            std::cout<<"��������Чָ��"<<std::endl;
        }
    }

    return 0;
}
