/*  Given the root of a binary tree, return the inorder traversal of its nodes' values.

          Example 1:
                  Input: root = [1,null,2,3]
                  Output: [1,3,2]

          Example 2:
                  Input: root = []
                  Output: []

          Example 3:
                  Input: root = [1]
                  Output: [1] 
*/


class Solution {
public:
    vector<int> data;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root != NULL)
        {
            inorderTraversal(root -> left);
            data.push_back(root -> val);
            inorderTraversal(root -> right);
        }
        return data;
    }
};
