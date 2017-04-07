#include <iostream>
#include <stdlib.h>
#include<conio.h>
#include <fstream> 

using namespace std;

const int MaxValue = 10000;					//初始设定的权值最大值
const int MaxBit = 128;						//初始设定的最大编码位数
const int MaxN =128;						//初始设定的最大结点个数

typedef char DataType;
#include "HaffmanTree.h"

void main(void)
{
	int i, j, n = 128;
	char ch;
	int weight[128]={0};//字符权重
	
	//初值值设置ASCII码各字符的权值为1，
	for(i=0;i<128;i++)
	{   
	    weight[i]=1;		
	}
	
	//读文件，求出文件中ASCII码表中各个字符的频度
    fstream sourceFile("source.txt" , ios::in);
	if(sourceFile == NULL) 
        cout << "源文件指定位置不存在！" <<endl; 
        
    //根据源文件出现字符的次数修改字符的权值，请完成这部分内容
	while( ？)//从文件中读入一个字符存进ch
	{  
	                         //计算ch字符出现的次数,修改ch的权值
	}
	
    //源文件读写头返回到文件开始
	sourceFile.clear(); 
    sourceFile.seekg(0);
	if(sourceFile == NULL) 
        cout << "源文件指定位置不存在！" <<endl; 

	//将ASCII码表中的128个字符保存在data数组中
	char data[128];
	for(i=0;i<=127;i++)
	{
		data[i]=i;
	}
	
	HaffNode *myHaffTree = new HaffNode[2*n-1];
	Code *myHaffCode = new Code[n];
	if(n > MaxN)
	{
		cout << "定义的n越界，修改MaxN! " << endl;
		exit(0);
	}
	//调用函数创建哈夫曼树，并相应结点进行哈夫曼编码，请自行完成
	Haffman(？);
	HaffmanCode(？);

	//输出128个ASCII码字符在文档中出现的次数，及对应的哈夫曼编码
	for(i = 0; i < n; i++)
	{
		//如实验六所示输出相应结点的数据、权值及相应的哈夫曼编码，请自行完成
	}

    //从文件"source.txt"中读取电文，并把电文编码后写入"out.txt"
    fstream outFile("out.txt" , ios::out);
    if(outFile == NULL) 
        cout << "压缩文件指定位置不存在！"<<endl ;
	
	while(sourceFile.get(ch))//读入一个字符存进ch
	{   
	   //将字符ch编码存入"out.txt"，请自行完成
	}
	sourceFile.close();
	outFile.close();
	
	//请课后思考如何进行电文解码
	system("pause");
}
