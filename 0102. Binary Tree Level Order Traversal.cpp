/*  Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

            Example 1:
                  Input: root = [3,9,20,null,null,15,7]
                  Output: [[3],[9,20],[15,7]]

            Example 2:
                  Input: root = [1]
                  Output: [[1]]

            Example 3:
                  Input: root = []
                  Output: []
*/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        
        if(root == NULL)
            return result;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty())
        {
            int size = Q.size();
            
            vector<int> level;
            
            for(int i = 0; i < size; i++) 
            { 
                TreeNode *node = Q.front();
                Q.pop();
            
                if(node -> left != NULL)
                    Q.push(node -> left);
                
                if(node -> right != NULL)
                    Q.push(node -> right);
            
                level.push_back(node -> val);
            }
            result.push_back(level);
        }
        return result;
    }
};

