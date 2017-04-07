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
 
 void Prim(AdjMWGraph &G,MinSpanTree CloseVertex[])
 {
    /*假设最小生成树从序号为0的顶点开始，其中CloseVertex数组保存最小生成树的顶点和边的信息
    算法思想：设G=(V, E)是具有n个顶点的连通网，T=(U, TE)是G的最小生成树                
    T的初始状态为U={u0}（u0∈V），TE={ }，重复执行下述操作：                            
    在所有u∈U，v∈V-U的边中找一条代价最小的边(u, v)并入集合TE，同时v并入U，直至U=V。   
    请在此处完成相应的代码编写        
    */                                                    
 }
  