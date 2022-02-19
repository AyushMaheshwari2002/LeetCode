/* Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
   According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q 
   as descendants (where we allow a node to be a descendant of itself).”

                Example 1:
                Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
                Output: 6
                Explanation: The LCA of nodes 2 and 8 is 6.

                Example 2:
                Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
                Output: 2
                Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
                Example 3:

                Input: root = [2,1], p = 2, q = 1
                Output: 2
*/


// Recursive:

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(p -> val < root -> val && q -> val < root -> val)
            return lowestCommonAncestor(root -> left, p, q);
        
        else if (p -> val > root -> val && q -> val > root -> val)
            return lowestCommonAncestor(root -> right, p, q);
        
        else {
            return root;
        }
    }
};


/*
Iterative:

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL) 
        {
            if (p->val < root->val && q->val < root->val) 
                root = root->left;
            
            else if (p->val > root->val && q->val > root->val) 
                root = root->right;
            
            else return root;
        }
        return root;
    }
};


Explanation:
Case1: Both p & q are smaller than the root node, then both elements, as well as LCA, will be in the left subtree.
Case2: Both are greater than the root node, then both elements, as well as LCA, will be in the right subtree.
Case3: If 1 element is greater than the root and the other is smaller than the root, that means both elements are in different subtrees. That means the root node is the LCA.
*/


