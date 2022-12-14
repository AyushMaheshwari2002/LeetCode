/*  Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree,
    construct and return the binary tree.

            Example 1:
                  Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
                  Output: [3,9,20,null,null,15,7]

            Example 2:
                  Input: preorder = [-1], inorder = [-1]
                  Output: [-1]
*/



class Solution {
public:
    TreeNode* rec(int l, int r) {
        if (l > r) return NULL;
        
        int i = 0;
        while (m_inorder[i] != m_preorder[m_curr]) {
            i++;
        }

        m_curr++;
        TreeNode* node = new TreeNode(m_inorder[i]);
        node->left = rec(l, i-1);
        node->right = rec(i+1, r);
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        m_preorder = preorder, m_inorder = inorder;
        return rec(0, preorder.size()-1);
    }
    
private:
    int m_curr = 0;
    vector<int> m_preorder, m_inorder;
};





