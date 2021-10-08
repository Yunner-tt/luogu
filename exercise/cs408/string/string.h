#ifndef _String_h_
#define _String_h_
#define MaxSize 30
#define Bool bool

//�ַ����ṹ��
typedef struct String
{
  char data[MaxSize];
  int length;
}String;

void InitStr(String &S);//��ʼ��
Bool StrAssign(String &T, char *str, int strLength);//��ֵ����
void StrCopy(String &T, String S);//���Ʋ���
Bool StrEmpty(String S);//�п�
void Concat(String &T, String S1, String S2);//��������
Bool SubString(String &Sub, String S, int pos, int len);//���Ӵ�
int StrCompare(String S, String T);//�Ƚϲ�������S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0����S<T���򷵻�ֵ<0;
int StrLength(String S);//��ȡ�ַ�������
int Index(String S, String T);//��λ����,������S�д����봮Tֵ��ͬ���Ӵ����򷵻���������S�е�һ�γ��ֵ�λ�ã�������ֵΪ0��
int Index_Simple(String S, String T);//��ģʽƥ��
int Index_Simple_CSKaoYan(String S, String T);//��ģʽƥ�䡪�������̲�д��
int Index_KMP(String S, String T, int next[]);//KMP�㷨
void getNext(String T, int *next);//��ģʽ��T��next����
int Index_KMP1(String S, String T);//KMP2
void Get_BetterNext(String T, int betterNext[]);//�Ż�next����
void ClearStr(String &S);//��ղ���
void PrintString(String S, char* strName);

#endif