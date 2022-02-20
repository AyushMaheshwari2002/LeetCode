/*  Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
    A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

                  Example 1:
                  Input: nums = [-10,-3,0,5,9]
                  Output: [0,-3,9,-10,null,5]
                  Explanation: [0,-10,5,null,-3,null,9] is also accepted:

                  Example 2:
                  Input: nums = [1,3]
                  Output: [3,1]
                  Explanation: [1,3] and [3,1] are both a height-balanced BSTs.
*/


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return BST(nums, 0, nums.size()-1);
    }
    
    TreeNode* BST(vector<int>& nums, int low, int high) 
    {
        if(low <= high)
        {
            int mid = low + (high - low)/2; 
            
            TreeNode* root = new TreeNode(nums[mid]);
            root -> left = BST(nums, low, mid-1);
            root -> right = BST(nums, mid+1, high);
            
            return root;
        }
        return NULL;
    }
};

