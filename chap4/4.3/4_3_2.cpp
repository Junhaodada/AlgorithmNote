#include <cstdio>
#include <cmath>

/*递归*/
/**
 * 递归流程：确定递归式和递归边界
 * 全排列
 * 八皇后
*/
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};
/*全排列*/
/**
 * P[1]-P[index-1]已经填入元素，需要向P[index]填入一个元素，
 * 填入后再次递归index+1后的组合，恢复哈希表，直至index+1=n打印排列，结束
*/
void generateP(int index)
{
    if (index == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }
}
// 123
// 132
// 213
// 231
// 312
// 321
void test1()
{
    n = 3;
    generateP(1);
}

/*n皇后问题*/
int count = 0;
void generateP2(int index)
{
    if (index == n + 1)
    {
        count++;
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            bool flag = true;
            for (int pre = 1; pre < index; pre++)
            {
                if (abs(index - pre) == abs(x - P[pre]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                P[index] = x;
                hashTable[x] = true;
                generateP2(index + 1);
                hashTable[x] = false;
            }
        }
    }
}
//92
void test2()
{
    n = 8;
    generateP2(1);
    printf("%d\n", count);
}

int main()
{
    test2();
    return 0;
}
void prac1(int index)
{
    if (index == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            P[index] = x;
            hashTable[x] = true;
            prac1(index + 1);
            hashTable[x] = false;
        }
    }
}