
//文件采用UTF-8格式编码，输出乱码请更改系统设置启用Beta-UTF-8格式
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PW_size 11
#define AC_size 9
#define PN_size 12

typedef struct Birthday{
//生日结构体
    int year;
    int month;
    int day;
}Birthday;

typedef struct Merchant{
//商家结构体
    char name[30];//名字
    char idcard[19];//身份证
    Birthday M_birthday;//生日
    char account[AC_size];//账号
    char password[PW_size];//密码
    char phone[PN_size];//手机号
    struct Merchant *next;//指向下一账户
}Merchant;

typedef struct Commodity{
//商品结构体
    char Com_name[30];//商品名
    int Com_price;//价格
    long long Cinventory;//库存
    struct Commodity *next;//指向下一商品
}Commodity;

Merchant* Guide1(Merchant *head,int *pkey);//登录面板
void Guide0(); //起始面板
void Register(Merchant *head);//注册面板
void Retrieve(Merchant *head);//找回密码面板
void Account_interact(Merchant *head,Merchant *move);//用户交互面板
void ChangeAccount(Merchant *head);//更换账户面板
void Changepassword(Merchant *move);//修改密码面板
void Password_Circle(Merchant *head,Merchant *move,int *pjudge);//错误密码循环

void Commodity_guide();//商品导航面板
void Commodity_print(Commodity *Com_head);//商品列表打印面板
void Commodity_add(Commodity *Com_head);//上架商品
void Commodity_delet(Commodity *Com_head);//下架商品
void Commodity_select(Commodity *Com_head);//查找商品

//main函数主体-------------------------------------------

int main()
{
    //变量声明
    int key=0;
    int *pkey=&key;
    char n='0',i='0',m='0';
    Merchant *move=NULL;
    //用户链表头
    Merchant *head=(Merchant*)malloc(sizeof(Merchant));
    head->next=NULL;
    //商品链表头
    Commodity *Com_head=(Commodity*)malloc(sizeof(Commodity));
    Com_head->next=NULL;
    
    
    //初始引导
    Guide0();
    //通过用户输入，执行下一步
    scanf("%c",&n);
    getchar();
    switch(n){
        case '0':
            move=Guide1(head,pkey);
            if(key==1){
                system("cls");
                Account_interact(head,move);
            }else {
                system("pause");
                system("cls");
                Register(head);
                move=Guide1(head,pkey);
                if(key==1){
                    Account_interact(head,move);
                    }
                }
        break;
        case '1':
            Register(head);
            while(1){
                move=Guide1(head,pkey);
                if(key==1){
                system("cls");
                Account_interact(head,move);
                break;
            }  
                printf("输入1终止登录并结束程序,输入其他重新进入登录界面\n");
                getchar();
                scanf("%c",&i);
                if(i=='1') break;
            }
                          

        break;
        case '2':
            return 0;
        break;
        default: printf("请输入有效指令\n");
    }

    //商品管理交互
    
    while(1){
        getchar();
        scanf("%c",&m);
    switch (m){
        case '1':
        Commodity_print(Com_head);
        break;
        case '2':
        Commodity_add(Com_head);
        break;
        case '3':
        Commodity_delet(Com_head);
        break;
        case '4':
        Commodity_select(Com_head);
        break;
        default:
        printf("请输入有效指令\n");
        break;
    }

}



}

//必要函数定义-------------------------------------------

void Register(Merchant *head){

    Merchant *move=head;
    Merchant *fresh=(Merchant*)malloc(sizeof(Merchant));
    fresh->next=NULL;


    //信息录入
    printf("您正在注册账户，请根据指引输入您的信息\n");
    printf("-----------------------------------------------\n");
    printf("您的名字：\n");
    scanf("%s",fresh->name);

        printf("-----------------------------------------------\n");
    printf("您的身份证号：\n");
    scanf("%s",fresh->idcard);

        printf("-----------------------------------------------\n");
    printf("您的生日（示例：2006 4 9）：\n");
    scanf("%d %d %d",&fresh->M_birthday.year,&fresh->M_birthday.month,&fresh->M_birthday.day);

        printf("-----------------------------------------------\n");
    printf("账号（由1~8位字符组成）：\n");
    scanf("%s",fresh->account);

        printf("-----------------------------------------------\n");
    printf("密码（由1~10位字符组成）：\n");
    scanf("%s",fresh->password);

        printf("-----------------------------------------------\n");
    printf("您的电话号码：\n");
    scanf("%s",fresh->phone);

    printf("-----------------------------------------------\n");
    printf("信息录入完毕\n");
    printf("-----------------------------------------------\n");

    while(move->next!=NULL){
        move=move->next;
    }
    move->next=fresh;

    system("pause");
    system("cls");
}

