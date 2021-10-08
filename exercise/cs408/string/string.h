#ifndef _String_h_
#define _String_h_
#define MaxSize 30
#define Bool bool

//字符串结构体
typedef struct String
{
  char data[MaxSize];
  int length;
}String;

void InitStr(String &S);//初始化
Bool StrAssign(String &T, char *str, int strLength);//赋值操作
void StrCopy(String &T, String S);//复制操作
Bool StrEmpty(String S);//判空
void Concat(String &T, String S1, String S2);//串链操作
Bool SubString(String &Sub, String S, int pos, int len);//求子串
int StrCompare(String S, String T);//比较操作，若S>T,则返回值>0;若S=T,则返回值=0；若S<T，则返回值<0;
int StrLength(String S);//获取字符串长度
int Index(String S, String T);//定位操作,若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置，否则函数值为0；
int Index_Simple(String S, String T);//简单模式匹配
int Index_Simple_CSKaoYan(String S, String T);//简单模式匹配——王道教材写法
int Index_KMP(String S, String T, int next[]);//KMP算法
void getNext(String T, int *next);//求模式串T的next数组
int Index_KMP1(String S, String T);//KMP2
void Get_BetterNext(String T, int betterNext[]);//优化next数组
void ClearStr(String &S);//清空操作
void PrintString(String S, char* strName);

#endif