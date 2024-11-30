#include<iostream>
#include<string>
#include<vector>
#include<graphics.h>
#include<conio.h>

class Date
{
public:
	int year;
	int mounth;
	int day;
};

class Member
{
public:
	Date paydate;
	std::string ID;
    double amount;
    std::string type;
    std::string method;
    std::string site;
    std::string detail;
    Member *next;
};


//	setbkcolor(RGB(159,252,253)); 天蓝色
//  195，195，195 浅灰色
//  112,146,190 灰蓝色
//初始用户界面--一级菜单
void usrmenu()
{


}


//查询菜单--二级菜单



//统计菜单--二级菜单



//查询函数群(1.起止日期2.金额3.某人+起止日期4.某物+起止日期)




//排序函数群(按金额降序)






//统计函数群(求某一条件下的总金额)





//录入函数群(录入并保存到文件)
void addmsg()
{
    Date paydate;
	std::string ID;
    double amount;
    std::string type;
    std::string method;
    std::string site;
    std::string detail;


}



//更新函数群(修改并保存到文件)




//文件IO
