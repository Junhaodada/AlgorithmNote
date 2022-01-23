#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*sort函数和lower_bound函数*/
/*对基本数据类型排序*/
bool cmp(int a, int b)
{
    return a > b; //降序
}
void test1()
{

    int a[6] = {9, 4, 2, 5, 6, -1};
    sort(a, a + 4);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    sort(a, a + 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
}
void test2()
{
    int a[6] = {9, 4, 2, 5, 6, -1};
    sort(a, a + 6, cmp);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
}
/*对结构体数组排序*/
struct node
{
    int x, y;
} ssd[10];
bool cmp2(node a, node b)
{
    return a.x > b.x; //按x排序
}
bool cmp3(node a, node b)
{
    //先按x降序排序，若x相等，按y升序排序
    if (a.x != b.x)
        return a.x > b.x;
    else
        return a.y < b.y;
}
void test3()
{
    ssd[0].x = 2;
    ssd[1].x = 1;
    ssd[2].x = 1;
    ssd[3].x = 5;
    sort(ssd, ssd + 4, cmp2);
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", ssd[i].x);
    } //7521
    printf("\n");
    ssd[0].y = 2;
    ssd[1].y = 1;
    ssd[2].y = 7;
    ssd[3].y = 5;

    sort(ssd, ssd + 4, cmp3);
    // 5 2
    // 2 1
    // 1 5
    // 1 7
    for (int i = 0; i < 4; i++)
    {
        printf("%d %d\n", ssd[i].x, ssd[i].y);
    }
}
/* 对容器排序 支持 vector string deque*/
void test4()
{
    string str[3] = {"fd", "ghf", "hfg"};
    sort(str, str + 3);
    // fd ghf hfg
    for (int i = 0; i < 3; i++)
    {
        printf("%s ", str[i].c_str());
    }
}
void test5()
{
    vector<int> v;
    v.emplace_back(2);
    v.emplace_back(4);
    v.emplace_back(6);
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", v[i]);
    }
}

// lower_bound upper_bound
/**
 * lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
 * upper_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。在从大到小的排序数组中，重载lower_bound()和upper_bound()
 * lower_bound( begin,end,num,greater<type>() ):从数组的begin位置到end-1位置二分查找第一个小于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
 * upper_bound( begin,end,num,greater<type>() ):从数组的begin位置到end-1位置二分查找第一个小于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
*/
void test6()
{
    int a[6] = {1, 2, 2, 3, 5, 5};
    int *lowerPos = lower_bound(a, a + 6, 5, greater<int>());
    int *upperPos = upper_bound(a, a + 6, 2);
    printf("%d\n", lowerPos - a); //下标6
    printf("%d\n", upperPos - a); //下标3
}

int main()
{
    test6();
    return 0;
}