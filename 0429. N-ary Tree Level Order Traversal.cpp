/*  Given an n-ary tree, return the level order traversal of its nodes' values.
    Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

            Example 1:
                  Input: root = [1,null,3,2,4,null,5,6]
                  Output: [[1],[3,2,4],[5,6]]

            Example 2:
                  Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
                  Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
*/



class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        if(root == NULL) 
            return {};
        
        vector<vector<int>> ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> v;
            
            for(int i = 0; i < size; i++)
            {
                Node* node = q.front();
                q.pop();

                v.push_back(node->val);

                // push the other childrens of root in queue
                for(auto i : node -> children)
                    q.push(i);
            }
        
            ans.push_back(v);
        }
        
        return ans;
    }
};



