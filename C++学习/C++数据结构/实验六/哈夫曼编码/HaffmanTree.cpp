#include <iostream>
#include <stdlib.h>
#include<conio.h>
#include <fstream> 
using namespace std;

const int MaxValue = 10000;					//��ʼ�趨��Ȩֵ���ֵ
const int MaxBit = 4;						//��ʼ�趨��������λ��
const int MaxN = 10;						//��ʼ�趨����������
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
		cout << "�����nԽ�磬�޸�MaxN! " << endl;
		exit(0);
	}
	Haffman(weight, data,n, myHaffTree);//�������������������
	/////////////////////
	//��������������//
	///////////////////
	Print(myHaffTree,2*n-2,0);
	HaffmanCode(myHaffTree, n, myHaffCode);//����������

	//���ÿ��Ҷ���Ĺ���������
	for(i = 0; i < n; i++)
	{
		cout << "data="<<data[i]<<"   Weight = " << myHaffCode[i].weight << "   Code = ";
		for(j = myHaffCode[i].start+1; j < n; j++)
			cout << myHaffCode[i].bit[j];
		cout << endl;
	}

    //������ģ��������
    char paper[100];
	cin.getline (paper,100);
	cout<<"�����ĵ���Ϊ��"<<endl;
	for(i = 0;i <strlen(paper); i++)
	{
		for(j = myHaffCode[paper[i]-'A'].start+1; j < n; j++)
			cout << myHaffCode[paper[i]-'A'].bit[j];
		cout << " ";
	}
	getchar();
     
}
