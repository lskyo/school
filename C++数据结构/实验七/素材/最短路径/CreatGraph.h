#include "AdjMWGraph.h"
struct RowColWeight
{
   int row;     //����
   int col;     //����
   int weight;   //Ȩֵ
};
struct MinSpanTree //�������Ķ������ݺ���Ӧ����ıߵ�Ȩֵ����CloseVertex����������
{
   VerT vertex;   //��С������ÿ���ߵĻ�ͷ��������
   int weight;    //��������������Ӧ�ߵ�Ȩֵ
};
void CreatGraph(AdjMWGraph &G,DataType V[],int n,RowColWeight E[],int e) //����ͼ
{
   for (int i=0;i<n;i++)
   {
      G.InsertVertex(V[i]);   //����ͼ�Ķ���
   }
   for (int i=0;i<e;i++)
   {
      G.InsertEdge(E[i].row,E[i].col,E[i].weight);  //����ͼ�ı�
   }
 }
 
 void Dijkstra(AdjMWGraph &G,int v0,int distance[],int path[])
 { //distance����������Ŵ�v0���㵽������������̾���
   //path������Ŵ�v0����������������·���ϵ���Ŀ�궥���ǰ���±�
   
   /*����˼�룺����һ������S��Ҳ���Կ�����㼯������Ѿ��ҵ����·���Ķ��� 
    S�ĳ�ʼ״ֻ̬����Դ��v����vi��V-S,�����Դ��v��vi�������Ϊ���·���� 
    �Ժ�ÿ���һ�����·��v, ��, vk���ͽ�vk���뼯��S�У�                  
    ����·��v, ��, vk , vi��ԭ���ļ�����Ƚϣ�ȡ·�����Ƚ�С��Ϊ���·���� 
    �ظ��������̣�ֱ������V��ȫ��������뵽����S�С�                     
    ���ڴ˴�������������                                                
    */
    

 }
  