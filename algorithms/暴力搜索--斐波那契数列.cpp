#include<iostream>
#include<vector>
//递归计算斐波那契数列
int fib(int x)
{
    std::vector<int> ans(46,-1);
    if(x==1||x==2){
        ans[x]=x;
        return x;
    }
    else{
        ans[x]=fib(x-1)+fib(x-2);
        return fib(x-1)+fib(x-2); //深度优先搜索
    }
    
}

int main()
{
    int n=0;
    long long ans=0;
    scanf("%d",&n);
    ans=fib(n);
    printf("%lld",ans);
    return 0;
}