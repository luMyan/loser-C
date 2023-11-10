//#include "2.h"
//#include"1.cpp"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(LNode)
int seat;
typedef struct LNode
{
    int number;
    char name[20];
    double telenum;
    struct LNode* next;
}LNode, * LinkList;
LinkList creatIncreLink();  //��������
void deleteElem(LinkList L, int i);  //��ͨѶ¼�ϰ����ɾ���ص�i��Ԫ��
int delName(LinkList L, char n[]);   //������ɾ����Ա��¼
int delNum(LinkList L, int n);
void insertYouXu(LinkList L, LinkList Elem);
void printList(LinkList L);
LinkList prior(LinkList L, LinkList p);
int searchName(LinkList L, char n[]);
int searchNum(LinkList L, int n);
LinkList creatIncreLink()
{
    LinkList p;
    int num = 1;
    int number;
    double telenum;
    char name[20] = { 0 };
    char temp;
    LinkList L, P = nullptr;
    L = (LinkList)malloc(LEN);
    L->next = NULL;
    printf("������ѧ��ѧ�š������͵绰���룬����ͨѶ¼����'-1'Ϊ���������־\n");
    printf("������ѧ�� %d: ", num);
    scanf_s("%d", &number);
    printf("���������� %d: ", num);
    temp = getchar();
    gets_s(name);
    printf("������绰����%d: ", num);
    scanf_s("%lf", &telenum);
    while (number >= 0)
    {
        p = (LinkList)malloc(LEN);
        p->number = number;
        p->telenum = telenum;
        strcpy_s(p->name, name);
        insertYouXu(L, p);
        num++;
        printf("������ѧ�� %d: ", num);
        scanf_s("%d", &number);
        printf("���������� %d: ", num);
        temp = getchar();
        gets_s(name);
        printf("������绰���� %d: ", num);
        scanf_s("%lf", &telenum);
    }
    return(L);
}

void deleteElem(LinkList L, int i)
{
    LinkList p = L, q;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next))
    {
        printf("��%d��Ԫ��ɾ��ʧ��\n", i);
        return;
    }
    q = p->next;
    p->next = q->next;
    free(q);
}

int delName(LinkList L, char n[])
{
    int flag = 0;
    LinkList p = L->next;
    seat = 1;
    if (L->next == NULL)
        printf("��������û��Ԫ�أ�����ʧ��\n");
    else
    {
        while (p != NULL)
        {
            if (!strcmp(p->name, n))
            {
                flag = 1;
                printf("%s ", p->name);
                p = p->next;
                deleteElem(L, seat);
            }
            else { p = p->next; seat++; }
        }
        if (flag)
        {
            printf("��ɾ��\n");
        }
    }
    return flag;
}

int delNum(LinkList L, int n)
{
    int flag = 0;
    LinkList p = L->next;
    seat = 1;
    if (L->next==NULL)
    {
        printf("��������û��Ԫ�أ�ɾ��ʧ��\n");
    }
    else
    {
        while (p!=NULL)
        {
            if (p->number <= n)
            {
                if (p->number == n)
                {
                    flag = 1;
                    printf("%d ", p->number);
                    p = p->next;
                    deleteElem(L, seat);
                }
            }
            else
            {
                p = p->next;
                seat++;
            }
        }
        printf("ɾ��\n");
    }
    return flag;
}

void insertYouXu(LinkList L, LinkList Elem)
{
    LinkList p = L->next;
    while (p!=NULL && Elem->number >= p->number)
    {
        if (p->number==Elem->number)
        {
            printf("�ظ����룡\n");
            return;
        }
        p = p->next;
    }
    if (p==NULL)
    {
        p = prior(L, p);
        Elem->next = NULL;
        p->next = Elem;
    }
    else
    {
        p = prior(L, p);
        Elem->next = p->next;
        p->next = Elem;
    }
}

void printList(LinkList L)
{
    LinkList p = L;
    int n = 1;
    printf("\n             ______________\n");
    printf("                ѧ��         ����         �绰����\n");
    printf("\n             ______________\n");
    if (L==NULL || L->next==NULL)
    {
        printf("��ͨѶ¼��û��Ԫ��\n");
    }
    else
    {
        while (p->next != NULL)
        {
            printf("       %2d    %-9d", n, p->next->number);
            printf("       %-5s   %.0f\n", p->next->name, p->next->telenum);
            p = p->next;
            n++;
        }
        printf("\n             ______________\n");
    }
    return;
}

LinkList prior(LinkList L, LinkList p)
{
    LinkList p_prior = L;
    if (L->next == NULL)
    {
        return(L);
    }
    while (p_prior->next != p)
    {
        p_prior = p_prior->next;
    }
    return (p_prior);
}

int searchName(LinkList L, char n[])
{
    int flag = 0;
    LinkList p = L->next;
    seat = 1;
    if (L->next ==NULL || L == NULL)
    {
        printf("��ͨѶ¼��û��Ԫ�أ�����ʧ��\n");
    }
    else
    {
        while (p != NULL)
        {
            if (!strcmp(p->name,n))
            {
                flag = 1;
                printf("Ҫ���ҵ��ǵ�%dλ��ͨѶ¼��Ա��\n", seat);
                printf("Number:%d   Name:%s    TeleNo.:%.0f\n", p->number, p->name, p->telenum);
            }
            p = p->next;
            seat++;
        }
    }
    return flag;
}

