/*���й���ģ�鶼������װ�ɺ�����������ͷ�ļ���
Դ�ļ�����Ҫ�����ǹ�����������ʱ�Ļ�����ܣ�������������߼���ģ����������Ϸ�ʽ*/
#include "D:\My_programe\Finalworks\src\HomeFeeMsg.hpp"

int main()
{
    Homemember *head=new Homemember;        //ͷ�ڵ㲻�����Ч����
    ofile(head);                            //����������������

    while(1){                               //Ϊ��ά�ֳ�ʼ���������ѭ��
        int n=0,num=0,judgement=0;
        char isprint='n';
        usrmenu();
        std::cin>>n;

        switch (n)
        {
        case 1:
            findtotal(head);                //����
                                            /*Ϊ��ʵ�ֶ����˵���������ɷ����ԣ�ʹ�ú�����װһ���˵���ѭ��,
                                             *��������Ҫ���س�ʼ�˵�ʱreturn��ǰ��������*/
            break;
        case 2:                             //����
            head=rank(head);
            printall(head,isprint);
            system("pause");
            system("cls");
            break;
        case 3:                             /*ͳ��;
                                            *����ѡ������Һ���Ⱥ���ƵĽṹ*/
            sumtotal(head);
            break;
        case 4:                             //����
            std::cout<<"������Ҫ���ӵ���Ŀ����"<<std::endl;
            std::cin>>num;
            for(int i=0;i<num;i++)
            {
                add(head);
            }
            break;
        case 5:                             //����
            std::cout<<"����(����0)����ɾ��(����1)��"<<std::endl;
            std::cin>>judgement;
            change(head,judgement);
            break;
        case 6:                             //�������򣬱������ݣ��ͷ��ڴ�
            ifile(head);
            Deletelist(head);
            return 0;
            break;
        default:
            std::cout<<"��������Чָ��"<<std::endl;
        }
    }

    return 0;
}
