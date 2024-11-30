#include<iostream>
#include<vector>
#include<string>

int main()
{
    int l=0,r=0;
    std::string test1;
    std::cin>>test1;
    r=test1.size()-1;
    for(l=0;l<r;l++)
    {
        char temp=test1[l];
        test1[l]=test1[r];
        test1[r]=temp;
        r--;
        
    }
    std::cout<<test1;

    return 0;
}