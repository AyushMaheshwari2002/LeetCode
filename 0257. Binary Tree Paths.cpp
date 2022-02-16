/*  Given the root of a binary tree, return all root-to-leaf paths in any order. A leaf is a node with no children.

              Example 1:
              Input: root = [1,2,3,null,5]
              Output: ["1->2->5","1->3"]

              Example 2:
              Input: root = [1]
              Output: ["1"]
*/


class Solution {
public:
    
    vector <string> ans;
    
    void getval(TreeNode *root, string s)
    {
        if(root -> left == NULL && root -> right == NULL)
            ans.push_back(s);
        
        if(root -> left != NULL)
            getval(root -> left, s + "->" + to_string(root -> left -> val));
        
        if(root -> right != NULL)
            getval(root -> right, s + "->" + to_string(root -> right -> val));
    }
     
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string s = "";
        s += to_string(root -> val);
        getval(root, s);
        return ans;
    }
};


