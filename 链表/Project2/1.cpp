#include<stdio.h>
#include<malloc.h>
constexpr auto MAX = 100;
//初始化，插入，删除，查找，清空，销毁，输出，测长度，
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;
int TnitList(LinkList &L)  //初始化 
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	return 1;
}
void EmptyList(LinkList &L)  //清空 
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
void DestroyList(LinkList &L)  //销毁
{
	LNode* p = nullptr;
	while (p)
	{
		p = L;
		L = L->next;
		free(p);
	}
}
int ListEmpty(LinkList L)      //判空 
{
	if (L->next == NULL)
		return 1;
	else return 0;
}
int ListLengh(LinkList L)      //求表长 
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
int LocateElem(LinkList L, ElemType e)  //查找 
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
void GetElem(LinkList L, int i, ElemType &e)  //取值
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
int ListInsert(LinkList& L, int i, ElemType e) //插入
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
int ListDelete(LinkList& L, int i)       //删除
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
void TraverseList(LinkList L)       //遍历
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
	printf("(1)初始化链表L\n");
	TnitList(L);
	printf("(2)依次插入元素a,b,c,d,e\n");
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("(3)输入链表L：");
	TraverseList(L);
	printf("(4)链表L的长度=%d\n", ListLengh(L));
	printf("(5)链表L为%s\n", ListEmpty(L) ? "空" : "非空");
	GetElem(L, 3, e);
	printf("(6)链表L的第三个元素=%c\n", e);
	printf("(7)元素a的位置=%d\n", LocateElem(L, 'a'));
	printf("(8)在第四个元素的位置插入f\n");
	ListInsert(L, 4, 'f');
	printf("(9)输出链表L：");
	TraverseList(L);
	printf("(10)删除L的第三个元素\n");
	ListDelete(L, 3);
	printf("(11)输出链表L");
	TraverseList(L);
	printf("(12)释放链表L\n");
	DestroyList(L);
	return 0;
}