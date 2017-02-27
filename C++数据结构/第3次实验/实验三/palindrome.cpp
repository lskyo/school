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
  cout<<"请输入一个字符串：";
  cin.getline(s,Max);  //输入一行字符串
  i=0;
  ////////////////////////////////////// 
  //请在此利用顺序栈把s串逆序存放在t中//
  /////////////////////////////////////
  if(strcmp(s,t) == 0) cout<<s<<" 是一个回文串"<<endl;  //t为s的逆序串
  else cout<<s<<" 不是一个回文串"<<endl;
  getch(); 
  return 0;
}
