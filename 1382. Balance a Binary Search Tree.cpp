/*  Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
    A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

          Example 1:
                Input: root = [1,null,2,null,3,null,4,null,null]
                Output: [2,1,3,null,null,null,4]
                Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

          Example 2:
                Input: root = [2,1,3]
                Output: [2,1,3]
*/



class Solution {
public:
    vector<TreeNode*> ans;
    
    TreeNode* balanceBST(TreeNode* root) 
    {
        inorder(root);
        
        return BST(0, ans.size() - 1);
    }
    
    void inorder(TreeNode* root) 
    {
        if (root == NULL) 
            return;
    
        inorder(root -> left);
        ans.push_back(root);
        inorder(root -> right);
    }
    
    TreeNode* BST(int start, int end) 
    {
        if (start > end) 
            return NULL;
        
        int mid = (start + end) / 2;
        
        TreeNode* root = ans[mid];
        root -> left = BST(start , mid - 1);
        root -> right = BST(mid + 1 , end);
        
        return root;
    }
};


