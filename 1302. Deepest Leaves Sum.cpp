/*  Given the root of a binary tree, return the sum of values of its deepest leaves.

            Example 1:
            Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
            Output: 15

            Example 2:
            Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
            Output: 19
*/



class Solution {  
public:
    int deepestLeavesSum(TreeNode* root) 
    {
        if(root -> left == NULL && root -> right == NULL)
            return root -> val;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        int sum = 0, last_sum = 0;
        
        while(!q.empty())
        {
            TreeNode* x = q.front();
            q.pop();
            
            if(x == NULL)
            {
                if(q.size() == 0)
                {
                    last_sum = sum;
                    break;
                }
                q.push(NULL);
                sum = 0;
            }
            else
            {
                sum += x -> val;
                if(x -> left != NULL) 
                  q.push(x -> left);
                if(x -> right != NULL) 
                  q.push(x -> right);
            }
        }
        return last_sum;
    }
};



