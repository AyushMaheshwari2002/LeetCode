/*  Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
    If the tree has more than one mode, return them in any order.
    Assume a BST is defined as follows:
          * The left subtree of a node contains only nodes with keys less than or equal to the node's key.
          * The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
          * Both the left and right subtrees must also be binary search trees.
 
            Example 1:
                  Input: root = [1,null,2,2]
                  Output: [2]

            Example 2:
                  Input: root = [0]
                  Output: [0]
*/



class Solution {
public:
    
    void inorder(TreeNode* root, unordered_map<int,int>& map)
    {
        if(root == NULL)
            return;
        
        inorder(root->left , map);
        map[root->val]++;
        inorder(root->right , map);
    }

    vector<int> findMode(TreeNode* root) 
    {
        unordered_map<int,int> map;
        inorder(root , map);
        
        int maxFreq = 0;
        for(auto i : map)
            maxFreq = max(i.second , maxFreq);
        
        vector<int> res;
        for(auto i : map)
        {
            if(i.second == maxFreq)
            {
                res.push_back(i.first);
            }
        }
        return res;
    }
};



