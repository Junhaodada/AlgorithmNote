#include <cstdio>
using namespace std;
const int maxn = 100010;
// 5 3
// 8 3 7 6 2
// 7 4 2
// YES
// NO
// YES
void test1()
{
    bool hashTable[maxn] = {false};
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        hashTable[x] = true;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        if (hashTable[x] == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
// 5 3
// 8 3 7 6 2
// 7 4 2
void test2()
{
    int hashTable[maxn] = {0};
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        hashTable[x]++;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        printf("%d: %d\n", x, hashTable[x]);
    }
}
int main()
{
    test2();
    return 0;
}