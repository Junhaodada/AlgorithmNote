#include <cstdio>
#include <algorithm>
using namespace std;
/*静态链表*/
struct Node
{
    int data;
    int next;   
} node[100];

void demo()
{
    node[1].data = 12;
    node[1].next = 3;
    node[3].data = 13;
    node[1].next = 2;
}
/*练习*/

int main()
{
    return 0;
}