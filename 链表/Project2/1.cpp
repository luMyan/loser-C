#include<stdio.h>
#include<malloc.h>
constexpr auto MAX = 100;
//��ʼ�������룬ɾ�������ң���գ����٣�������ⳤ�ȣ�
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;
int TnitList(LinkList &L)  //��ʼ�� 
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	return 1;
}
void EmptyList(LinkList &L)  //��� 
{
	LNode* p, * q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}
void DestroyList(LinkList &L)  //����
{
	LNode* p = nullptr;
	while (p)
	{
		p = L;
		L = L->next;
		free(p);
	}
}
int ListEmpty(LinkList L)      //�п� 
{
	if (L->next == NULL)
		return 1;
	else return 0;
}
int ListLengh(LinkList L)      //��� 
{
	int j = 0;
	LNode* p;
	p = L->next;
	while (p)
	{
		j++;
		p = p->next;
	}
	return j;
}
int LocateElem(LinkList L, ElemType e)  //���� 
{
	LNode* p;
	int j = 1;
	p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
		j++;
	}
	if (p)
	{
		return j;
	}
	return 0;
}
void GetElem(LinkList L, int i, ElemType &e)  //ȡֵ
{
	LNode* p;
	p = L->next;
	int j = 1;
	
	while (p && j<i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		return;
	}
	e = p->data;
}
int ListInsert(LinkList& L, int i, ElemType e) //����
{
	LNode* p, * s;
	p = L;
	int j = 0;
	while (p && j<i-1)
	{
		p = p->next;
		j++;
	}
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}
int ListDelete(LinkList& L, int i)       //ɾ��
{
	LNode* p, * q;
	p = L;
	int j = 0;
	if (!p || j>i-1)
	{
		return 0;
	}
	while (p && j<i-1)
	{
		p = p->next;
		j++;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}
void TraverseList(LinkList L)       //����
{
	LNode* p;
	p = L->next;
	if (ListEmpty(L))
	{
		return;
	}
	while (p)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	LinkList L;
	ElemType e;
	printf("(1)��ʼ������L\n");
	TnitList(L);
	printf("(2)���β���Ԫ��a,b,c,d,e\n");
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("(3)��������L��");
	TraverseList(L);
	printf("(4)����L�ĳ���=%d\n", ListLengh(L));
	printf("(5)����LΪ%s\n", ListEmpty(L) ? "��" : "�ǿ�");
	GetElem(L, 3, e);
	printf("(6)����L�ĵ�����Ԫ��=%c\n", e);
	printf("(7)Ԫ��a��λ��=%d\n", LocateElem(L, 'a'));
	printf("(8)�ڵ��ĸ�Ԫ�ص�λ�ò���f\n");
	ListInsert(L, 4, 'f');
	printf("(9)�������L��");
	TraverseList(L);
	printf("(10)ɾ��L�ĵ�����Ԫ��\n");
	ListDelete(L, 3);
	printf("(11)�������L");
	TraverseList(L);
	printf("(12)�ͷ�����L\n");
	DestroyList(L);
	return 0;
}