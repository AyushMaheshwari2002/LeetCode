hgggfb/*  Given the root of a binary tree, return the sum of all left leaves.
    A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

          Example 1:
                Input: root = [3,9,20,null,null,15,7]
                Output: 24
                Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
                
          Example 2:
                Input: root = [1]
                Output: 0
*/



class Solution {
public:
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root)
    {
        if(root != NULL)
        {
            if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
            {
                ans += root->left->val;
            }
            sumOfLeftLeaves(root->left);
            sumOfLeftLeaves(root->right);
        }
        
        return ans;
    }
};


