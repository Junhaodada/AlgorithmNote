#include <cstdio>
#include <algorithm>
using namespace std;
/*直接插入排序*/
void insertSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = A[i], j = i;
        while (j > 0 && temp < A[j - 1])
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
}

void test(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = A[i], j = i;
        while (j > 0 && temp < A[j - 1])
        {
            A[j] = A[j - 1];
        }
        A[j] = temp;
    }
}

int main()
{
    int A[6] = {3, 4, 2, 6, 1, 0};
    insertSort(A, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}