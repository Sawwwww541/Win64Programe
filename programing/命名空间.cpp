//命名空间不会重载，函数可以重载，但是当你的命名空间跟STL里的冲突时
//编译器会倾向于你的命名空间，而不是用STL；
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool Judge(std::string nums);

int main()
{
  int T=0;
  std::cin>>T;
  std::string nums[T];
  for(int i=0;i<T;i++)
  {
    std::cin>>nums[i];
    sort(nums[i].begin(),nums[i].end());
  }
  for(int i=0;i<T;i++)
  {
    if(Judge(nums[i])) std::cout<<"Yes";
    else std::cout<<"No";
  }

  return 0;
}

bool Judge(std::string nums)
{
  int jud1=0,jud2=0;
  for(int i=0;i<4;i++)
  {
    char temp=nums[0];
    if(temp==nums[i]) jud1++;
  }
  for(int i=3;i>=0;i--)
  {
    char temp=nums[3];
    if(temp==nums[i]) jud2++;
  }
  if(jud1==2||jud2==2) return true;
  else return false;
}