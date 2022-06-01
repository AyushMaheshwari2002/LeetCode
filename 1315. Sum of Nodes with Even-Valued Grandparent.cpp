/* Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.
   A grandparent of a node is the parent of its parent if it exists.

          Example 1:
                Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
                Output: 18
                Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

          Example 2:
                Input: root = [1]
                Output: 0
*/



class Solution {
public:
    int sum = 0;
    
    int sumEvenGrandparent(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        if(root -> val % 2 == 0)
        {
            if(root -> left != NULL)
            {
                if(root -> left -> left != NULL) 
                    sum += root -> left -> left -> val;
                
                if(root -> left -> right != NULL) 
                    sum += root -> left -> right -> val;
            }
            if(root -> right != NULL)
            {
                if(root -> right -> left != NULL) 
                    sum += root -> right -> left -> val;
                
                if(root -> right -> right != NULL) 
                    sum += root -> right -> right -> val;
            }
        }
        
        sumEvenGrandparent(root -> left);
        sumEvenGrandparent(root -> right);
        
        return sum;
    }
};



