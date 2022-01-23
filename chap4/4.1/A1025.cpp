//1025PAT Ranking
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct student //学生结构体
{
    char id[15]; //准考证号
    int score;
    int loc_number; //考场号
    int loc_rank;
} stu[30005];
/*
//The output must be sorted in nondecreasing order of the final ranks. 
The testees with the same score must have the same rank, and the output 
must be sorted in nondecreasing order of their registration numbers.
*/
bool cmp(student x, student y) //排序规则
{
    if (x.score != y.score)
        return x.score > y.score;
    else
        return strcmp(x.id, y.id) < 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    int loc_sum = n;
    int count = 0;
    while (n--)
    {
        int k; //各个考场人数
        scanf("%d", &k);
        //	int count=0;//总数
        for (int i = 0; i < k; i++) //输入学生信息
        {
            scanf("%s %d", stu[count].id, &stu[count].score);
            stu[count].loc_number = (loc_sum - n); //赋值考场号
            count++;
        }
        sort(stu + count - k, stu + count, cmp);
        stu[count - k].loc_rank = 1;                //初始化各个考场排名
        for (int j = count - k + 1; j < count; j++) //赋予排名
        {
            if (stu[j].score == stu[j - 1].score)      //如果与前一位考生同分
                stu[j].loc_rank = stu[j - 1].loc_rank; //排名也相同
            else                                       //不同分，排名为该考生前的人数
                stu[j].loc_rank = j + 1 - (count - k);
        }
    }
    //输出要求
    /*
For each test case, first print in one line the total number of testees. 
Then print the final ranklist in the following format:
registration_number final_rank location_number local_rank	
*/
    printf("%d\n", count);       //输出所有考生人数total number
    sort(stu, stu + count, cmp); //所有考生排序
    int r = 1;                   //当前考生排名
    for (int i = 0; i < count; i++)
    {
        if (i > 0 && stu[i].score != stu[i - 1].score)
            r = i + 1;
        printf("%s ", stu[i].id); //registration_number
        //location_number local_rank
        printf("%d %d %d\n", r, stu[i].loc_number, stu[i].loc_rank);
    }
    return 0;
}