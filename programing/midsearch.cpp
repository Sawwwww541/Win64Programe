#include <iostream>
#include <vector>

int main() {
        std::vector<int> nums{1,3,5,6};
        int target=5;
        int left=0,right=nums.size()-1,count=0;
        int mid=left+(right-left)/2;
        while(left<=right){
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        if(left<=right) return (left+1);
        else if(target>nums[nums.size()-1]) return nums.size();
        else{
            while(nums[count]<target){
                count++;
            }
            return count;
        }
    }
