/*  Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

          Example 1:
                Input: root = [5,3,6,2,4,null,7], k = 9
                Output: true

          Example 2:
                Input: root = [5,3,6,2,4,null,7], k = 28
                Output: false
*/


class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root)
    {
        if(root == 0)
        {
            return;
        }
        else {
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int p1 = 0;
        int p2 = v.size() - 1;
        
        while (p1 < p2) {
            if (v[p1] + v[p2] == k) 
            {
                return true;
            }
            else if (v[p1] + v[p2] > k) 
            {
                p2--;
            }
            else { 
                p1++; 
            }
        }
        return false;
    }
};

