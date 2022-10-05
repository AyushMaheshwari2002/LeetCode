/*  Given the root of a binary tree, return the length of the diameter of the tree.
    The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
    The length of a path between two nodes is represented by the number of edges between them.

            Example 1:
                    Input: root = [1,2,3,4,5]
                    Output: 3
                    Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

            Example 2:
                    Input: root = [1,2]
                    Output: 1
*/



class Solution {
public:
    
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int data = height(root);
        
        return diameter-1;
    }
    
    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int lh = height(root -> left);
        int rh = height(root -> right);
        
        diameter = max(diameter , 1+lh+rh);
        
        return 1 + max(lh , rh);
    }
};



