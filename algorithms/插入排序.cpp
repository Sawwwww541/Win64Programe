#include<iostream>

void printarr(int a[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        std::cout<<a[i]<<" ";

    }

}

void arr_sort(int a[],int n)
{
    int i=0,j=0;

    for(i=1;i<n;i++)
    {
        int temp=a[i];
        j=i-1;
        while(a[j]>temp&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printarr(a,n);
}

int main()
{
    int n=0;
    int a[]={18,20,12,1,4,5,7,3};
    n=sizeof(a)/sizeof(a[0]);
    printarr(a,n);
    std::cout<<"\n";
    arr_sort(a,n);

    return 0;
}