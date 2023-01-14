/*  Given the root of a complete binary tree, return the number of the nodes in the tree.
    According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as
    possible. It can have between 1 and 2h nodes inclusive at the last level h.
    Design an algorithm that runs in less than O(n) time complexity.

            Example 1:
                  Input: root = [1,2,3,4,5,6]
                  Output: 6

            Example 2:
                  Input: root = []
                  Output: 0

            Example 3:
                  Input: root = [1]
                  Output: 1

*/



// Using QUEUE O((NlogN)^2)
class Solution {
public:
    int countNodes(TreeNode* root)
    {
        int count = 0;

        if(root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(node -> left != NULL) {
                count++;
                q.push(node -> left);
            }

            if(node -> right != NULL) {
                count++;
                q.push(node -> right);
            }
        }

        return count+1;       // +1 is for root node
    }
};




/* TC : O(N)
class Solution {
public:
    int count = 0;

    void solve(TreeNode* root)
    {
        if(root != NULL)
            count++;

        if(root -> left != NULL)
            solve(root -> left);

        if(root -> right != NULL)
            solve(root -> right);
    }

    int countNodes(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        solve(root);

        return count;
    }
};




//  TC : O(N)
class Solution {
public:
    int count = 0;

    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        if(root -> left != NULL)
            count++;
            solve(root -> left);

        if(root -> right != NULL)
            count++;
            solve(root -> right);

        return count;
    }

    int countNodes(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        solve(root);

        return count+1;
    }
};
*/



