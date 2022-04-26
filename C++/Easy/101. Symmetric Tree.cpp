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

    bool isSymTree(TreeNode* p, TreeNode* q)
    {
        if(p == nullptr && q == nullptr)
            return true;

        if(p == nullptr || q == nullptr)
            return false;

        if(p-> val != q->val)
            return false;

        return isSymTree(p->left, q->right) && isSymTree(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root)
    {
        if(!root)
            return false;

        return isSymTree(root->left, root->right);
    }
};
