/*  Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

            Example 1:
                  Input: root = [3,1,4,null,2], k = 1
                  Output: 1

            Example 2:
                  Input: root = [5,3,6,2,4,null,null,1], k = 3
                  Output: 3
*/



class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v)
    {
        if(root == NULL)
            return;
        
        inorder(root -> left , v);
        v.push_back(root -> val);
        inorder(root -> right , v);
        
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        if(root == NULL)
            return -1;
        
        vector<int> v;
        
        inorder(root, v);
        
        return v[k-1];
    }
};



