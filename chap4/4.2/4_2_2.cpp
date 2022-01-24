#include <cstdio>
#include <algorithm>
using namespace std;
/*字符串哈希初步*/
/**
 * 将大写字母A-Z与0-26对应，一个完全由大写字母构成的字符串，可以映射成一个26进制数字
 * a-z可以与27-52对应，映射规则变为52进制
 */
// 5 2
// ABC SSA GF CC RE
// CC SD
// 1
// 0
const int maxn = 100;
char S[maxn][5], temp[5];
int hashTable[26 * 26 * 26 + 10];
int hashFunc(char S[], int len)
{
    int id = 0;
    for (int i = 0; i < len; i++)
    {
        //只考虑大写字母
        id = id * 26 + (S[i] - 'A');

        // 考虑所有字母
        // if (S[i] >= 'A' && S[i] <= 'Z')
        // {
        //     id = id * 52 + (S[i] - 'A');
        // }
        // else if (S[i] >= 'a' && S[i] <= 'z')
        // {
        //     id = id * 52 + (S[i] - 'a') + 26;
        // }
    }
    return id;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", S[i]);
        int id = hashFunc(S[i], 3);
        hashTable[id]++;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%s", temp);
        int id = hashFunc(temp, 3);
        printf("%d\n", hashTable[id]); //字符串出现次数
    }

    return 0;
}