#include <iostream>
#include <stdlib.h>
#include<conio.h>
#include <fstream> 
using namespace std;

const int MaxValue = 10000;					//初始设定的权值最大值
const int MaxBit = 4;						//初始设定的最大编码位数
const int MaxN = 10;						//初始设定的最大结点个数
typedef char DataType;
#include "HaffmanTree.h"

void main(void)
{
	int i, j, n = 4;
	int weight[] = {1,3,5,7};
	DataType data[]={'A','B','C','D'};
	HaffNode *myHaffTree = new HaffNode[2*n+1];
	Code *myHaffCode = new Code[n];
	if(n > MaxN)
	{
		cout << "定义的n越界，修改MaxN! " << endl;
		exit(0);
	}
	Haffman(weight, data,n, myHaffTree);//创建哈夫曼树结点数据
	/////////////////////
	//添加输出哈夫曼树//
	///////////////////
	Print(myHaffTree,2*n-2,0);
	HaffmanCode(myHaffTree, n, myHaffCode);//哈夫曼编码

	//输出每个叶结点的哈夫曼编码
	for(i = 0; i < n; i++)
	{
		cout << "data="<<data[i]<<"   Weight = " << myHaffCode[i].weight << "   Code = ";
		for(j = myHaffCode[i].start+1; j < n; j++)
			cout << myHaffCode[i].bit[j];
		cout << endl;
	}

    //输入电文，编码电文
    char paper[100];
	cin.getline (paper,100);
	cout<<"编码后的电文为："<<endl;
	for(i = 0;i <strlen(paper); i++)
	{
		for(j = myHaffCode[paper[i]-'A'].start+1; j < n; j++)
			cout << myHaffCode[paper[i]-'A'].bit[j];
		cout << " ";
	}
	getchar();
     
}
