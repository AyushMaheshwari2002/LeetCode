/*  Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

            Example 1:
            Input: root = [4,2,6,1,3]
            Output: 1

            Example 2:
            Input: root = [1,0,48,null,null,12,49]
            Output: 1
*/



class Solution {
public:  
    
    void inorder(TreeNode *root , vector<int> &v)
    {
        if(root == NULL)
            return;
        
        inorder(root -> left , v);
        v.push_back(root -> val);
        inorder(root -> right , v);
    }
    
    int getMinimumDifference(TreeNode *root)
    {
        int diff = INT_MAX;
        
        vector<int> v;
        inorder(root , v);
        
        for(int i = 0; i < v.size()-1; i++)
        {
            diff = min(v[i+1] - v[i] , diff);
        }
        
        return diff;
    }
};



