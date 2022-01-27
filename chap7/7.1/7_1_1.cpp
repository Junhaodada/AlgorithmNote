#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
/*栈*/
/*简单计算器*/
struct node
{
    double num;
    char op;
    bool flag;
};
string str;
stack<node> s;
queue<node> q;
map<char, int> op;

void Change()
{
}
double Cal()
{
}

int main()
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str != "0")
    {
        for (string::iterator it = str.end(); it != str.begin(); it--)
        {
            if (*it == ' ')
                str.erase(it);
        }
        while (!s.empty())
            s.pop();
        Change();
        printf("%.2f\n", Cal());
    }

    return 0;
}