#include <stdio.h>
#include <stdlib.h>

#include "linkList.h"

Status InitList_Sq(struct Sqlist &L)
{ 
	//����һ���յ����Ա�L
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(struct Sqlist));
	if(!L.elem)
		return (OVERFLOW);			//�洢����ʧ��
	L.length = 0;					// �ձ���Ϊ0
	L.listsize = LIST_INIT_SIZE;	// ��ʼ�洢����
	return OK;
} // InitList_Sq

void DestoryList_Sq(struct Sqlist &L)
{
	//�������Ա�L
	//Ҫ�����Ա�L����
	free(L.elem);
	L.elem = NULL;
} //DestoryList_Sq_Sq

void ClearList_Sq(struct Sqlist &L)
{
	//��L����Ϊ�ձ�
	//Ҫ�����Ա�L����
	L.length = 0;
} //ClearList_Sq

Status ListEmpyt_Sq(struct Sqlist L)
{
	//��LΪ�ձ�����TRUE�����򷵻�FALSE
	//Ҫ�����Ա�L����
	if(0 == L.length)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
} // ListEmpyt_Sq

Status ListLength_Sq(struct Sqlist L)
{
	//Ҫ�����Ա��Ѵ���
	//����L������Ԫ�ظ���
	return L.length;
} //ListLength_Sq

void GetElem_Sq(struct Sqlist L, int i, ElemType &e)
{
	//Ҫ�����Ա���ڣ�1<=i<=ListLength_Sq(L)
	//e����L�е�i������Ԫ�ص�ֵ
	e = *(L.elem + i - 1);
} //GetElem_Sq

Status compare_equal_Sq(ElemType e1, ElemType e2)
{
	//�ж���������Ԫ���Ƿ���ȣ���ȷ���TRUE�����ȷ���FALSE
	if(e1 == e2)
		return TRUE;
	else
		return FALSE;
} //compare_equal_Sq

Status LocateElem_Sq(struct Sqlist L, ElemType e, Status (*compare)(ElemType, ElemType))
{
	//���Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����
	//����L�е�һ����e�����ϵ��compare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ�����0
	ElemType * p = L.elem;
	int i; // λ��
	for(i=1; i<=L.length; i++)
	{
		if(compare(e, *(p+i-1)))
		{
			return i;
		}
	}
	return 0;
} //LocateElem_Sq

Status PriorElem_Sq(struct Sqlist L, ElemType cur_e, ElemType &pre_e)
{
	//Ҫ�����Ա�L����
	//��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
	int pos;
	pos = LocateElem_Sq(L, cur_e, compare_equal_Sq);
	if(!pos || 1 == pos)  // Ԫ��cur_e��L�в����ڻ�Ϊ��һ��
		return NOTEXIT;
	else
		return *(L.elem+pos-2);
} //PriorElem_Sq


Status NextrElem_Sq(struct Sqlist L, ElemType cur_e, ElemType &next_e)
{
	//Ҫ�����Ա�L����
	//��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ������������ʧ�ܣ�next_e�޶���
	int pos;
	pos = LocateElem_Sq(L, cur_e, compare_equal_Sq);
	if(!pos || L.length == pos)  // Ԫ��cur_e��L�в����ڻ�Ϊ���һ��
		return NOTEXIT;
	else
		return *(L.elem+pos);
} //NextrElem_Sq


void ListInsert_Sq(struct Sqlist &L, int i, ElemType e)
{
	//Ҫ�����Ա���ڣ�1<=i<=ListLength_Sq(L)+1
	//�ڵ�i��λ��֮ǰ��������Ԫ��e, L�ĳ��ȼ�1

	int j;
	ElemType * newbase;
	if(L.length+1 > L.listsize)
	{
		newbase = (ElemType *)realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			exit(OVERFLOW);   //�洢����ʧ��
		L.elem = newbase;  // �»�ַ
		L.listsize += LISTINCREMENT;  // ���Ӵ洢����
	}
	for(j=L.length; j>=i; j--)
	{
		*(L.elem+j) = *(L.elem+j-1);
	}
	*(L.elem+i-1) = e;
	L.length++;   // ����1
} //ListInsert_Sq

void ListDelete_Sq(struct Sqlist &L, int i, ElemType &e)
{
	//���Ա�����ҷǿգ�1<=i<=ListLength_Sq(L)
	//ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
	int j;
	e = *(L.elem+i-1);
	for(j=i; j<L.length; j++)
	{
		*(L.elem+j-1) = *(L.elem+j);
	}
	L.length--;
} //ListDelete_Sq

Status ListTraverse_Sq(struct Sqlist L, Status (*visit)(ElemType))
{
	//Ҫ�����Ա����
	//���ζ�L��ÿ��Ԫ�ص��ú���visit(), һ��visit()ʧ�ܣ������ʧ�ܣ�����FALSE,���򷵻�TRUE
	int i;
	for(i=0; i<L.length; i++)
	{
		if(!visit(*(L.elem+i)))
			return FALSE;	    
	}
	return TRUE;
} // ListTraverse_Sq

Status visit_display_Sq(ElemType e)
{
	printf("%d ", e);
	return TRUE;
} //visit_display_Sq



//�㷨


//�㷨2.1
void unionList_Sq(struct Sqlist &La, struct Sqlist Lb)
{
	//��Lb�д��ڵ�La�в����ڵ�Ԫ�ز��뵽La��
	int La_len = ListLength_Sq(La);
	int Lb_len = ListLength_Sq(Lb);
	int i;
	ElemType e;
	for(i=1; i<=Lb_len; i++)
	{
		GetElem_Sq(Lb, i, e);    // ȡ�ڲ���Ԫ�ظ���e
		if(!LocateElem_Sq(La, e, compare_equal_Sq))
		{  
			ListInsert_Sq(La, ++La_len, e);  
		}
	}
}  //unionList_Sq

//�㷨2.2
void MergeList_Sq(struct Sqlist La, struct Sqlist Lb, struct Sqlist &Lc)
{
	//��֪���Ա�La��Lb������Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ��µ����Ա�Lc,Lc������Ԫ��Ҳ��ֵ�ǵݼ�����
	int i, j, k, ai, bj;
	int La_len, Lb_len;
	ElemType e;
	InitList_Sq(Lc);
	i = j = k = 1;
	La_len = ListLength_Sq(La);
	Lb_len = ListLength_Sq(Lb);
	while(i<=La_len && j<=Lb_len)
	{
		//La, LbΪ�ǿձ�
		GetElem_Sq(La, i, ai);
		GetElem_Sq(Lb, j, bj);
		if(ai <= bj)
		{
			ListInsert_Sq(Lc, k++, ai);
			++i;
		}
		else
		{
			ListInsert_Sq(Lc, k++, bj);
			++j;
		}
	}
	while(i <= La_len)
	{
		GetElem_Sq(La, i++, ai);
		ListInsert_Sq(Lc, k++, ai);
	}
	while(j <= Lb_len)
	{
		GetElem_Sq(Lb, j++, bj);
		ListInsert_Sq(Lc, k++, bj);
	}
} //MergList

//�㷨2.3��2.4��2.5��2.6��2.7
//ǰ��ʵ����
