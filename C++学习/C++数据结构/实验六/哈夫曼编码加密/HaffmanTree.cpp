#include <iostream>
#include <stdlib.h>
#include<conio.h>
#include <fstream> 

using namespace std;

const int MaxValue = 10000;					//��ʼ�趨��Ȩֵ���ֵ
const int MaxBit = 128;						//��ʼ�趨��������λ��
const int MaxN =128;						//��ʼ�趨����������

typedef char DataType;
#include "HaffmanTree.h"

void main(void)
{
	int i, j, n = 128;
	char ch;
	int weight[128]={0};//�ַ�Ȩ��
	
	//��ֵֵ����ASCII����ַ���ȨֵΪ1��
	for(i=0;i<128;i++)
	{   
	    weight[i]=1;		
	}
	
	//���ļ�������ļ���ASCII����и����ַ���Ƶ��
    fstream sourceFile("source.txt" , ios::in);
	if(sourceFile == NULL) 
        cout << "Դ�ļ�ָ��λ�ò����ڣ�" <<endl; 
        
    //����Դ�ļ������ַ��Ĵ����޸��ַ���Ȩֵ��������ⲿ������
	while( ��)//���ļ��ж���һ���ַ����ch
	{  
	                         //����ch�ַ����ֵĴ���,�޸�ch��Ȩֵ
	}
	
    //Դ�ļ���дͷ���ص��ļ���ʼ
	sourceFile.clear(); 
    sourceFile.seekg(0);
	if(sourceFile == NULL) 
        cout << "Դ�ļ�ָ��λ�ò����ڣ�" <<endl; 

	//��ASCII����е�128���ַ�������data������
	char data[128];
	for(i=0;i<=127;i++)
	{
		data[i]=i;
	}
	
	HaffNode *myHaffTree = new HaffNode[2*n-1];
	Code *myHaffCode = new Code[n];
	if(n > MaxN)
	{
		cout << "�����nԽ�磬�޸�MaxN! " << endl;
		exit(0);
	}
	//���ú���������������������Ӧ�����й��������룬���������
	Haffman(��);
	HaffmanCode(��);

	//���128��ASCII���ַ����ĵ��г��ֵĴ���������Ӧ�Ĺ���������
	for(i = 0; i < n; i++)
	{
		//��ʵ������ʾ�����Ӧ�������ݡ�Ȩֵ����Ӧ�Ĺ��������룬���������
	}

    //���ļ�"source.txt"�ж�ȡ���ģ����ѵ��ı����д��"out.txt"
    fstream outFile("out.txt" , ios::out);
    if(outFile == NULL) 
        cout << "ѹ���ļ�ָ��λ�ò����ڣ�"<<endl ;
	
	while(sourceFile.get(ch))//����һ���ַ����ch
	{   
	   //���ַ�ch�������"out.txt"�����������
	}
	sourceFile.close();
	outFile.close();
	
	//��κ�˼����ν��е��Ľ���
	system("pause");
}
