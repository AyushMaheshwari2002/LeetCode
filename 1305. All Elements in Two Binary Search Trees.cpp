/* Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

            Example 1:
            Input: root1 = [2,1,4], root2 = [1,0,3]
            Output: [0,1,1,2,3,4]

            Example 2:
            Input: root1 = [1,null,8], root2 = [8,1]
            Output: [1,1,8,8]
*/



class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        inorder(root1);
        inorder(root2);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
    
    vector<int> ans;
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        inorder(root -> left);
        ans.push_back(root -> val);
        inorder(root -> right);
    }
};


