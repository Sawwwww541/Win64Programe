#include <iostream>
#include <vector>
#include <algorithm>

void QSort(std::vector<int>& nums,int left,int right);

int main()
{
  int lenth=0;
  std::cin>>lenth;
  std::vector<int> nums(lenth);
  for(int i=0;i<lenth;i++)
    std::cin>>nums[i];
  QSort(nums,0,nums.size());
  return 0;
}

void QSort(std::vector<int>& nums,int left,int right)
{   
    int i=left;
    int j=right;
    int pivot=nums[left];
    if(i>=j) return;

  while(left!=right)
  {
    while(nums[j]>=pivot&&i<j) j--;

    while(nums[i]<=pivot&&i<j) i++;

    if(i<j) std::swap(nums[i],nums[j]);
  }
    std::swap(nums[left],nums[i]);
    QSort(nums,left,i-1);
    QSort(nums,i,right);
}