int searchNum(LinkList L, int n)
{
    int flag = 0;
    LinkList p = L->next;
    seat = 1;
    if (L->next==NULL)
    {
        printf("��������û��Ԫ�أ�����ʧ��\n");
    }
    else
    {
        while (p!=NULL)
        {
            if (p->number<=n)
            {
                if (p->number==n)
                {
                    flag = 1;
                    printf("Ҫ���ҵ��ǵ�%dλ��ͨѶ¼��Ա��\n", seat);
                    printf("ѧ�ţ�%d   ������%s   �绰����.��%.0f\n", p->number, p->name, p->telenum);
                }
            }
            p = p->next;
            seat++;
        }
    }
    return flag;
}

int main()
{
    LinkList L = NULL;
    int flag = 0;
    int menu = 0;
    char temp = 0;
    int way = 0;
    system("color 1f");
    printf("\n  ****************^@^��ӭʹ��ͨѶ¼ϵͳ****************\n");
    printf("           *         1 ͨѶ¼�Ľ���                     *\n");
    printf("           *         2 ����ͨѶ��¼                     *\n");
    printf("           *         3 ��ѯͨѶ��¼                     *\n");
    printf("           *         4 ɾ��ͨѶ��¼                     *\n");
    printf("           *         5 ��ʾͨѶ¼��Ϣ                     *\n");
    printf("           *         0 �˳�����ϵͳ                     *\n");
    printf("\n  ****************^@^��ӭʹ��ͨѶ¼ϵͳ****************\n");
    printf("��ѡ��0-5��");
    scanf_s("%d", &menu);
    while (menu != 0)
    {
        switch (menu)
        {
        case 1:
            L = creatIncreLink();
            printf("����ͨѶ¼��");
            printList(L);
            flag = 1;
            break;
        case 2:
        {
            if (flag == 1)
            {
                int number = 0;
                //int	telenum = 0;
                double telenum;
                char name[20]{};
                char temp;
                printf("������ͨѶ¼��Ա��ѧ�ź�������\n");
                printf("������ѧ�ţ�");
                scanf_s("%d", &number);
                printf("������������");
                temp = getchar();
                gets_s(name);
                printf("������绰���룺");
                scanf_s("%lf", &telenum);
                LinkList p = (LinkList)malloc(LEN);
                p->number = number;
                p->telenum = telenum;
                strcpy_s(p->name, name);
                insertYouXu(L, p);
                printf("�����");
                printList(L);
            }
            else
            {
                printf("\nERROR:ͨѶ¼��û�н��������Ƚ���ͨѶ¼\n");
            }
            break;
        }

        case 3:
            //int way = 0;
        {
            int n = 0;
            int s = 0;
            char na[20]{};
            char temp;
            if (L != NULL)
            {
                if (flag)
                {
                    printf("ѡ����ҷ�ʽ��\n");
                    printf("           1.��ѧ��   2.������");
                    scanf_s("%d", &way);
                    if (way == 1)
                    {
                        printf("\n������ѧ�ţ�");
                        scanf_s("%d", &n);
                        s = searchNum(L, n);
                        if (s == 0)
                        {
                            printf("�޴�ͨѶ¼��Ա������ʧ�ܣ�\n");
                        }

                    }
                    else if (way == 2)
                    {
                        printf("\n������������");
                        temp = getchar();
                        gets_s(na);
                        s = searchName(L, na);
                        if (s == 0)
                        {
                            printf("�޴�ͨѶ¼��Ա������ʧ��!\n");
                        }
                    }
                    else
                    {
                        printf("ͨѶ¼���޼�¼��\n");
                    }
                }
                break;
            }
            else
            {
                printf("ͨѶ¼���޼�¼��\n");
            }
            break;
        }

        case 4:
            //int way = 0;
            //char temp = 0;
        {
            printf("ѡ��ɾ����ʽ��1.����� 2.��ѧ�� 3.������\n");
            scanf_s("%d", &way);
            if (way == 1)
            {
                int n;
                printf("������ͨѶ¼��ţ�");
                scanf_s("%d", &n);
                printf("ɾ����\n");
                deleteElem(L, n);
                printList(L);
            }
            else if (way == 2)
            {
                int n, f;
                printf("������ѧ�ţ�");
                scanf_s("%d", &n);
                f = delNum(L, n);
                if (f != 0)
                {
                    printf("ɾ����\n");
                    printList(L);
                }
                else
                {
                    printf("�޴�ѧ�ţ�ɾ��ʧ�ܣ�\n");
                }
            }
            else if (way == 3)
            {
                char na[20] = { 0 };
                char temp;
                int f;
                printf("\n������������");
                temp = getchar();
                gets_s(na);
                f = delName(L, na);
                if (f != 0)
                {
                    printf("ɾ����\n");
                    printList(L);
                }
                else
                {
                    printf("�޸�ѧ�ţ�ɾ��ʧ�ܣ�\n");
                }
            }
            else
            {
                printf("ERROR!!\n");
            }
            break;
        }

        case 5:
            printf("��ǰͨѶ¼�������£�\n");
            printList(L);
            break;
        case 0:
            exit(0);
        default:
            printf("\n�޴˹��ܣ���������\n");
        }
        printf("ѡ���ܣ�");
        scanf_s("%d", &menu);
    }
}
