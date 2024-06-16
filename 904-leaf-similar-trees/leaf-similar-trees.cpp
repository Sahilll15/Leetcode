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
    void gatherLeaves(TreeNode* root, vector<int>& leaves) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
        }

        gatherLeaves(root->left, leaves);
        gatherLeaves(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        gatherLeaves(root1, leaves1);
        gatherLeaves(root2, leaves2);

        return leaves1 == leaves2;
    }
};
