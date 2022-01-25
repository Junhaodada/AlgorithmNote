#include <cstdio>
#include <algorithm>
using namespace std;

/*简单贪心*/
/** PAT B1020  
 * 已知月饼种类数、需求量、总售价，给出最佳销售方案
 * 
*/
struct mooncake
{
    double store;
    double sell;
    double price;
} cake[1010];
bool cmp(mooncake a, mooncake b)
{
    return a.price > b.price;
}
// 3 20
// 18 15 10
// 75 72 45
// 94.50
void test1()
{
    int n;
    double D;
    scanf("%d%lf", &n, &D);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &cake[i].store);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }
    sort(cake, cake + n, cmp); //按单价从高到低排序
    double ans = 0;            //收益
    for (int i = 0; i < n; i++)
    {
        if (cake[i].store <= D)
        {
            D -= cake[i].store;
            ans += cake[i].sell;
        }
        else
        {
            ans += cake[i].price * D;
            break;
        }
    }
    printf("%.2f\n", ans);
}
int main()
{
    test1();
    return 0;
}