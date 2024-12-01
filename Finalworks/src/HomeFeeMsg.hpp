/*ע�⣺��������ΪvscodeĬ�ϵ��ļ������ʽ��UTF-8����Windows���ն�Ĭ�ϱ����ʽ��gbk�����ָ�ʽ��ͻ�������룻
����취�����޸�vscodeĬ�����ã���Windows�ն�ͬ������*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//��Ա��
class Homemember
{
    public:
        Homemember():ID("none"),amount(0.0),type("none"),method("none"),
        site("none"),detail("none"),next(nullptr){}

        void entermsgs(Homemember *temp)                        //¼������
        {
            std::cout<<"�������������ڣ�����20240409����"<<std::endl;
            std::cin>>temp->Date;

            std::cout<<"�������Ա��Ϣ��"<<std::endl;
            std::cin>>temp->ID;

            std::cout<<"���������ѽ�"<<std::endl;
            std::cin>>temp->amount;

            std::cout<<"����������Ʒ�ࣺ"<<std::endl;
            std::cin>>temp->type;

            std::cout<<"������֧����ʽ��"<<std::endl;
            std::cin>>temp->method;

            std::cout<<"���������ѳ�����"<<std::endl;
            std::cin>>temp->site;

            std::cout<<"��������Ʒ���飺"<<std::endl;
            std::cin>>temp->detail;

        }
    
        std::string Date;
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


void add(Homemember *head);
Homemember* rank(Homemember *head);
Homemember* midsearch(Homemember *head);
Homemember* merge(Homemember *head1,Homemember *head2);
void change(Homemember *head,int& judgement);


void sumtotal(Homemember *head);
double sum1(Homemember *head);
double sum2(Homemember *head);
double sum3(Homemember *head);


void printmsgs(Homemember *target);
void printall(Homemember *head,char& isprint);


void ifile(Homemember *head);
void ofile(Homemember *head);
void Deletelist(Homemember *head);

//��ʼ�û�����--һ���˵�
void usrmenu()
{
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"��ӭʹ�ü�ͥ���ѹ���ϵͳ���������ѡ���Ӧ����"<<std::endl;
    std::cout<<"1----��ѯ 2----���� 3----ͳ�� 4----¼�� 5----���� 6----�˳�"<<std::endl;
    std::cout<<"**************************************************************************"<<std::endl;
}


//��ѯ�˵�--�����˵�
void findmenu()
{
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"11----����������β�ѯ              12----�����׽���ѯ"<<std::endl;
    std::cout<<"13----����ͥ��Ա�����������ѯ      14----������Ʒ������������ѯ"<<std::endl;
    std::cout<<"15----�����ϼ��˵�"<<std::endl;
    std::cout<<"**************************************************************************"<<std::endl;
}


//ͳ�Ʋ˵�--�����˵�
void summenu() 
{
    std::cout<<"**************************************************************************"<<std::endl;
    std::cout<<"31----����ʱ��μ�ͥ�����ܶ�ͳ��        32----�ض���Ա�ڸ���ʱ��������ܶ�ͳ��"<<std::endl;
    std::cout<<"33----�ض�Ʒ���ڸ���ʱ��������ܶ�ͳ��     34----�����ϼ��˵�"<<std::endl;
    std::cout<<"**************************************************************************"<<std::endl;
}


//��Ϣ��ӡ����
void printmsgs(Homemember *target)
{
    std::cout<<"-------------------------------------"<<std::endl;
    std::cout<<"�������ڣ�"<<target->Date<<std::endl;
    std::cout<<"��Ա��ݣ�"<<target->ID<<std::endl;
    std::cout<<"���ѽ�"<<target->amount<<std::endl;
    std::cout<<"����Ʒ�ࣺ"<<target->type<<std::endl;
    std::cout<<"֧����ʽ��"<<target->method<<std::endl;
    std::cout<<"���ѳ�����"<<target->site<<std::endl;
    std::cout<<"��Ʒ���飺"<<target->detail<<std::endl;
    std::cout<<"-------------------------------------"<<std::endl;
}


//���������Ĵ�ӡ��������װ�����ÿ�һ��
void printall(Homemember *head,char& isprint)
{
    std::cout<<"�Ѱ��������������Ƿ��ӡ��Ϣ��[y/n]"<<std::endl;
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

//��ѯ����Ⱥ(1.��ֹ����2.���3.ĳ��+��ֹ����4.ĳ��+��ֹ����)
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
            std::cout<<"��������Чָ��"<<std::endl;
            break;
        }
    }

}

//����
void find1(Homemember *head)
{
    auto *move=head->next;
    int temp=0;
    std::string Date;

    std::cout<<"�������������ڣ�����20240409����"<<std::endl;
    std::cin>>Date;

    while(move!=nullptr)
    {
        if(Date==move->Date)
        {
            //��ӡ���Ѽ�¼
            printmsgs(move);
            temp++;
        }

        move=move->next;
    }
    if(temp==0)
    {
        //�������
        std::cout<<"δ�ҵ�������Ѽ�¼���������ز��ҵ����˵�"<<std::endl;
        system("pause");
        system("cls");
    }
}

//���
void find2(Homemember *head)
{
    auto *move=head->next;
    double amount;
    int temp=0;

    std::cout<<"���������ѽ�"<<std::endl;
    std::cin>>amount;

    while(move!=nullptr)
    {
        if(amount==move->amount)
        {
            //��ӡ
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //�������
        std::cout<<"δ�ҵ�������Ѽ�¼���������ز��ҵ����˵�"<<std::endl;
        system("pause");
        system("cls");
    }

}

//��+����
void find3(Homemember *head)
{
    auto *move=head->next;
    std::string ID;
    int temp=0;
    std::string Date;

    std::cout<<"�������������ڣ�����20240409����"<<std::endl;
    std::cin>>Date;
    std::cout<<"�������Ա��Ϣ��"<<std::endl;
    std::cin>>ID;

    while(move!=nullptr)
    {
        if(Date==move->Date)
        {
            //��ӡ���Ѽ�¼
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //�������
        std::cout<<"δ�ҵ�������Ѽ�¼���������ز��ҵ����˵�"<<std::endl;
        system("pause");
        system("cls");
    }
}

//��+����
void find4(Homemember *head)
{
    auto *move=head->next;
    std::string type;
    int temp=0;
    std::string Date;

    std::cout<<"�������������ڣ�����20240409����"<<std::endl;
    std::cin>>Date;
    std::cout<<"����������Ʒ�ࣺ"<<std::endl;
    std::cin>>type;

    while(move!=nullptr)
    {
        if(Date==move->Date)
        {
            //��ӡ���Ѽ�¼
            printmsgs(move);
            temp++;
        }
        move=move->next;
    }
    if(temp==0)
    {
        //�������
        std::cout<<"δ�ҵ�������Ѽ�¼���������ز��ҵ����˵�"<<std::endl;
        system("pause");
        system("cls");
    }

}

//ͳ�ƺ���Ⱥ(��ĳһ�����µ��ܽ��)
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
            std::cout<<"��������Чָ��"<<std::endl;
        }

        std::cout<<"ͳ����ϣ��������������ѽ������Ϊ��"<<sumamount<<"Ԫ"<<std::endl;
    }
}

//˭+ʱ���
double sum1(Homemember *head)
{
    auto *move=head->next;
    std::string begin,end;
    std::string ID;
    double sumamount=0.0;

    std::cout<<"�������ͥ��Ա��"<<std::endl;
    std::cin>>ID;
    std::cout<<"��������ʼʱ�䣺(���磺20240409)"<<std::endl;
    std::cin>>begin;
    std::cout<<"��������ֹʱ�䣺(���磺20240409)"<<std::endl;
    std::cin>>end;

    while(move!=nullptr)
    {
        if(move->ID==ID&&move->Date>=begin&&move->Date<=end)
            {
                printmsgs(move);
                sumamount+=move->amount;
            }
        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"δ�ҵ���Ӧ���Ѽ�¼"<<std::endl;
    
    return sumamount;
}

//Ʒ��+ʱ���
double sum2(Homemember *head)
{
    auto *move=head->next;
    std::string begin,end;
    std::string type;
    double sumamount=0.0;

    std::cout<<"����������Ʒ�ࣺ"<<std::endl;
    std::cin>>type;
    std::cout<<"��������ʼʱ�䣺"<<std::endl;
    std::cin>>begin;
    std::cout<<"��������ֹʱ�䣺"<<std::endl;
    std::cin>>end;

    while(move!=nullptr)
    {
        if(move->type==type&&move->Date>=begin&&move->Date<=end)
            {
                printmsgs(move);
                sumamount+=move->amount;
            }
        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"δ�ҵ���Ӧ���Ѽ�¼"<<std::endl;

    return sumamount;
}

//ʱ���
double sum3(Homemember *head)
{
    auto *move=head->next;
    std::string begin,end;
    double sumamount=0.0;

    std::cout<<"��������ʼʱ�䣺"<<std::endl;
    std::cin>>begin;
    std::cout<<"��������ֹʱ�䣺"<<std::endl;
    std::cin>>end;

    while(move!=nullptr)
    {
        if(move->Date>=begin&&move->Date<=end)
            {
                printmsgs(move);
                sumamount+=move->amount;
            } 
        move=move->next;
    }

    if(sumamount==0.0)
        std::cout<<"δ�ҵ���Ӧ���Ѽ�¼"<<std::endl;

    return sumamount;
}

//¼�뺯��Ⱥ(¼�벢���浽�ļ�)
void add(Homemember *head)
{
    //�ƶ�ָ�룬����β�巨��������ڵ�
    auto *temp=new Homemember;
    auto *move=head;

    while(move->next!=nullptr) 
    {
        move=move->next;
    }

    temp->entermsgs(temp);
    move->next=temp;
                
}

//������Ⱥ(��������������)
//���ù鲢����
Homemember* rank(Homemember *head) 
{
    if(head==nullptr||head->next==nullptr) return head;

    Homemember *head1=head;
    Homemember *head2=midsearch(head);

    head1=rank(head1);
    head2=rank(head2);

    return merge(head1,head2);

}
//���������е�
Homemember* midsearch(Homemember *head)
{
    Homemember *slow=head,*fast=head->next;

    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    Homemember *mid=slow->next;
    slow->next=nullptr;         //�ж��е�����һ�������

    return mid;
}
//�ϲ���˳���������
Homemember* merge(Homemember *head1,Homemember *head2)
{
    Homemember *temp=new Homemember(),*p=temp;

    while(head1!=nullptr&&head2!=nullptr)
    {
        if(head1->Date<=head2->Date)
        {
            p->next=head1;
            head1=head1->next;
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

//���º���Ⱥ(�޸Ĳ����浽�ļ�,����ɾ��ĳһ���)
void change(Homemember *head,int& judgement) 
{
    std::string ID,type;
    double amount;
    std::string Date;
    auto *target=head->next,*slow=head;
    char yesorno='n';

    //����ϸ������ģ�飬��ֹ�޸ĵ�һ�����ϵ���Ŀ

    std::cout<<"�����������Ϣ���Ա㶨λ��Ҫ�޸ĵ���Ŀ"<<std::endl;
    std::cout<<"�������������ڣ�����20240409����"<<std::endl;
    std::cin>>Date;    
    std::cout<<"��Ա��ݣ�"<<std::endl;
    std::cin>>ID;
    std::cout<<"���ѽ�"<<std::endl;
    std::cin>>amount;
    std::cout<<"����Ʒ�ࣺ"<<std::endl;
    std::cin>>type;

    while(target!=nullptr)
    {
        if(Date==target->Date&&ID==target->ID
        &&amount==target->amount&&type==target->type)
        {
            //��ӡ���Ѽ�¼
            printmsgs(target);
            break;
        }
        slow=target;
        target=target->next;
    }
    if(target==nullptr)
    {
        //�������
        std::cout<<"δ�ҵ�������Ѽ�¼����������"<<std::endl;
        system("pause");
        system("cls");
        return;
    }

    if(judgement==0)
    {
        std::cout<<"��������ĺ������"<<std::endl;
        target->entermsgs(target);
        std::cout<<"�޸ĳɹ�"<<std::endl;
    }
    else
    {
        std::cout<<"ȷ��ɾ����[y/n]"<<std::endl;
        std::cin>>yesorno;
        if(yesorno=='y')
        {
            slow->next=target->next;
            delete target;
            target=nullptr;
        }else
        {
            std::cout<<"ȡ��ɾ������������"<<std::endl;
            system("pause");
            system("cls");
            return;
        }
    }

}

//�ļ�IO
void ifile(Homemember *head)                //�ڴ浽�ļ�
{
    std::ofstream file("fee.dat",std::ios::out);
    auto *move=head->next;

    if(file.is_open())
    {
        while(move!=nullptr)
        {
            file<<move->Date<<" "<<move->ID<<" "<<move->amount<<" "<<move->type<<" "
            <<move->method<<" "<<move->site<<" "<<move->detail<<"\n"
            <<"###"<<std::endl;              //������Ϊ��ָ�������ģ�����ֿ�
            move=move->next;
        }
    }

    file.close();
}

void ofile(Homemember *head)                //�ļ����ڴ�
{
    auto *tail=head;
    std::ifstream file("fee.dat");
    std::string _check;
    
    if(file.is_open())
    {
        while(std::getline(file,_check))
        {
            
            if(_check=="###")
            {
                 while(tail->next!=nullptr)              //��ָ���Ƶ�����β
                {
                    tail=tail->next;
                }
                
            }
            else
            {
                Homemember *newnode=new Homemember;
                std::istringstream iss(_check);
                if(iss>>newnode->Date>>newnode->ID>>newnode->amount>>newnode->type>>newnode->method>>newnode->site>>newnode->detail)
                {
                    tail->next=newnode;
                    tail=newnode;
                }
            }
        }
    }

}

//�ڴ����
void Deletelist(Homemember *head)
{
    auto *move=head;
    while(move!=nullptr)
    {
        auto *temp=move;
        move=move->next;
        delete temp;
    }
}