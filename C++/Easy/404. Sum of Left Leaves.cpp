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
class Solution {
public:

    bool isLeaf(TreeNode* node)
    {
        if(node == nullptr)
            return false;

        if(node->left == nullptr && node->right == nullptr)
            return true;

        return false;
    }

    int sumOfLeftLeaves(TreeNode* root)
    {
        int leftLeafSum = 0;

        if(root == nullptr)
            return 0;

        if(isLeaf(root->left))
        {
            leftLeafSum+= root->left->val;
        }

        leftLeafSum+= sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

        return leftLeafSum;
    }
};
