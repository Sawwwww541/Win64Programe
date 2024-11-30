#include<iostream>
#include<string>

class person    //封装
{
    public:
        std::string name;
        int age;

    private:
        std::string address;
        void changename()
        {
            std::string chname;
            std::cin>>chname;
            this->name=chname;

        }


};

class student:public person     //继承
{
    public:
        std::string id;
    private:
        void changeid()
        {
            std::string chid;
            std::cin>>chid;
            this->id=chid;

        }

};



int main()
{
    person Alan;
    Alan.name="Alan";
    Alan.age=18;
    student Amy;
    Amy.name="Amy";
    Amy.age=18;
    Amy.id="12345";

    std::cout<<Alan.name;


    return 0;
}