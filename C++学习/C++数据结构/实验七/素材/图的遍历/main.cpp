#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char VerT;						//�����ڽӾ���ͼ���е�VerT
typedef char DataType;					//����˳������е�DataType
const int MaxVertices = 30;			   //������󶥵����
const int MaxEdges=900;                 //������������
const int MaxWeight = 10000;			//����Ȩֵ�������
const int MaxQueueSize = 10000;

#include "AdjMWGraph.h"					//�����ڽӾ����ͼ��

struct RowColWeight
{
	int row;							//���±�
	int col;							//���±�
	int weight;							//Ȩֵ
};

void CreatGraph(AdjMWGraph &G, DataType V[], int n, RowColWeight E[],int e)
//��ͼG�в���n������V��e����E
{
	//��ͼG�в���n������
	for(int i = 0; i < n; i++) 
		G.InsertVertex(V[i]);

	//��ͼG�в���e����
	for(int k = 0; k < e; k++) 
		G.InsertEdge(E[k].row, E[k].col, E[k].weight);
}

void Visit(VerT item)  //���ʶ��㺯��
{
	cout<<item<<"  ";
}

void main(void)
{   int i;
	AdjMWGraph g;
	char a[MaxVertices] ;//�������м���	
	RowColWeight rcw[MaxEdges] ;//����Ԫ�����м���
	
	///������򴴽���ʵ�������ͼ������������������///
	do
	{
		system("cls");
		cout<<"##################\n1.ͼ�Ľ��� \n2.������ȱ���ͼ \n3.������ȱ���ͼ \n0.���� \n##################\n";
	    cout<<"��ѡ����Ҫ�����ģ�";
		cin>>i;
		if(i==1)
		{
			int n,e;
			cout<<"�����붥������";
			cin>>n;
			cout<<"�����붥���������У�";
			/*DataType *V = new DataType[n];*/
			for(int j=0;j<n;j++)
			{
				cin>>a[j];
			}
			cout<<"�����������";
			cin>>e;
			cout<<"������ߣ�";
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
			cout<<"������ȱ�������˳��Ϊ��";
			g.DepthFirstSearch(Visit);
			system("pause");
		}
		else if(i==3)
		{
			cout<<"������ȱ�������˳��Ϊ��";
			g.BroadFirstSearch(Visit);
			system("pause");
		}
	}while(i!=0);
	

}     


