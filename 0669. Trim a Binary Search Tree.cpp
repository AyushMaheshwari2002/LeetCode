/*  Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming
    the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be
    proven that there is a unique answer.
    Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

              Example 1:
                      Input: root = [1,0,2], low = 1, high = 2
                      Output: [1,null,2]

              Example 2:
                      Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
                      Output: [3,2,null,1]
*/



class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if(root == NULL)
            return NULL;
        
        // if root value is smaller than low so there is no need to go in left side
        // because all values will be more smaller than low so we can go for right side
        // BST GO TO RIGHT SIDE FOR VALID RANGE [low , high]
        if(root -> val < low)
            return trimBST(root -> right , low , high);
        
        // BST GO TO LEFT SIDE FOR VALID RANGE [low , high]
        if(root -> val > high)
            return trimBST(root -> left , low , high);
        
        // ONLY CASE REMAINING is ROOT lies WITHIN RANGE [low , high]
        root -> left = trimBST(root -> left , low , high);
        root -> right = trimBST(root -> right , low , high);
        
        return root;
    }
};



