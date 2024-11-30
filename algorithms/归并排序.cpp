#include<iostream>

void Merge(int nums[],int temp[],int left,int right);
void msort(int nums[],int temp[],int left,int right);
void Merge_sort(int nums[],int len);

int main() {
    int nums[10]{3,2,4,6,9,10,11,43,21,66};
    int len=sizeof(nums)/sizeof(int);
    Merge_sort(nums,len);
    for(int i=0;i<len;i++)
        std::cout<<nums[i]<<" ";
}
void Merge_sort(int nums[],int len) {
    auto *temp=new int[len];
    if(temp) {
        msort(nums,temp,0,len-1);
        delete(temp);
    }
    else {
        std::cout<<"Error!"<<std::endl;
    }
}
void msort(int nums[],int temp[],int left,int right) {
    if(left<right) {
        int mid=(left+right)/2;
        msort(nums,temp,left,mid);//左半
        msort(nums,temp,mid+1,right);//右半
        Merge(nums,temp,left,right);
    }
}
void Merge(int nums[],int temp[],int left,int right) {
    int l_pos=left,r_pos=(left+right)/2+1,pos=left;
    while(l_pos <= (right+left)/2 && r_pos <= right) {
        if(nums[l_pos] <= nums[r_pos]) {
            temp[pos++] = nums[l_pos++];
        } else {
            temp[pos++] = nums[r_pos++];
        }
    }
    while(l_pos <= (left+right)/2) {
        temp[pos++] = nums[l_pos++];
    }
    while(r_pos <= right) {
        temp[pos++] = nums[r_pos++];
    }
    for(int i=left;i<=right;i++) {
        nums[i]=temp[i];
    }
    }
