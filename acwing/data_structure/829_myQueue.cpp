#include <iostream>
#include <vector>

/*
实现一个队列，队列初始为空，支持四种操作：

push x – 向队尾插入一个数 x；
pop – 从队头弹出一个数；
empty – 判断队列是否为空；
query – 查询队头元素。
现在要对队列进行 M 个操作，其中的每个操作 3 和操作 4 都要输出相应的结果。

输入格式
第一行包含整数 M，表示操作次数。

接下来 M 行，每行包含一个操作命令，操作命令为 push x，pop，empty，query 中的一种。

输出格式
对于每个 empty 和 query 操作都要输出一个查询结果，每个结果占一行。

其中，empty 操作的查询结果为 YES 或 NO，query 操作的查询结果为一个整数，表示队头元素的值。

数据范围
1≤M≤100000,
1≤x≤109,
所有操作保证合法。

输入样例：
10
push 6
empty
query
pop
empty
push 3
push 4
pop
query
push 6
输出样例：
NO
6
YES
4
*/

struct MyQueue
{
    std::vector<int> st;

    bool empty()
    {
        return st.empty();
    }

    void push(int x)
    {
        st.push_back(x);
    }

    int pop()
    {
        if (empty())
            return -1;
        int t = st.front();
        st.erase(st.begin());
        return t;
    }

    int front()
    {
        if (empty())
            return -1;
        return st.front();
    }
};

int main(int argc, char *argv[])
{
    int m;
    std::cin >> m;
    MyQueue st;
    while (m--)
    {
        std::string type;
        std::cin >> type;
        if (type == "push")
        {
            int val;
            std::cin >> val;
            st.push(val);
        }
        else if (type == "empty")
        {
            if (st.empty())
            {
                std::cout << "YES" << std::endl;
            }
            else
            {
                std::cout << "NO" << std::endl;
            }
        }
        else if (type == "pop")
        {
            st.pop();
        }
        else if (type == "query")
        {
            std::cout << st.front() << std::endl;
        }
    }
    return 0;
}