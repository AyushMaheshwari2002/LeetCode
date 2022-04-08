/* Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no 
   left child and only one right child.

          Example 1:
          Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
          Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

          Example 2:
          Input: root = [5,1,7]
          Output: [1,null,5,null,7]
*/



class Solution {
public:
    TreeNode* newtree = new TreeNode(0);                      // make new node and initialize with 0 value
    TreeNode* ans = newtree;                                  // another node pointing to the head of new node
    
    void inorder(TreeNode* root)
    {
         if(root == NULL)
         {
            return;
         }
        
        inorder(root -> left);
        newtree -> right = new TreeNode(root -> val);             // make new node with root value 
        newtree = newtree -> right;                               // move ahead in right direction
        
        inorder(root -> right);
       
    }
    
    TreeNode* increasingBST(TreeNode* root) 
    {           
        inorder(root);
        
        return ans -> right;                                       // move in right to skip the initial 0 value
    }
};


