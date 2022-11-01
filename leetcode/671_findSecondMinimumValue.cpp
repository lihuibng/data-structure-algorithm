#include <iostream>
using namespace std;

/*
671. 二叉树中第二小的节点
给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。

更正式地说，即 root.val = min(root.left.val, root.right.val) 总成立。

给出这样的一个二叉树，你需要输出所有节点中的 第二小的值 。

如果第二小的值不存在的话，输出 -1 。



示例 1：


输入：root = [2,2,5,null,null,5,7]
输出：5
解释：最小的值是 2 ，第二小的值是 5 。
示例 2：


输入：root = [2,2,2]
输出：-1
解释：最小的值是 2, 但是不存在第二小的值。


提示：

树中节点数目在范围 [1, 25] 内
1 <= Node.val <= 231 - 1
对于树中每个节点 root.val == min(root.left.val, root.right.val)
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
    int minValue;
    int ans = -1;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (ans != -1 && root->val >= ans)
        {
            return;
        }
        if (root->val > minValue)
        {
            ans = root->val;
        }
        dfs(root->left);
        dfs(root->right);
        return;
    }
    int findSecondMinimumValue(TreeNode *root)
    {
        minValue = root->val;
        dfs(root);
        return ans;
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
    s.printTree(t2);
    auto res = s.findSecondMinimumValue(t2);
    cout << res;
    cout << endl;

    return 0;
}