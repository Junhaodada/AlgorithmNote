#include <cstdio>
#include <algorithm>
using namespace std;
/*链表——动态链表*/
struct node
{
    int data;
    node *next;
};
/*创建链表*/
node *create(int Array[], int n)
{
    node *p, *pre, *head;
    head = new node;
    head->next = NULL;
    pre = head;
    for (int i = 0; i < n; i++)
    {
        p = new node;
        p->data = Array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}
/*查找元素*/
int search(node *head, int x)
{
    int count = 0;
    node *p = head->next;
    while (p != nullptr)
    {
        if (p->data == x)
            count++;
        p = p->next;
    }
    return count;
}
/*遍历链表*/
void output(node *head)
{
    node *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
/*插入元素*/
void insert(node *head, int pos, int x)
{
    node *p = head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    node *q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;
}
/*删除元素*/
void del(node *head, int x)
{
    node *p = head->next;
    node *pre = head;
    while (p != nullptr)
    {
        if (p->data == x)
        {
            pre->next = p->next;
            delete (p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}
void test()
{
    int array[] = {1, 2, 3, 4, 3};
    int n = 5;
    node *L = create(array, n);
    output(L);
    printf("%d\n", search(L, 3));
    insert(L, 3, 9);
    output(L);
    del(L, 3);
    output(L);
}
int main()
{
    test();
    return 0;
}