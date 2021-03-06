#include "SeqList.h"					//包含动态数组结构的顺序表类

class AdjMWGraph                         //图的邻接矩阵类
{
private:
	SeqList Vertices;								//顶点顺序表
	int Edge[MaxVertices][MaxVertices];				//边权值数组
	int numOfEdges;									//边的个数
    //与V连通的连通分量的深度优先遍历
	void DepthFirstSearch(const int v, int visited[],void Visit(VerT item));
    //与V连通的连通分量的广度优先遍历
	void BroadFirstSearch(const int v, int visited[], void Visit(VerT item));
	
public:
	AdjMWGraph(const int sz = MaxVertices);			//构造函数
	~AdjMWGraph(void){};							//析构函数

	int NumOfVertices(void)							//取顶点个数
		{return Vertices.Size();}
	int NumOfEdges(void)							//取边的个数
		{return numOfEdges;}
	VerT GetValue(const int v);						//取顶点数值
	int GetWeight(const int v1, const int v2);		//取边的权值

	void InsertVertex(const VerT &vertex);			//插入顶点
	void InsertEdge(const int v1, const int v2, int weight);//插入边
	void DeleteVertex(const int v);					//删除顶点
	void DeleteEdge(const int v1, const int v2);	//删除边
	int GetFirstNeighbor(const int v);				//取第一个邻接顶点
	int GetNextNeighbor(const int v1, const int v2);//取下一个邻接顶点
     
	void DepthFirstSearch(void Visit(VerT item));	//深度优先遍历
	void BroadFirstSearch(void Visit(VerT item));	//广度优先遍历
	
};

AdjMWGraph::AdjMWGraph(const int sz): Vertices(sz)
//构造函数
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
//取顶点v的数值
{
	if(v < 0 || v > Vertices.Size())
	{
		cout << "参数v越界出错!" << endl;
		exit(0);
	}
	return Vertices.GetData(v);
}

int AdjMWGraph::GetWeight(const int v1, const int v2)
//取起始顶点为v1、终止顶点为 v2的边的权值
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "参数v1或v2越界出错!" << endl;
		exit(0);
	}
	return Edge[v1][v2];
}

void AdjMWGraph::InsertVertex(const VerT &vertex)
//插入顶点vertex
{
	//把顶点vertex插入到顺序表的当前表尾位置
	Vertices.Insert(vertex, Vertices.Size());
}

void AdjMWGraph::InsertEdge(const int v1, const int v2, int weight)
//插入一条起始顶点为v1、终止顶点为 v2、权值为weight的边
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "参数v1或v2越界出错!" << endl;
		exit(0);
	}
	Edge[v1][v2] = weight;							//插入边
	numOfEdges++;									//边的个数加1
}

void AdjMWGraph::DeleteVertex(const int v)
//删除顶点v
{
	//删除所有包含顶点v的边
	for(int i = 0; i < Vertices.Size(); i++)
		for(int j = 0; j < Vertices.Size(); j++)
			if((i == v || j == v) && i != j && Edge[i][j] > 0 
				&& Edge[i][j] < MaxWeight) 
			{
				Edge[i][j] = MaxWeight;		//把该边的权值置为无穷大
				numOfEdges--;				//边的个数减1
			}

	Vertices.Delete(v);								//删除顶点v
}

void AdjMWGraph::DeleteEdge(const int v1, const int v2)
//删除一条起始顶点为v1、终止顶点为 v2的边
{
	if(v1 < 0 || v1 > Vertices.Size() ||
		v2 < 0 || v2 > Vertices.Size() || v1 == v2)
	{
		cout << "参数v1或v2出错!" << endl;
		exit(0);
	}

	if(Edge[v1][v2] == MaxWeight || v1 == v2)
	{
		cout << "该边不存在!" << endl;
		exit(0);
	}

	Edge[v1][v2] = MaxWeight;				//把该边的权值置为无穷大
	numOfEdges--;							//边的个数减1
}

int AdjMWGraph::GetFirstNeighbor(const int v)
//取顶点v的第一个邻接顶点。若存在返回该顶点的下标序号，否则返回-1
{
	if(v < 0 || v > Vertices.Size())
	{
		cout << "参数v1越界出错!" << endl;
		exit(0);
	}

	for(int col = 0; col <= Vertices.Size(); col++)
		if(Edge[v][col] > 0 && Edge[v][col] < MaxWeight) return col;
	return -1;
}

int AdjMWGraph::GetNextNeighbor(const int v1, const int v2)
//取顶点v1的邻接顶点v2后的邻接顶点
//若存在返回该顶点的下标序号，否则返回-1
{
	if(v1 < 0 || v1 > Vertices.Size() || v2 < 0 || v2 > Vertices.Size())
	{
		cout << "参数v1或v2越界出错!" << endl;
		exit(0);
	}

	for(int col = v2+1; col <= Vertices.Size(); col++)
		if(Edge[v1][col] > 0 && Edge[v1][col] < MaxWeight) return col;
	return -1;
}

void AdjMWGraph::DepthFirstSearch(void Visit(VerT item))
//图的深度优先遍历
{   int i;
	int *visited = new int[NumOfVertices()];
	for( i = 0; i < NumOfVertices(); i++) visited[i] = 0;
	for(i = 0; i < NumOfVertices(); i++)
		if(! visited[i]) DepthFirstSearch(i, visited, Visit);
	delete []visited;
}

void AdjMWGraph::DepthFirstSearch(const int v, int visited[], void Visit(VerT item))
//与邻接点V连通的连通分量的深度优先遍历
{
	//算法思想：
    //	访问顶点v；
    //从v的未被访问的邻接点中选取一个顶点w，从w出发进行深度优先遍历；
    //	重复上述两步，直至图中所有和v有路径相通的顶点都被访问到。
    //请自行完成

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
{  
     //图的广度优先遍历,
     //图的每一个顶点都作为一次初始顶点进行广度优先遍历
     //根据顶点的访问标记来判断是否需要访问该顶点，从而访问图中的所有顶点
     //请自行完成 


	int *visited = new int[NumOfVertices()];
	for(int i = 0; i < NumOfVertices(); i++) visited[i] = 0;
	for(int i = 0; i < NumOfVertices(); i++)
		if(!visited[i]) BroadFirstSearch(i, visited, Visit);
	delete []visited;
   
}

#include "SeqQueue.h"					//包含静态数组结构的顺序队列类
void AdjMWGraph::BroadFirstSearch(const int v, int visited[], void Visit(VerT item))
{
	
	//算法思想：
	//访问顶点v；
	//	依次访问v的各个未被访问的邻接点v1, v2, …, vk；
	//	分别从v1，v2，…，vk出发依次访问它们未被访问的邻接点，
	//并使“先被访问顶点的邻接点”先于“后被访问顶点的邻接点”被访问。
	//直至图中所有与顶点v有路径相通的顶点都被访问到。
	//请在此补充完整连通顶点v的连通分量的广度遍历

	VerT u, w;
	SeqQueue queue;
	Visit(GetValue(v));
	visited[v] = 1;
	queue.Append(v);
	while(queue.NotEmpty())
	{
		u = queue.Delete();
		w = GetFirstNeighbor(u);
		while(w != -1)
		{
			if(!visited[w])
			{
				Visit(GetValue(w));
				visited[w] = 1;
				queue.Append(w);
			}
			w = GetNextNeighbor(u, w);
		}
	}
}
	
