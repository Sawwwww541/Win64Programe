#include<iostream>
#include<memory>

class test
{
    public:
        test():setting(0),value(0)
        {
            std::cout<<"created test"<<std::endl;
        }

        ~test()
        {
            std::cout<<"destoried test"<<std::endl;
        }
    private:
        int value;
        int setting;
};

int main(int argc,char** argv)
{
    {
    std::unique_ptr<test> realtest=std::make_unique<test>();
    }
    return 0;
}
