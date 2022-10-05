/*  Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node
    has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) 
    always holds.
    Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
    If no such second minimum value exists, output -1 instead.

            Example 1:
                    Input: root = [2,2,5,null,null,5,7]
                    Output: 5
                    Explanation: The smallest value is 2, the second smallest value is 5.

            Example 2:
                    Input: root = [2,2,2]
                    Output: -1
                    Explanation: The smallest value is 2, but there isn't any second smallest value.
*/



/* USING VECTOR
class Solution {
public:
      vector<int> v;
      int findSecondMinimumValue(TreeNode* root)
      {
          if(root == NULL) 
              return 0;
          
          v.push_back(root -> val);
          findSecondMinimumValue(root -> left);
          findSecondMinimumValue(root -> right);
    
          sort(v.begin() , v.end());
          v.erase(unique(v.begin(),v.end()) , v.end());
          
          if(v.size() < 2)
              return -1;
          
          return v[1];
      }
};
*/



// USING SET
class Solution {
public:

    void traverse(TreeNode* root , set<int> &s)
    {
            if(root == NULL)
            {
                return;
            } 
            
            s.insert(root -> val);
            traverse(root -> left , s);
            traverse(root -> right , s);
    }

    int findSecondMinimumValue(TreeNode* root)
    {
        set<int> s;
        traverse(root , s);

        // check if there are atleast 2 unique nodes so that we can find second largest element
        if(s.size() < 2)
            return -1;

        auto it = s.begin();     // points to 1st smallest element
        it++;                    // points to 2nd smallest element
        return *it;
    }
};




