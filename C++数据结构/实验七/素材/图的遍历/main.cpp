#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char VerT;						//定义邻接矩阵图类中的VerT
typedef char DataType;					//定义顺序表类中的DataType
const int MaxVertices = 30;			   //定义最大顶点个数
const int MaxEdges=900;                 //定义最大边条数
const int MaxWeight = 10000;			//定义权值的无穷大
const int MaxQueueSize = 10000;

#include "AdjMWGraph.h"					//包含邻接矩阵的图类

struct RowColWeight
{
	int row;							//行下标
	int col;							//列下标
	int weight;							//权值
};

void CreatGraph(AdjMWGraph &G, DataType V[], int n, RowColWeight E[],int e)
//在图G中插入n个顶点V和e条边E
{
	//在图G中插入n个顶点
	for(int i = 0; i < n; i++) 
		G.InsertVertex(V[i]);

	//在图G中插入e条边
	for(int k = 0; k < e; k++) 
		G.InsertEdge(E[k].row, E[k].col, E[k].weight);
}

void Visit(VerT item)  //访问顶点函数
{
	cout<<item<<"  ";
}

void main(void)
{   int i;
	AdjMWGraph g;
	char a[MaxVertices] ;//顶点序列集合	
	RowColWeight rcw[MaxEdges] ;//边三元组序列集合
	
	///补充程序创建如实验给出的图，并将其遍历序列输出///
	do
	{
		system("cls");
		cout<<"##################\n1.图的建立 \n2.深度优先遍历图 \n3.广度优先遍历图 \n0.结束 \n##################\n";
	    cout<<"请选择你要操作的：";
		cin>>i;
		if(i==1)
		{
			int n,e;
			cout<<"请输入顶点数：";
			cin>>n;
			cout<<"请输入顶点数据序列：";
			/*DataType *V = new DataType[n];*/
			for(int j=0;j<n;j++)
			{
				cin>>a[j];
			}
			cout<<"请输入边数：";
			cin>>e;
			cout<<"请输入边：";
			/*RowColWeight *E=new RowColWeight[e];*/
			for(int j=0;j<e;j++)
			{
				cin>>rcw[j].col;
				cin>>rcw[j].row;
				cin>>rcw[j].weight;
			}
			CreatGraph(g,  a,  n, rcw, e);
		}
		else if(i==2)
		{
			cout<<"深度优先遍历数据顺序为：";
			g.DepthFirstSearch(Visit);
			system("pause");
		}
		else if(i==3)
		{
			cout<<"广度优先遍历数据顺序为：";
			g.BroadFirstSearch(Visit);
			system("pause");
		}
	}while(i!=0);
	

}     


