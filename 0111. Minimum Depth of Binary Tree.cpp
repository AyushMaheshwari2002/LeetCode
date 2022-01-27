/*  Given a binary tree, find its minimum depth.
    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

              Example 1:
                    Input: root = [3,9,20,null,null,15,7]
                    Output: 2

              Example 2:
                    Input: root = [2,null,3,null,4,null,5,null,6]
                    Output: 5
*/


class Solution {
public:
    int minDepth(TreeNode* root) 
    {        
        if(root == NULL)
            return 0;
        
        if(root -> left == NULL) 
            return 1 + minDepth(root -> right);
        
        if(root -> right == NULL) 
            return 1 + minDepth(root -> left);
        
        else
            return 1 + min(minDepth(root -> left), minDepth(root -> right));
    }
};

