#include <cstdio>
#include <algorithm>
using namespace std;
/*简单选择排序*/
void selectSort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (A[k] > A[j])
            {
                k = j;
            }
        }
        if (i != k)
        {
            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
        }
    }
}

void test(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (A[k] > A[j])
            {
                k = j;
            }
        }
        if (k != i)
        {
            int temp = A[k];
            A[k] = A[i];
            A[i] = temp;
        }
    }
}
int main()
{
    int A[6] = {3, 4, 2, 6, 1, 0};
    test(A, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}