struct HaffNode
//哈夫曼树的结点结构
{   DataType data;                          //结点数据
	int weight;								//权值
	int flag;								//标记
	int parent;								//双亲结点下标
	int leftChild;							//左孩子下标
	int rightChild;							//右孩子下标
};

struct Code
//存放哈夫曼编码的数据元素结构
{   DataType data;                         //编码对应数据
	int bit[MaxN];							//整形数组存放01串，也可使用其它类型如实际字符串
	int start;								//编码的起始下标
	int weight;								//字符的权值
};

void Haffman(int weight[],DataType data[], int n, HaffNode haffTree[])
{
	int i,j, m1, m2, x1, x2;

	for( i = 0; i < 2 * n - 1 ; i++)
	{
		if(i < n) 
		{
			haffTree[i].weight = weight[i];
            haffTree[i].data  = data[i];
		}
		else      
		haffTree[i].weight = 0;
		haffTree[i].parent = 0;
		haffTree[i].flag   = 0;
		haffTree[i].leftChild = -1;
		haffTree[i].rightChild = -1;
	}

	for(i = 0;i < n-1;i++)
	{
		m1 = m2 = MaxValue;
		x1 = x2 = 0;
		for(j = 0; j < n+i;j++)
		{
			if(haffTree[j].weight < m1 && haffTree[j].flag == 0)
			{
				m2 = m1;
				x2 = x1;
				m1 = haffTree[j].weight;
				x1 = j;
			}
			else if(haffTree[j].weight < m2 && haffTree[j].flag == 0)
			{
				m2 = haffTree[j].weight;
				x2 = j;
			}
		}

		haffTree[x1].parent  = n+i;   
		haffTree[x2].parent  = n+i;
		haffTree[x1].flag    = 1;
		haffTree[x2].flag    = 1;
		haffTree[n+i].weight = haffTree[x1].weight+haffTree[x2].weight;
		haffTree[n+i].leftChild = x1;
		haffTree[n+i].rightChild = x2;
	}
}

void HaffmanCode(HaffNode haffTree[], int n, Code haffCode[])
//由n个结点的哈夫曼树haffTree构造哈夫曼编码haffCode
{
	Code *cd = new Code;
	int child, parent;

	for(int i = 0; i < n; i++)		
	{
		cd->start = n-1;					
		cd->weight = haffTree[i].weight;	
		cd->data=haffTree[i].data ;        
		child = i;
		parent = haffTree[child].parent;


		while(parent != 0)
		{
			if(haffTree[parent].leftChild == child)
				cd->bit[cd->start] = 0;			
			else							
				cd->bit[cd->start] = 1;				
			cd->start--;
			child = parent;
			parent = haffTree[child].parent;
		}

		for(int j = cd->start+1; j < n; j++) 
			haffCode[i].bit[j] = cd->bit[j];
		haffCode[i].start  = cd->start;
		haffCode[i].weight = cd->weight;	
		haffCode[i].data = cd->data;		
	}
	delete cd;
}

void Print(HaffNode haffTree[],int n,int level)
//请根据二叉树的凹入打印输出实现哈夫曼树的输出
{
	if(haffTree[n].rightChild!=-1)
	{
		Print(haffTree,haffTree[n].rightChild,level+1);
	}
	for(int i=0;i<level;i++)
	{
		if(i==level-1)
			printf("  ----");
		else
			printf("      ");
	}
	cout<<haffTree[n].data<<endl;
	if(haffTree[n].leftChild!=-1)
		Print(haffTree,haffTree[n].leftChild,level+1);
}