/* Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

              Example 1:
              Input: root = [1,2,2,3,4,4,3]
              Output: true

              Example 2:
              Input: root = [1,2,2,null,3,null,3]
              Output: false
*/


class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {    
        if(root == NULL)                              //Tree is empty
            return true;
        
        return isSymmetricTest(root -> left, root -> right);
    }
    
    bool isSymmetricTest(TreeNode* p , TreeNode* q)
    {
        if(p == NULL && q == NULL)                             //left & right node is NULL 
            return true; 
        
        else if(p == NULL || q == NULL)                       //one of them is Not NULL
            return false; 
        
        else if(p -> val != q -> val) 
            return false;
            
        //comparing left subtree's left child with right subtree's right child --AND-- comparing left subtree's right child with right subtree's left child
        return isSymmetricTest(p -> left, q -> right) && isSymmetricTest(p -> right, q -> left);    
    }
};

