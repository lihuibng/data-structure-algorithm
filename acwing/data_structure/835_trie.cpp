#include <iostream>
#include <vector>

/*
维护一个字符串集合，支持两种操作：

I x 向集合中插入一个字符串 x；
Q x 询问一个字符串在集合中出现了多少次。
共有 N 个操作，输入的字符串总长度不超过 105，字符串仅包含小写英文字母。

输入格式
第一行包含整数 N，表示操作数。

接下来 N 行，每行包含一个操作指令，指令为 I x 或 Q x 中的一种。

输出格式
对于每个询问指令 Q x，都要输出一个整数作为结果，表示 x 在集合中出现的次数。

每个结果占一行。

数据范围
1≤N≤2∗104
输入样例：
5
I abc
Q abc
Q ab
I ab
Q ab
输出样例：
1
0
1
*/


struct Node
{
    bool is_word;
    int cnt;
    std::vector<Node *> nodes;
    Node()
        : is_word(false), cnt(0), nodes(26, nullptr)
    {
    }
};

struct Trie
{
    Node *root;
    Trie()
        : root(new Node())
    {
    }

    void insert(const std::string &word)
    {
        Node *p = root;
        for (int i = 0; i < word.size(); i++)
        {
            int x = word[i] - 'a';
            if (p->nodes[x] == nullptr)
                p->nodes[x] = new Node();
            p = p->nodes[x];
        }
        p->is_word = true;
        p->cnt++;
    }

    int wordcnt(const std::string &word)
    {
        Node *p = root;
        for (int i = 0; i < word.size(); i++)
        {
            int x = word[i] - 'a';
            if (p->nodes[x] == nullptr)
                return 0;
            p = p->nodes[x];
        }
        if (p->is_word)
        {
            return p->cnt;
        }
        return 0;
    }
};

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a;
    std::string stra;
    Trie trie;
    while (a--)
    {
        std::cin >> stra;
        if (stra == "I")
        {
            std::string strb;
            std::cin >> strb;
            trie.insert(strb);
        }
        else if (stra == "Q")
        {
            std::string strb;
            std::cin >> strb;
            std::cout << trie.wordcnt(strb) << std::endl;
        }
    }

    return 0;
}