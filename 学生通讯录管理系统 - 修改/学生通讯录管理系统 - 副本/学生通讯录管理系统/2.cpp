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
LinkList creatIncreLink();  //创建链表
void deleteElem(LinkList L, int i);  //在通讯录上按序号删除地第i个元素
int delName(LinkList L, char n[]);   //按姓名删除成员记录
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
    printf("请输入学生学号、姓名和电话号码，建立通讯录，以'-1'为输入结束标志\n");
    printf("请输入学号 %d: ", num);
    scanf_s("%d", &number);
    printf("请输入姓名 %d: ", num);
    temp = getchar();
    gets_s(name);
    printf("请输入电话号码%d: ", num);
    scanf_s("%lf", &telenum);
    while (number >= 0)
    {
        p = (LinkList)malloc(LEN);
        p->number = number;
        p->telenum = telenum;
        strcpy_s(p->name, name);
        insertYouXu(L, p);
        num++;
        printf("请输入学号 %d: ", num);
        scanf_s("%d", &number);
        printf("请输入姓名 %d: ", num);
        temp = getchar();
        gets_s(name);
        printf("请输入电话号码 %d: ", num);
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
        printf("第%d个元素删除失败\n", i);
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
        printf("该链表中没有元素，查找失败\n");
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
            printf("被删除\n");
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
        printf("该链表中没有元素，删除失败\n");
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
        printf("删除\n");
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
            printf("重复输入！\n");
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
    printf("                学号         姓名         电话号码\n");
    printf("\n             ______________\n");
    if (L==NULL || L->next==NULL)
    {
        printf("该通讯录中没有元素\n");
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
        printf("该通讯录中没有元素，查找失败\n");
    }
    else
    {
        while (p != NULL)
        {
            if (!strcmp(p->name,n))
            {
                flag = 1;
                printf("要查找的是第%d位的通讯录成员：\n", seat);
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
        printf("该链表中没有元素，查找失败\n");
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
                    printf("要查找的是第%d位的通讯录成员：\n", seat);
                    printf("学号：%d   姓名：%s   电话号码.：%.0f\n", p->number, p->name, p->telenum);
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
    printf("\n  ****************^@^欢迎使用通讯录系统****************\n");
    printf("           *         1 通讯录的建立                     *\n");
    printf("           *         2 插入通讯记录                     *\n");
    printf("           *         3 查询通讯记录                     *\n");
    printf("           *         4 删除通讯记录                     *\n");
    printf("           *         5 显示通讯录信息                     *\n");
    printf("           *         0 退出管理系统                     *\n");
    printf("\n  ****************^@^欢迎使用通讯录系统****************\n");
    printf("请选择0-5：");
    scanf_s("%d", &menu);
    while (menu != 0)
    {
        switch (menu)
        {
        case 1:
            L = creatIncreLink();
            printf("建立通讯录：");
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
                printf("请输入通讯录成员的学号和姓名：\n");
                printf("请输入学号：");
                scanf_s("%d", &number);
                printf("请输入姓名：");
                temp = getchar();
                gets_s(name);
                printf("请输入电话号码：");
                scanf_s("%lf", &telenum);
                LinkList p = (LinkList)malloc(LEN);
                p->number = number;
                p->telenum = telenum;
                strcpy_s(p->name, name);
                insertYouXu(L, p);
                printf("插入后：");
                printList(L);
            }
            else
            {
                printf("\nERROR:通讯录还没有建立，请先建立通讯录\n");
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
                    printf("选择查找方式：\n");
                    printf("           1.按学号   2.按姓名");
                    scanf_s("%d", &way);
                    if (way == 1)
                    {
                        printf("\n请输入学号：");
                        scanf_s("%d", &n);
                        s = searchNum(L, n);
                        if (s == 0)
                        {
                            printf("无此通讯录成员，查找失败！\n");
                        }

                    }
                    else if (way == 2)
                    {
                        printf("\n请输入姓名：");
                        temp = getchar();
                        gets_s(na);
                        s = searchName(L, na);
                        if (s == 0)
                        {
                            printf("无此通讯录成员，查找失败!\n");
                        }
                    }
                    else
                    {
                        printf("通讯录中无记录！\n");
                    }
                }
                break;
            }
            else
            {
                printf("通讯录中无记录！\n");
            }
            break;
        }

        case 4:
            //int way = 0;
            //char temp = 0;
        {
            printf("选择删除方式：1.按序号 2.按学号 3.按姓名\n");
            scanf_s("%d", &way);
            if (way == 1)
            {
                int n;
                printf("请输入通讯录序号：");
                scanf_s("%d", &n);
                printf("删除后：\n");
                deleteElem(L, n);
                printList(L);
            }
            else if (way == 2)
            {
                int n, f;
                printf("请输入学号：");
                scanf_s("%d", &n);
                f = delNum(L, n);
                if (f != 0)
                {
                    printf("删除后：\n");
                    printList(L);
                }
                else
                {
                    printf("无此学号，删除失败！\n");
                }
            }
            else if (way == 3)
            {
                char na[20] = { 0 };
                char temp;
                int f;
                printf("\n请输入姓名：");
                temp = getchar();
                gets_s(na);
                f = delName(L, na);
                if (f != 0)
                {
                    printf("删除后：\n");
                    printList(L);
                }
                else
                {
                    printf("无该学号，删除失败！\n");
                }
            }
            else
            {
                printf("ERROR!!\n");
            }
            break;
        }

        case 5:
            printf("当前通讯录内容如下：\n");
            printList(L);
            break;
        case 0:
            exit(0);
        default:
            printf("\n无此功能，重新输入\n");
        }
        printf("选择功能：");
        scanf_s("%d", &menu);
    }
}
