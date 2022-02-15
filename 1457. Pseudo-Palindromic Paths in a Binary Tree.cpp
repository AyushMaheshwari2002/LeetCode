/*  Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of 
    the node values in the path is a palindrome.
    Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

            Example 1:
            Input: root = [2,3,1,3,1,null,1]
            Output: 2 
            Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], 
            the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] 
            can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).

            Example 2:
            Input: root = [2,1,1,1,3,null,null,null,null,null,1]
            Output: 1 
            Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], 
            the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).

            Example 3:
            Input: root = [9]
            Output: 1
*/


class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;             //'count' count the odd occurrences like 1 2 3 2 1 ; the occurrence of 3 is 1 hence it is a palindrome. If the occurrence                                       is greater than 1 then it is not a palindrome like 1 2 3 4 1.
        vector<int> v(10,0);
        
        pseudo_count(root, v, count);
        
        return count;
    }
    
    void pseudo_count(TreeNode* root, vector<int> &v, int &count)
    {
        if(root == NULL)
            return;
        
        v[root -> val]++;
        pseudo_count(root -> left, v, count);
        pseudo_count(root -> right, v, count);
        
        if(root -> left == NULL && root -> right == NULL)
        {
            int flag = 0;
            
            for(int i = 0; i <= v.size()-1; i++)
            {
                if(v[i] % 2 != 0)
                    flag++;
            }
            if(flag == 1 || flag == 0)
                count++;    
        }
        v[root -> val]--;
    }
};

