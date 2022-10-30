#include <iostream>
#include <stack>
#include <unordered_map>

/*
给定一个表达式，其中运算符仅包含 +,-,*,/（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。

注意：

数据保证给定的表达式合法。
题目保证符号 - 只作为减号出现，不会作为负号出现，例如，-1+2,(2+2)*(-(1+1)+2) 之类表达式均不会出现。
题目保证表达式中所有数字均为正整数。
题目保证表达式在中间计算过程以及结果中，均不超过 231−1。
题目中的整除是指向 0 取整，也就是说对于大于 0 的结果向下取整，例如 5/3=1，对于小于 0 的结果向上取整，例如 5/(1−4)=−1。
C++和Java中的整除默认是向零取整；Python中的整除//默认向下取整，因此Python的eval()函数中的整除也是向下取整，在本题中不能直接使用。
输入格式
共一行，为给定表达式。

输出格式
共一行，为表达式的结果。

数据范围
表达式的长度不超过 105。

输入样例：
(2+2)*(1+1)
输出样例：
8
*/

void eval(std::stack<int> &st, std::stack<char> &op)
{
    int b = st.top();
    st.pop();

    int a = st.top();
    st.pop();

    char c = op.top();
    op.pop();

    int r = 0;
    if (c == '+')
        r = a + b;
    else if (c == '-')
        r = a - b;
    else if (c == '*')
        r = a * b;
    else if (c == '/')
        r = a / b;

    st.push(r);
}

int calcExpression(const std::string &s)
{
    std::stack<int> st;
    std::stack<char> op;
    std::unordered_map<char, int> mp{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    int i = 0;
    while (i < s.length())
    {
        if (std::isdigit(s[i]))
        {
            std::string res;
            while (i < s.length() && std::isdigit(s[i]))
                res += s[i++];
            st.push(std::stoi(res));
            i--;
        }
        else if (s[i] == '(')
        {
            op.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (op.top() != '(')
            {
                eval(st, op);
            }
            op.pop();
        }
        else if (mp.count(s[i]))
        {
            while (!op.empty() && mp[op.top()] >= mp[s[i]])
            {
                eval(st, op);
            }
            op.push(s[i]);
        }
        i++;
    }
    while (op.size())
        eval(st, op);
    return st.top();
}

int main(int argc, char *argv[])
{
    std::string str;
    std::cin >> str;
    std::cout << calcExpression(str) << std::endl;
    return 0;
}