#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char VerT;						//�����ڽӾ���ͼ���е�VerT
typedef char DataType;					//����˳������е�DataType
const int MaxVertices = 30;			   //������󶥵����
const int MaxEdges=900;                 //������������
const int MaxWeight = 10000;			//����Ȩֵ�������
const int MaxQueueSize = 10000;        //������е����Ԫ�ظ���

#include "CreatGraph.h"

void Visit(VerT item) //���ʶ��㺯��
{
   cout<<item<<" ";
}

int main()
{
   AdjMWGraph g;  //ͼ�Ķ���
   char a[MaxVertices];  //�������
   RowColWeight e[MaxEdges]; //ͼ�ı�
   int n;  //ͼ�Ķ������
   int m;  //ͼ�ı���
   cout<<"�����������";
   cin>>n;
   cout<<"������������";
   for (int k=0;k<n;k++)
     cin>>a[k];
   cout<<"���������";
   cin>>m;
   for (int k=0;k<m;k++)
   {
      cin>>e[k].row>>e[k].col>>e[k].weight;
   }
   //���ڴ˴������벹����������Ҫ�����������//
   //1.�������������ݹ��ɵ�ͼ                //
   //2.����CreatGraph.h�ļ��е�Prim��������ͼ����С������//
   //3.����ʵ��Ҫ��������������ܴ���//
  
   system("pause");
   return 0;
}