#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

typedef char VerT;						//定义邻接矩阵图类中的VerT
typedef char DataType;					//定义顺序表类中的DataType
const int MaxVertices = 30;			   //定义最大顶点个数
const int MaxEdges=900;                 //定义最大边条数
const int MaxWeight = 10000;			//定义权值的无穷大
const int MaxQueueSize = 10000;        //定义队列的最大元素个数

#include "CreatGraph.h"

void Visit(VerT item) //访问顶点函数
{
   cout<<item<<" ";
}

int main()
{
   AdjMWGraph g;  //图的定义
   char a[MaxVertices];  //结点序列
   RowColWeight e[MaxEdges]; //图的边
   int n;  //图的顶点个数
   int m;  //图的边数
   cout<<"请输入结点个数";
   cin>>n;
   cout<<"请输入结点序列";
   for (int k=0;k<n;k++)
     cin>>a[k];
   cout<<"请输入边数";
   cin>>m;
   for (int k=0;k<m;k++)
   {
      cin>>e[k].row>>e[k].col>>e[k].weight;
   }
  /*在此处补充完整，找到顶点0到其它顶点的最短路径，
  需要完成以下内容：
  1.根据输入的数据创建图
  2.调用CreatGraph.h文件中的Dijkstra函数计算最短路径
  3.将到各顶点的路径输出
  */
   system("pause");
   return 0;
}