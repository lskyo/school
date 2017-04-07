#include  <iostream>
#include  <fstream>
#include  <cstdlib>
#include<conio.h>
#include<string>
using namespace std;

int const Max=100;//替换的子串的最大长度
#include"String.h"
#define InFile "test.in"
#define OutFile "test.out"
#define SIZE 20          /*  查找单词字符和输入替换单词少于20  */
#define MAXLEN 10000     /*  文章字符不大于10000  */

int main(void)
{
	int start,end,i;
	 int count=0;       /*  用于检查匹配计数  */
	 char ch;
	 String paper;    /*  用于保存读入的文本  */
	 String keyWords;   /*  查找单词  */
	 String copyWords; /*  替换单词  */
	 
	 fstream File;  //创建文件对象

      cout<<"请输入要查找的单词: ";
      cin>>keyWords;

      cout<<"请输入要替换的单词: ";
      cin>>copyWords;

      File.open (InFile,ios::in|ios::_Nocreate);//文件以输入方式打开，不建立文件，如果文件不存在，则打开文件失败
      if (!File) /*  读文件  */
	  {
         cout<<"文件打开失败!"<<endl;
         exit(1);
	  }
      File.unsetf(ios::skipws);  //不跳过空格
         while (File>>ch)/*  读文件  */
		 {
	          paper=paper+ch;
		 }
       File.close(); //关闭文件

       i=0;
       start=0;
	   int num=keyWords.getSize();
	   //////////////////////////////////////////////////////////
	   //请在此处填入相应的代码，从而完成对paper串的查找与替换 //
	   //////////////////////////////////////////////////////////
	   while((i=paper.FindSubstr(keyWords,start))!=-1)
	   {
		   count++;
		   paper.Delete(i,num);
		   paper.Insert(i,copyWords);
	   }
	   





    cout<<"共找到"<<count<<"处替换";
    fstream Fileout;
	Fileout.open(OutFile,ios::out);
	for(i=0;i<=paper.getSize();i++)
	 {
		 Fileout<<paper[i];    //将paper串输出到文件中
	 }
	 Fileout.close();
	  cout<<"请查看test.out文件"<<endl;
	  _getch();
	  return 0;
  
}
