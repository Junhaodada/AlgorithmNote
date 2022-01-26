#include <cstdio>
#include <algorithm>
using namespace std;
/*二分查找时间复杂度O(logn)*/
int binarySearch(int A[], int left, int right, int x)
{
    int mid;
    while (left <= right)
    {
        // mid = (left + right) / 2;
        mid = left + (right - left) / 2;
        if (A[mid] == x)
            return mid;
        else if (A[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main()
{
    const int n = 5;
    int A[n] = {1, 3, 5, 7, 8};
    printf("%d\n", binarySearch(A, 0, 5, 3));     //1
    printf("%d\n", lower_bound(A, A + 5, 5) - A); //2
    printf("%d\n", binary_search(A, A + 5, -1));  //1 查找成功返回1
    return 0;
}