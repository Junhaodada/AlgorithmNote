#include <cstdio>
#include <algorithm>
using namespace std;
/*DFS*/
const int maxn = 30;
int n, V, maxValue = 0;
int w[maxn], c[maxn];
void DFS(int index, int sumW, int sumC)
{
    if (index == n)
    {
        if (index == n)
        {
            if (sumW <= V && sumC > maxValue)
            {
                maxValue = sumC;
            }
            return;
        }
    }
    DFS(index + 1, sumW, sumC);
    DFS(index + 1, sumW + w[index], sumC + c[index]);
}
/*优化*/
void DFS1(int index, int sumW, int sumC)
{
    if (index == n)
        return;
    DFS1(index + 1, sumW, sumC);
    if (sumW + w[index] <= V)
    {
        if (sumC + c[index] > maxValue)
        {
            maxValue = sumC + c[index];
        }
        DFS1(index + 1, sumW + w[index], sumC + c[index]);
    }
}
/*
5 8
3 5 1 2 2
4 5 2 1 3  
10
*/
int main()
{
    scanf("%d%d", &n, &V);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }
    DFS1(0, 0, 0);
    printf("%d\n", maxValue);

    return 0;
}