void Guide0(){
    //初始引导界面
    printf("-----------------------------------------------\n");
    printf("欢迎使用电商管理系统，请根据指引选择服务：\n");
    printf("若您第一次使用，请先注册\n");
    printf("请输入“0”登录账户\n");
    printf("请输入“1”注册账户\n");
    printf("请输入“2”结束程序\n");
    printf("-----------------------------------------------\n");
}

Merchant* Guide1(Merchant *head,int *pkey){
    //登录界面
    char account[AC_size];//账号
    char password[PW_size];//密码
    int judge=0;
    int *pjudge=&judge;
    Merchant *move=head->next;

    printf("-----------------------------------------------\n");
    printf("您正在登录，请输入账户信息\n");
    printf("-----------------------------------------------\n");
    printf("请输入账号：\n");
    printf("-----------------------------------------------\n");
    scanf("%s",account);
    getchar();
    //查找对应账户
    while(move!=NULL){
        if(strcmp(move->account,account)==0){
            printf("已为您找到账户%s\n",move->account);
            printf("-----------------------------------------------\n");
            break;
        }
        move=move->next;
    }
    if(move==NULL){
        printf("-----------------------------------------------\n");
        printf("无账户信息，为您跳转到注册页面\n");
    }else{
        printf("请输入密码：\n");
        printf("-----------------------------------------------\n");
        while(1){
            scanf("%s",password);
                if(strcmp(move->password,password)==0){
                    *pkey=1;
                    return move;
                }else{
                    while(1){
                        Password_Circle(head,move,pjudge);
                        if(judge==1){
                            *pkey=1;
                            return move;
                        }
                    }
                    
                }
        }
    }
    return move;
}

void Password_Circle(Merchant *head,Merchant *move,int *pjudge){
//错误密码的循环

    char password[PW_size];

    printf("您输入的密码错误，请再次输入\n");
    printf("-----------------------------------------------\n");
    printf("请输入密码：\n");
    printf("-----------------------------------------------\n");
    printf("(如果您忘记密码，输入“zhaohui”以找回密码)\n");
    printf("-----------------------------------------------\n");

    scanf("%s",password);

    if(strcmp(password,"zhaohui")==0){
            Retrieve(head);
            return;
        }
    if(strcmp(move->password,password)==0){
        *pjudge=1;
        return;
    }
}


void Retrieve(Merchant *head){
    //move自己找
    //找回密码
    char Re_idcard[19];//身份证
    char Re_phone[PN_size];//手机号
    char account[AC_size];
    char Re_n='0';
    Merchant *move=head->next;
    
    system("cls");
    printf("-----------------------------------------------\n");
    printf("您正在找回密码\n");
    printf("输入“0”返回，输入“1”继续\n");
    printf("-----------------------------------------------\n");
    getchar();
    scanf("%c",&Re_n);

    if(Re_n=='1'){
        printf("-----------------------------------------------\n");
        printf("请输入要找回密码的账号：\n");
        scanf("%s",account);
        getchar();
        //查找对应账户
        while(move!=NULL){
            if(strcmp(move->account,account)==0){
                printf("-----------------------------------------------\n");
                printf("已为您找到账户%s\n",move->account);
                printf("-----------------------------------------------\n");
                break;
            }
            move=move->next;
        }
        if(move==NULL){
            printf("未找到账户，请检查是否输入正确\n");
        }else{
            printf("-----------------------------------------------\n");
            printf("请输入您的身份证：\n");
            scanf("%s",Re_idcard);
            getchar();
            printf("-----------------------------------------------\n");
            printf("请输入您的电话号码：\n");
            scanf("%s",Re_phone);
            getchar();

            if(strcmp(Re_idcard,move->idcard)==0&&strcmp(Re_phone,move->phone)==0){
                system("cls");
                printf("-----------------------------------------------\n");
                printf("找回成功\n");
                printf("您的密码是：%s\n",move->password);
                printf("-----------------------------------------------\n");
                return;
            }else {
                printf("-----------------------------------------------\n");
                printf("信息核验错误，请您检查是否输入正确的信息\n");
                printf("输入“1”重新找回，输入“2”返回\n");
                printf("-----------------------------------------------\n");
                scanf("%c",&Re_n);
                if(Re_n=='1') Retrieve(head);
                if(Re_n=='2') return;
            }
        }
    }
    if(Re_n=='0') return;
    
}

