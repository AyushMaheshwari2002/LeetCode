/*  Given a binary tree
            struct Node {
              int val;
              Node *left;
              Node *right;
              Node *next;
            }
    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
    Initially, all next pointers are set to NULL.

            Example 1:
                  Input: root = [1,2,3,4,5,null,7]
                  Output: [1,#,2,3,#,4,5,7,#]
                  Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in 
                  Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

            Example 2:
                  Input: root = []
                  Output: []
*/



class Solution {
public:
    Node* connect(Node* root) 
    {
        if (!root)
            return root;
                
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
                
        while (q.size() > 1)
        {
            Node* curr = q.front();
            q.pop();
            if (!curr)
            {
                q.push(NULL);
                continue;
            }
            curr->next = q.front();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return root;
    }
};



