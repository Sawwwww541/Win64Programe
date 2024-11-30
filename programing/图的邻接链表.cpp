#include<iostream>
#include<vector>

/*由于图的多节点连接不唯一的特点，只封装一个函数不足以实现一个图
所以我们采用一个数组去存储节点，用链表来表示节点之间的联系*/

//我们可以将图抽象为一个图类



typedef struct node
{
    int val;
    struct node *next;

}node;

void edgelink2(int src,int val,std::vector<node*>& nodelist);

class Graph
{
    public:
        Graph():V(5),nodelist(V,nullptr){}
        //为数组进行节点初始化赋值
        void init()
        {
            for(int i=0;i<V;i++){
                nodelist[i]->val=i;
            }
            //这里创建一个简单的四节点的完全有向图;
            //0-1
            edgelink2(0,1,nodelist);
            //0-2
            edgelink2(0,2,nodelist);
            //0-3
            edgelink2(0,3,nodelist);
            //1-2
            edgelink2(1,2,nodelist);
            //1-3
            edgelink2(1,3,nodelist);
            //2-3
            edgelink2(2,3,nodelist);
            //3-4
            edgelink2(3,4,nodelist);
        }    

    private:
        int V;
        std::vector<node*> nodelist;
};
    //无向图的边连接
    void edgelink2(int src,int val,std::vector<node*>& nodelist)
    {
        node *newnode=new node;
        newnode->val=val;

        //头插法，建立新边
        newnode->next=nodelist[src];
        nodelist[src]=newnode;

        //建立双向连接
        node *newnode1=new node;
        newnode1->val=src;

        newnode1->next=nodelist[val];
        nodelist[val]=newnode1;
    }


int main()
{
    Graph G;
    G.init();
    



    return 0;
}