//账户交互页面
void Account_interact(Merchant *head,Merchant *move){
    //move传递

    char x='1',num='2';
    system("cls");
    printf("-----------------------------------------------\n");
    printf("欢迎您，%s\n",move->account);
    printf("输入“0”更改密码\n");
    printf("输入“1”进入商品管理界面\n");
    printf("输入“2”更换账户\n");
    printf("-----------------------------------------------\n");
    getchar();
    scanf("%c",&x);

    switch(x){
        case '0':
        while(1){
            Changepassword(move);
            printf("-----------------------------------------------\n");
            printf("输入“1”重新输入密码\n");
            printf("输入“2”进入商品管理界面\n");
            printf("-----------------------------------------------\n");
            getchar();
            scanf("%c",&num);
            if(num=='1') continue;
            else if(num=='2'){
                Commodity_guide();
                break;
            }else printf("请输入有效指令\n");
        }
        break;
        case '1':
        Commodity_guide();
        break;
        case '2':
        ChangeAccount(head);
        Commodity_guide();
        break;
        default: 
        printf("请输入有效指令\n");
        break;
    }

}

void ChangeAccount(Merchant *head){
    //move自己找

    char account[AC_size];
    char password[PW_size];
    Merchant *move=head->next;

    printf("-----------------------------------------------\n");
    printf("您正在更换账户\n");
    printf("-----------------------------------------------\n");
    printf("请输入账号：\n");

    scanf("%s",account);
    getchar();
    //查找对应账户
    while(move!=NULL){
        if(strcmp(move->account,account)==0){
            printf("-----------------------------------------------\n");
            printf("已为您找到账户%s\n",move->account);
            printf("-----------------------------------------------\n");
            break;
        }
        move=move->next;
        
    }
    if(move==NULL){
        printf("-----------------------------------------------\n");
        printf("无账户信息，将自动为您跳转到注册界面\n");
        system("pause");
        system("cls");
        Register(head);
    }else{
        printf("请输入密码：\n");
        printf("-----------------------------------------------\n");
        while(1){
            scanf("%s",password);
            getchar();
                if(strcmp(move->password,password)==0){
                    Account_interact(head,move);
                    break;
                }else{
                    printf("您输入的密码错误，请再次输入\n");
                    printf("-----------------------------------------------\n");
                    printf("如果您忘记密码，输入“zhaohui”以找回密码\n");
                    printf("-----------------------------------------------\n");
                }
                if(strcmp(password,"zhaohui")==0){
                    Retrieve(head);
                }
            }
        }
    
}

//改密码
void Changepassword(Merchant *move){
    //move传递

    char oldpassword[PW_size];

    printf("-----------------------------------------------\n");
    printf("请输入您的旧密码\n");
    scanf("%s",oldpassword);
    if(strcmp(oldpassword,move->password)==0){
        printf("-----------------------------------------------\n");
        printf("请输入您的新密码\n");
        printf("-----------------------------------------------\n");
        scanf("%s",move->password);
        printf("修改成功，您的新密码是：%s\n",move->password);
    }else{
        printf("-----------------------------------------------\n");
        printf("您输入的密码错误，请您再次输入\n");
    }

}

//商品管理
void Commodity_guide(){

    system("cls");
    printf("-----------------------------------------------\n");
    printf("欢迎来到商品管理界面，请根据指引选择服务：\n");
    printf("输入“1”显示所有商品信息\n");
    printf("输入“2”添加商品\n");
    printf("输入“3”删除商品\n");
    printf("输入“4”查询商品信息\n");
    printf("-----------------------------------------------\n");

}

