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
 
 void Prim(AdjMWGraph &G,MinSpanTree CloseVertex[])
 {
    /*������С�����������Ϊ0�Ķ��㿪ʼ������CloseVertex���鱣����С�������Ķ���ͱߵ���Ϣ
    �㷨˼�룺��G=(V, E)�Ǿ���n���������ͨ����T=(U, TE)��G����С������                
    T�ĳ�ʼ״̬ΪU={u0}��u0��V����TE={ }���ظ�ִ������������                            
    ������u��U��v��V-U�ı�����һ��������С�ı�(u, v)���뼯��TE��ͬʱv����U��ֱ��U=V��   
    ���ڴ˴������Ӧ�Ĵ����д        
    */                                                    
 }
  