/*  Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

          Example 1:
                Input: root = [4,2,6,1,3]
                Output: 1

          Example 2:
                Input: root = [1,0,48,null,null,12,49]
                Output: 1
*/



class Solution {
public:
    
    vector<int> v;
    
    int minDiffInBST(TreeNode* root) 
    {
        // inorder is always in ascending order
        if(root != NULL)
        {
            minDiffInBST(root->left);
            v.push_back(root->val);
            minDiffInBST(root->right);
        }
        
        int ans = INT_MAX;
        
        for(int i = 1; i < v.size(); i++)
        {
            ans = min(ans, abs(v[i]-v[i-1]));
        }
        
        return ans;
    }
};




