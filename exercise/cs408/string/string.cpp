#include <bits/stdc++.h>
using namespace std;
#include "string.h"

//��ʼ��
void InitStr(String &S)
{
  S.data[1] = '\0'; //���ַ���������������Ϊ��ʼ״̬
  S.length = 0;
}

//��ֵ����
bool StrAssign(String &T, char *str, int strLength)
{
  if (str[0] == '\0')
    return false; //����������ʧ��,�������ݳ�ʼ����������ղ�������
  for (int i = 0; i < strLength; ++i)
  {                         //��һ��Ϊʲô����i<strLength
    T.data[i + 1] = str[i]; //����T�ĵ�һ��Ԫ��λ��
  }
  T.length = strLength;
  return true;
}

//���Ʋ���
void StrCopy(String &T, String S)
{
  for (int i = 1; i <= S.length; ++i)
  { //��һ��Ϊʲô����i<=S.length
    T.data[i] = S.data[i];
  }
  T.length = S.length;
}

//�п�
bool StrEmpty(String S)
{
  return S.length == 0;
}

//��������
void Concat(String &T, String S1, String S2)
{
  for (int i = 1; i <= S1.length; i++)
  {
    T.data[i] = S1.data[i];
  }
  for (int j = S1.length + 1; j <= S1.length + S2.length; j++)
  {
    T.data[j] = S2.data[j - S1.length]; //����ú���һ��ѭ���������������±�
  }
  T.length = S1.length + S2.length;
}

//���Ӵ�
bool SubString(String &Sub, String S, int pos, int len)
{
  if (pos + len - 1 > S.length)
    return false;
  for (int i = pos; i < pos + len; ++i)
    Sub.data[i - pos + 1] = S.data[i];
  Sub.length = len;
  return true;
}

//�Ƚϲ�������S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0����S<T���򷵻�ֵ<0;
int StrCompare(String S, String T)
{
  for (int i = 1; i <= S.length & i <= T.length; i++)
  {
    if (S.data[i] != T.data[i])
      return S.data[i] - T.data[i];
  }
  //ɨ����������ַ�����ͬ���򳤶ȳ��Ĵ�����
  return S.length - T.length;
}

//��ȡ�ַ�������
int StrLength(String S)
{
  return S.length;
}

//��λ����,������S�д����봮Tֵ��ͬ���Ӵ����򷵻���������S�е�һ�γ��ֵ�λ�ã�������ֵΪ0��
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
      return i; //�����Ӵ��������е�λ��
  }
  return 0; //S�в�������T��ȵ��Ӵ�
}

//��ղ���
void ClearStr(String &S)
{
  S.length = 0;
  memset(S.data, '\0', MaxSize); //�õ���һ��cstring���е�memset����
}

void PrintString(String S,char *strName)
{
  //ѭ����ӡ
  printf("%s:[ ",strName);
  for (int i = 0; i <= S.length; i++)
  {
    if (S.data[i] != '\0')
      printf("%c", S.data[i]); //ע����������ַ��õ���%c����%s�����һ���ַ���
  }
  printf("]\n");
}
//��ģʽƥ��
int Index_Simple(String S, String T)
{
  int k = 1;        //k��¼��ǰ����ָ��
  int i = k, j = 1; //j��¼ģʽ��ָ�룬i��¼��������ģʽ�����жԱȵ��Ӵ�����ʼ��ַ
  while (i <= S.length && j <= T.length)
  {
    if (S.data[i] == T.data[j])
    {
      ++i;
      ++j; //�����ȽϺ����ַ�
    }
    else
    {
      k++; //�����һ���ִ�
      i = k;
      j = 1; //����j��ֵ
    }
  }
  if (j > T.length)
  { //ƥ��ɹ�
    return k;
  }
  else
  {
    return 0;
  }
}

//��ģʽƥ�䡪�������̲�д��
int Index_Simple_CSKaoYan(String S, String T)
{
  int i = 1; //i��¼��ǰ����ָ��
  int j = 1; //j��¼ģʽ��ָ��
  while (i <= S.length && j <= T.length)
  {
    if (S.data[i] == T.data[j])
    {
      ++i;
      ++j; //�����ȽϺ����ַ�
    }
    else
    {
      i = i - j + 2; //�����һ���ִ�
      j = 1;         //����j��ֵ
    }
  }
  if (j > T.length)
  { //ƥ��ɹ�
    return i - T.length;
  }
  else
  {
    return 0;
  }
}

//��ģʽ��T��next����
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
      //���pi=pj����next[j+1]=next[j]+1
      next[i] = j;
    }
    else
    {
      //������j=next[j],ѭ������
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
      ++j; //�����ȽϺ���ַ�
    }
    else
    {
      j = next[j]; //ģʽ�������ƶ�
    }
  }
  if (j > T.length) //ƥ��ɹ�
    return i - T.length;
  else
    return 0;
}

//�Ż�next����
void Get_BetterNext(String T, int *betterNext)
{
  int i = 1, j = 0;
  int next[T.length + 1];
  getNext(T, next);  //�����next����
  betterNext[1] = 0; //��betterNext[1]=0
  for (int j = 2; j <= T.length; ++j)
  {
    if (T.data[next[j]] == T.data[j])
      betterNext[j] = betterNext[next[j]]; //�����漰��������ĶԱȣ���ϸ����
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
      ++j; //�����ȽϺ���ַ�
    }
    else
    {
      j = next[j]; //ģʽ�������ƶ�
    }
  }
  if (j > T.length) //ƥ��ɹ�
    return i - T.length;
  else
    return 0;
}
