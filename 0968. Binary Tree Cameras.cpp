/*  You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
    Return the minimum number of cameras needed to monitor all nodes of the tree.

        Example 1:
            Input: root = [0,0,null,0,0]
            Output: 1
            Explanation: One camera is enough to monitor all nodes if placed as shown.

        Example 2:
            Input: root = [0,0,null,0,null,0,null,null,0]
            Output: 2
            Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
*/



class Solution {
public:
    
    int res = 0;
    int minCameraCover(TreeNode* root) 
    {
        return (dfs(root) < 1 ? 1 : 0) + res;
    }

    int dfs(TreeNode* root)
    {
        if (!root) return 2;
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if (left == 0 || right == 0)
        {
            res++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
};



