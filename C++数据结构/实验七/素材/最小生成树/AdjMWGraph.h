#include "SeqList.h"					//������̬����ṹ��˳�����

class AdjMWGraph
{
private:
	SeqList Vertices;								//����˳���
	int Edge[MaxVertices][MaxVertices];				//��Ȩֵ����
	int numOfEdges;									//�ߵĸ���
    
	//��V��ͨ����ͨ������������ȱ���
	void DepthFirstSearch(const int v, int visited[],void Visit(VerT item));
    //��V��ͨ����ͨ�����Ĺ�����ȱ���
	void BroadFirstSearch(const int v, int visited[], void Visit(VerT item));
public:
	AdjMWGraph(const int sz = MaxVertices);			//���캯��
	~AdjMWGraph(void){};							//��������

	int NumOfVertices(void)							//ȡ�������
		{return Vertices.Size();}
	int NumOfEdges(void)							//ȡ�ߵĸ���
		{return numOfEdges;}
	VerT GetValue(const int v);						//ȡ������ֵ
	int GetWeight(const int v1, const int v2);		//ȡ�ߵ�Ȩֵ

	void InsertVertex(const VerT &vertex);			//���붥��
	void InsertEdge(const int v1, const int v2, int weight);//�����
	void DeleteVertex(const int v);					//ɾ������
	void DeleteEdge(const int v1, const int v2);	//ɾ����
	int GetFirstNeighbor(const int v);				//ȡ��һ���ڽӶ���
	int GetNextNeighbor(const int v1, const int v2);//ȡ��һ���ڽӶ���
     
	void DepthFirstSearch(void Visit(VerT item));	//������ȱ���
	void BroadFirstSearch(void Visit(VerT item));	//������ȱ���
};

AdjMWGraph::AdjMWGraph(const int sz): Vertices(sz)
//���캯��
{
	for(int i = 0; i < sz; i++)
		for(int j = 0; j < sz; j++)
		{
			if(i == j) Edge[i][j] = 0;
			else Edge[i][j] = MaxWeight;
		}
	numOfEdges = 0;
}

VerT AdjMWGraph::GetValue(const int v)
//ȡ����v����ֵ
{
	if(v < 0 || v > Vertices.Size())
	{
		cout << "����vԽ�����!" << endl;
		exit(0);
	}
	return Vertices.GetData(v);
}

int AdjMWGraph::GetWeight(const int v1, const int v2)
//ȡ��ʼ����Ϊv1����ֹ����Ϊ v2�ıߵ�Ȩֵ
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "����v1��v2Խ�����!" << endl;
		exit(0);
	}
	return Edge[v1][v2];
}

void AdjMWGraph::InsertVertex(const VerT &vertex)
//���붥��vertex
{
	//�Ѷ���vertex���뵽˳���ĵ�ǰ��βλ��
	Vertices.Insert(vertex, Vertices.Size());
}

void AdjMWGraph::InsertEdge(const int v1, const int v2, int weight)
//����һ����ʼ����Ϊv1����ֹ����Ϊ v2��ȨֵΪweight�ı�
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "����v1��v2Խ�����!" << endl;
		exit(0);
	}
	Edge[v1][v2] = weight;							//�����
	numOfEdges++;									//�ߵĸ�����1
}

void AdjMWGraph::DeleteVertex(const int v)
//ɾ������v
{
	//ɾ�����а�������v�ı�
	for(int i = 0; i < Vertices.Size(); i++)
		for(int j = 0; j < Vertices.Size(); j++)
			if((i == v || j == v) && i != j && Edge[i][j] > 0 
				&& Edge[i][j] < MaxWeight) 
			{
				Edge[i][j] = MaxWeight;		//�Ѹñߵ�Ȩֵ��Ϊ�����
				numOfEdges--;				//�ߵĸ�����1
			}

	Vertices.Delete(v);								//ɾ������v
}

void AdjMWGraph::DeleteEdge(const int v1, const int v2)
//ɾ��һ����ʼ����Ϊv1����ֹ����Ϊ v2�ı�
{
	if(v1 < 0 || v1 > Vertices.Size() ||
		v2 < 0 || v2 > Vertices.Size() || v1 == v2)
	{
		cout << "����v1��v2����!" << endl;
		exit(0);
	}

	if(Edge[v1][v2] == MaxWeight || v1 == v2)
	{
		cout << "�ñ߲�����!" << endl;
		exit(0);
	}

	Edge[v1][v2] = MaxWeight;				//�Ѹñߵ�Ȩֵ��Ϊ�����
	numOfEdges--;							//�ߵĸ�����1
}

int AdjMWGraph::GetFirstNeighbor(const int v)
//ȡ����v�ĵ�һ���ڽӶ��㡣�����ڷ��ظö�����±���ţ����򷵻�-1
{
	if(v < 0 || v > Vertices.Size())
	{
		cout << "����v1Խ�����!" << endl;
		exit(0);
	}

	for(int col = 0; col <= Vertices.Size(); col++)
		if(Edge[v][col] > 0 && Edge[v][col] < MaxWeight) return col;
	return -1;
}

int AdjMWGraph::GetNextNeighbor(const int v1, const int v2)
//ȡ����v1���ڽӶ���v2����ڽӶ���
//�����ڷ��ظö�����±���ţ����򷵻�-1
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "����v1��v2Խ�����!" << endl;
		exit(0);
	}

	for(int col = v2+1; col <= Vertices.Size(); col++)
		if(Edge[v1][col] > 0 && Edge[v1][col] < MaxWeight) return col;
	return -1;
}

void AdjMWGraph::DepthFirstSearch(void Visit(VerT item))
{   int i;
	int *visited = new int[NumOfVertices()];
	for( i = 0; i < NumOfVertices(); i++) visited[i] = 0;
	for(i = 0; i < NumOfVertices(); i++)
		if(! visited[i]) DepthFirstSearch(i, visited, Visit);
	delete []visited;
}

void AdjMWGraph::DepthFirstSearch(const int v, int visited[], void Visit(VerT item))
{
	Visit(GetValue(v));
	visited[v] = 1;

	int w = GetFirstNeighbor(v);
	while(w != -1)
	{
		if(! visited[w]) DepthFirstSearch(w, visited, Visit);
		w = GetNextNeighbor(v, w);
	}
}

void AdjMWGraph::BroadFirstSearch(void Visit(VerT item))
{  // ���ڴ˲�������������ȱ�����ʵ��
}

#include "SeqQueue.h"					//������̬����ṹ��˳�������
void AdjMWGraph::BroadFirstSearch(const int v, int visited[], void Visit(VerT item))
{
	//���ڴ˲�����������ͨ����v����ͨ�����ı�����ʵ��
}
