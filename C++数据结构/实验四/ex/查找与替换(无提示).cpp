#include  <iostream>
#include  <fstream>
#include  <cstdlib>
#include<conio.h>
#include<string>
using namespace std;

int const Max=100;//�滻���Ӵ�����󳤶�
#include"String.h"
#define InFile "test.in"
#define OutFile "test.out"
#define SIZE 20          /*  ���ҵ����ַ��������滻��������20  */
#define MAXLEN 10000     /*  �����ַ�������10000  */

int main(void)
{
	int start,end,i;
	 int count=0;       /*  ���ڼ��ƥ�����  */
	 char ch;
	 String paper;    /*  ���ڱ��������ı�  */
	 String keyWords;   /*  ���ҵ���  */
	 String copyWords; /*  �滻����  */
	 
	 fstream File;  //�����ļ�����

      cout<<"������Ҫ���ҵĵ���: ";
      cin>>keyWords;

      cout<<"������Ҫ�滻�ĵ���: ";
      cin>>copyWords;

      File.open (InFile,ios::in|ios::_Nocreate);//�ļ������뷽ʽ�򿪣��������ļ�������ļ������ڣ�����ļ�ʧ��
      if (!File) /*  ���ļ�  */
	  {
         cout<<"�ļ���ʧ��!"<<endl;
         exit(1);
	  }
      File.unsetf(ios::skipws);  //�������ո�
         while (File>>ch)/*  ���ļ�  */
		 {
	          paper=paper+ch;
		 }
       File.close(); //�ر��ļ�

       i=0;
       start=0;
	   int num=keyWords.getSize();
	   //////////////////////////////////////////////////////////
	   //���ڴ˴�������Ӧ�Ĵ��룬�Ӷ���ɶ�paper���Ĳ������滻 //
	   //////////////////////////////////////////////////////////
	   while((i=paper.FindSubstr(keyWords,start))!=-1)
	   {
		   count++;
		   paper.Delete(i,num);
		   paper.Insert(i,copyWords);
	   }
	   





    cout<<"���ҵ�"<<count<<"���滻";
    fstream Fileout;
	Fileout.open(OutFile,ios::out);
	for(i=0;i<=paper.getSize();i++)
	 {
		 Fileout<<paper[i];    //��paper��������ļ���
	 }
	 Fileout.close();
	  cout<<"��鿴test.out�ļ�"<<endl;
	  _getch();
	  return 0;
  
}
