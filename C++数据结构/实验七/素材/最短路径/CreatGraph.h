#include "AdjMWGraph.h"
struct RowColWeight
{
   int row;     //行数
   int col;     //列数
   int weight;   //权值
};
struct MinSpanTree //生成树的顶点数据和相应顶点的边的权值数据CloseVertex的数据类型
{
   VerT vertex;   //最小生成树每条边的弧头顶点数据
   int weight;    //保存生成树的相应边的权值
};
void CreatGraph(AdjMWGraph &G,DataType V[],int n,RowColWeight E[],int e) //创建图
{
   for (int i=0;i<n;i++)
   {
      G.InsertVertex(V[i]);   //插入图的顶点
   }
   for (int i=0;i<e;i++)
   {
      G.InsertEdge(E[i].row,E[i].col,E[i].weight);  //插入图的边
   }
 }
 
 void Dijkstra(AdjMWGraph &G,int v0,int distance[],int path[])
 { //distance数组用来存放从v0顶点到其余各顶点的最短距离
   //path用来存放从v0到其它各顶点的最短路径上到达目标顶点的前驱下标
   
   /*基本思想：设置一个集合S（也可以看作红点集）存放已经找到最短路径的顶点 
    S的初始状态只包含源点v，对vi∈V-S,假设从源点v到vi的有向边为最短路径。 
    以后每求得一条最短路径v, …, vk，就将vk加入集合S中，                  
    并将路径v, …, vk , vi与原来的假设相比较，取路径长度较小者为最短路径。 
    重复上述过程，直到集合V中全部顶点加入到集合S中。                     
    请在此处补充完整代码                                                
    */
    

 }
  