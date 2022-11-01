#include <iostream>
using namespace std;

/*
114. 二叉树展开为链表
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。


示例 1：


输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [0]
输出：[0]


提示：

树中结点数在范围 [0, 2000] 内
-100 <= Node.val <= 100


进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val(0),
          left(nullptr),
          right(nullptr)
    {
    }

    TreeNode(int x)
        : val(x),
          left(nullptr),
          right(nullptr)
    {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x),
          left(left),
          right(right)
    {
    }
};

class Solution
{
public:
    TreeNode *flat(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        TreeNode *left = flat(root->left);
        TreeNode *right = flat(root->right);
        if (left)
        {
            root->right = left;
            TreeNode *p = left;
            while (p)
            {
                if (p->right == nullptr)
                    break;
                p = p->right;
            }
            p->right = right;
        }
        root->left = nullptr;
        return root;
    }

    void flatten(TreeNode *root)
    {
        flat(root);
    }

    void printTree(TreeNode *root)
    {
        if (root == nullptr)
            return;
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    TreeNode *t2 = new TreeNode(1);
    t2->right = new TreeNode(2);
    s.flatten(t2);
    s.printTree(t2);
    cout << endl;

    return 0;
}