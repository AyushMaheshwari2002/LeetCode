/* Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
            * BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should
              be initialized to a non-existent number smaller than any element in the BST.
            * boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
            * int next() Moves the pointer to the right, then returns the number at the pointer.
   Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
   You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

                Example 1:
                      Input
                      ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
                      [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
                      Output
                      [null, 3, 7, true, 9, true, 15, true, 20, false]

                      Explanation
                      BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
                      bSTIterator.next();    // return 3
                      bSTIterator.next();    // return 7
                      bSTIterator.hasNext(); // return True
                      bSTIterator.next();    // return 9
                      bSTIterator.hasNext(); // return True
                      bSTIterator.next();    // return 15
                      bSTIterator.hasNext(); // return True
                      bSTIterator.next();    // return 20
                      bSTIterator.hasNext(); // return False
*/




// TC : O(1)   SC : O(h)     where h is the height of the tree
class BSTIterator {
public:
    
    stack<TreeNode *> s;
    
    BSTIterator(TreeNode* root) 
    {
        push(root);
    }
    
    void push(TreeNode *root)
    {
        while(root != NULL)
        {
            s.push(root);
            root = root -> left;
        }
    }
    
    int next() 
    {
        TreeNode* temp = s.top();
        s.pop();
        push(temp -> right);
        
        return temp -> val;
    }
    
    bool hasNext()
    {
        return !s.empty();
    }
};




/*
// TC : O(1)   SC : O(N)
class BSTIterator {
public:
    
    vector<int> v;
    int i;
    void inorder(TreeNode *root, vector<int> &v)
    {
        if(root == NULL)
            return;

        inorder(root -> left , v);
        v.push_back(root -> val);
        inorder(root -> right , v);
    }

    BSTIterator(TreeNode* root)
    {
        inorder(root , v);
        i = 0;
    }

    int next() 
    {
        int temp = v[i];
        i++;
        return temp;
    }

    bool hasNext()
    {
        return i < v.size();
    }
};
*/



