#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include "SeqStack.h"

int main()
{ 
  char s[Max]="",t[Max]="";
  int i;
  SeqStack st(Max);
  cout<<"������һ���ַ�����";
  cin.getline(s,Max);  //����һ���ַ���
  i=0;


  ////////////////////////////////////// 
  //���ڴ�����˳��ջ��s����������t��//
  /////////////////////////////////////
  for(i;i<Max && s[i]!='\0';i++)
  {
	  st.Push(s[i]);
  }
  for(int j=0;j<i;j++)
  {
	  t[j]=st.Pop();
  }

  if(strcmp(s,t) == 0) cout<<s<<" ��һ�����Ĵ�"<<endl;  //tΪs������
  else cout<<s<<" ����һ�����Ĵ�"<<endl;
  getch(); 
  return 0;
}
