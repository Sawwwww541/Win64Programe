#include<iostream>//冒泡排序

void frank(int arr[]);
int main(void){
    int arr[10];
    int i=0;
    for(i=0;i<10;i++){
        std::cin>>arr[i];
    }
    frank(arr);
    for(i=0;i<10;i++){
        std::cout<<arr[i];
    }
}
void frank(int arr[]){
    int a=0,b=0,t=0;
    for(a=0;a<9;a++){
        for(b=0;b<9;b++){
            if(arr[b]>arr[b+1]){
                t=arr[b];
                arr[b]=arr[b+1];
                arr[b+1]=t;
            }
        }
    }
}