//录入商品信息
void Commodity_add(Commodity *Com_head){

    Commodity *move=Com_head;
    Commodity *Fresh=(Commodity*)malloc(sizeof(Commodity));
    Fresh->next=NULL;

    printf("-----------------------------------------------\n");
    printf("您正在添加商品\n");
    printf("-----------------------------------------------\n");
    printf("请输入商品名称\n");
        getchar();
    scanf("%s",Fresh->Com_name);
        getchar();
    printf("-----------------------------------------------\n");
    printf("请输入商品价格（元）\n");
    scanf("%d",&Fresh->Com_price);
        getchar();
    printf("-----------------------------------------------\n");
    printf("请输入商品库存量（件）\n");
    scanf("%lld",&Fresh->Cinventory);
    printf("-----------------------------------------------\n");

    while(move->next!=NULL){
        move=move->next;
    }
    move->next=Fresh;
    printf("添加成功，即将返回导航页面\n");
    system("pause");
    Commodity_guide();

}

void Commodity_print(Commodity *Com_head){

    Commodity *move=Com_head->next;

    printf("-----------------------------------------------\n");
    printf("已为您打印您的商品列表\n");
    printf("-----------------------------------------------\n");

    while(move!=NULL){
        printf("商品名：%s\n",move->Com_name);
        printf("商品价格（元）：%d\n",move->Com_price);
        printf("商品库存（件）：%lld\n",move->Cinventory);
        printf("-----------------------------------------------\n");
        move=move->next;
    }

    printf("打印结束\n");
    printf("-----------------------------------------------\n");
    printf("即将返回导航页面\n");
    system("pause");
    Commodity_guide();

}

void Commodity_delet(Commodity *Com_head){

    char name[30];
    char n='0';
    Commodity *Front=NULL;
    Commodity *move=Com_head->next;
    printf("-----------------------------------------------\n");
    printf("请输入您要下架的商品名称\n");
    getchar();
    scanf("%s",name);
    while(move!=NULL){
            
            if(strcmp(name,move->Com_name)==0){
                printf("-----------------------------------------------\n");
                printf("商品名：%s\n",move->Com_name);
                printf("商品价格（元）：%d\n",move->Com_price);
                printf("商品库存（件）：%lld\n",move->Cinventory);
                printf("-----------------------------------------------\n");
                break;
            }
            Front=move;
            move=move->next;
        }

    //若出循环后Front仍是空指针，说明链表中只有一个结点，会产生指针赋值失败的bug，导致程序挂起

    if(Front==NULL){

            printf("-----------------------------------------------\n");
            printf("是否删除以上商品？\n");
            printf("是请输入“1”\n");
            printf("否请输入“0”\n");
            printf("-----------------------------------------------\n");
            getchar();
            scanf("%c",&n);

            if(n=='1'){

                Com_head->next=move->next;
                free(move);
                move=NULL;
                
                printf("删除成功\n");
            }else if(n=='0'){
                return;
            }else printf("请输入有效指令\n");

    }else if(move!=NULL&&Front!=NULL){

            printf("-----------------------------------------------\n");
            printf("是否删除以上商品？\n");
            printf("是请输入“1”\n");
            printf("否请输入“0”\n");
            printf("-----------------------------------------------\n");
            getchar();
            scanf("%c",&n);
            if(n=='1'){
                Front->next=move->next;//只要一方为空指针都会导致程序挂起
                free(move);
                move=NULL;
                printf("删除成功\n");
            }else if(n=='0'){
                return;
            }else printf("请输入有效指令\n");
        }else printf("无商品信息\n");

    printf("-----------------------------------------------\n");
    printf("即将返回导航页面\n");
    printf("-----------------------------------------------\n");
    system("pause");
    Commodity_guide();

}


void Commodity_select(Commodity *Com_head){

    char name[30];
    Commodity *move=Com_head->next;
    printf("-----------------------------------------------\n");
    printf("请输入您要查找的商品名称\n");
    printf("-----------------------------------------------\n");
    getchar();
    scanf("%s",name);
        while(move!=NULL){
            if(strcmp(name,move->Com_name)==0){
                printf("-----------------------------------------------\n");
                printf("为您找到以下商品\n");
                printf("-----------------------------------------------\n");
                printf("商品名：%s\n",move->Com_name);
                printf("商品价格（元）：%d\n",move->Com_price);
                printf("商品库存（件）：%lld\n",move->Cinventory);
                printf("-----------------------------------------------\n");
                break;
            }
            move=move->next;
        }
        if(move==NULL){
            printf("-----------------------------------------------\n");
            printf("无商品信息\n");
            printf("-----------------------------------------------\n");
        }
    printf("即将返回导航页面\n");    
    system("pause");
    Commodity_guide();

    }
