#include <bits/stdc++.h>
using namespace std;
#include "string.h"

//初始化
void InitStr(String &S)
{
  S.data[1] = '\0'; //以字符串结束符号来作为初始状态
  S.length = 0;
}

//赋值操作
bool StrAssign(String &T, char *str, int strLength)
{
  if (str[0] == '\0')
    return false; //传入空数组就失败,条件依据初始化操作和清空操作而定
  for (int i = 0; i < strLength; ++i)
  {                         //想一想为什么这是i<strLength
    T.data[i + 1] = str[i]; //空置T的第一个元素位置
  }
  T.length = strLength;
  return true;
}

//复制操作
void StrCopy(String &T, String S)
{
  for (int i = 1; i <= S.length; ++i)
  { //想一想为什么这是i<=S.length
    T.data[i] = S.data[i];
  }
  T.length = S.length;
}

//判空
bool StrEmpty(String S)
{
  return S.length == 0;
}

//串链操作
void Concat(String &T, String S1, String S2)
{
  for (int i = 1; i <= S1.length; i++)
  {
    T.data[i] = S1.data[i];
  }
  for (int j = S1.length + 1; j <= S1.length + S2.length; j++)
  {
    T.data[j] = S2.data[j - S1.length]; //这里好好想一下循环的条件及数组下标
  }
  T.length = S1.length + S2.length;
}

//求子串
bool SubString(String &Sub, String S, int pos, int len)
{
  if (pos + len - 1 > S.length)
    return false;
  for (int i = pos; i < pos + len; ++i)
    Sub.data[i - pos + 1] = S.data[i];
  Sub.length = len;
  return true;
}

//比较操作，若S>T,则返回值>0;若S=T,则返回值=0；若S<T，则返回值<0;
int StrCompare(String S, String T)
{
  for (int i = 1; i <= S.length & i <= T.length; i++)
  {
    if (S.data[i] != T.data[i])
      return S.data[i] - T.data[i];
  }
  //扫描过的所有字符都相同，则长度长的串更大
  return S.length - T.length;
}

//获取字符串长度
int StrLength(String S)
{
  return S.length;
}

//定位操作,若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置，否则函数值为0；
int Index(String S, String T)
{
  int i = 1, n = StrLength(S), m = StrLength(T);
  String sub;
  while (i <= n - m + 1)
  {
    SubString(sub, S, i, m);
    if (StrCompare(sub, T) != 0)
      ++i;
    else
      return i; //返回子串在主串中的位置
  }
  return 0; //S中不存在与T相等的子串
}

//清空操作
void ClearStr(String &S)
{
  S.length = 0;
  memset(S.data, '\0', MaxSize); //用到了一个cstring库中的memset函数
}

void PrintString(String S,char *strName)
{
  //循环打印
  printf("%s:[ ",strName);
  for (int i = 0; i <= S.length; i++)
  {
    if (S.data[i] != '\0')
      printf("%c", S.data[i]); //注意输出单个字符用的是%c，而%s是输出一个字符串
  }
  printf("]\n");
}
//简单模式匹配
int Index_Simple(String S, String T)
{
  int k = 1;        //k记录当前主串指针
  int i = k, j = 1; //j记录模式串指针，i记录主串中与模式串进行对比的子串的起始地址
  while (i <= S.length && j <= T.length)
  {
    if (S.data[i] == T.data[j])
    {
      ++i;
      ++j; //继续比较后续字符
    }
    else
    {
      k++; //检查下一个字串
      i = k;
      j = 1; //重制j的值
    }
  }
  if (j > T.length)
  { //匹配成功
    return k;
  }
  else
  {
    return 0;
  }
}

//简单模式匹配——王道教材写法
int Index_Simple_CSKaoYan(String S, String T)
{
  int i = 1; //i记录当前主串指针
  int j = 1; //j记录模式串指针
  while (i <= S.length && j <= T.length)
  {
    if (S.data[i] == T.data[j])
    {
      ++i;
      ++j; //继续比较后续字符
    }
    else
    {
      i = i - j + 2; //检查下一个字串
      j = 1;         //重制j的值
    }
  }
  if (j > T.length)
  { //匹配成功
    return i - T.length;
  }
  else
  {
    return 0;
  }
}

//求模式串T的next数组
void getNext(String T, int *next)
{
  int i = 1, j = 0;
  next[1] = 0;
  while (i < T.length)
  {
    if (j == 0 || T.data[i] == T.data[j])
    {
      ++i;
      ++j;
      //如果pi=pj，则next[j+1]=next[j]+1
      next[i] = j;
    }
    else
    {
      //否则令j=next[j],循环继续
      j = next[j];
    }
  }
}

//KMP1
int Index_KMP(String S, String T)
{
  int i = 1, j = 1;
  int next[T.length + 1];
  getNext(T, next);
  while (i <= S.length && j <= T.length)
  {
    if (j == 0 || S.data[i] == T.data[j])
    {
      ++i;
      ++j; //继续比较后继字符
    }
    else
    {
      j = next[j]; //模式串向右移动
    }
  }
  if (j > T.length) //匹配成功
    return i - T.length;
  else
    return 0;
}

//优化next数组
void Get_BetterNext(String T, int *betterNext)
{
  int i = 1, j = 0;
  int next[T.length + 1];
  getNext(T, next);  //先求出next数组
  betterNext[1] = 0; //令betterNext[1]=0
  for (int j = 2; j <= T.length; ++j)
  {
    if (T.data[next[j]] == T.data[j])
      betterNext[j] = betterNext[next[j]]; //这里涉及三个数组的对比，仔细看看
    else
      betterNext[j] = next[j];
  }
}
//KMP1
int Index_KMP1(String S, String T, int next[])
{
  int i = 1, j = 1;
  //    int next[T.length + 1];
  //    getNext(T, next);
  while (i <= S.length && j <= T.length)
  {
    if (j == 0 || S.data[i] == T.data[j])
    {
      ++i;
      ++j; //继续比较后继字符
    }
    else
    {
      j = next[j]; //模式串向右移动
    }
  }
  if (j > T.length) //匹配成功
    return i - T.length;
  else
    return 0;
}
