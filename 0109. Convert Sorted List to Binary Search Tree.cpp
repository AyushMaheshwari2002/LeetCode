/* Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
   For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

            Example 1:
                  Input: head = [-10,-3,0,5,9]
                  Output: [0,-3,9,-10,null,5]
                  Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

            Example 2:
                  Input: head = []
                  Output: []
*/



// TC : O(N log n)     SC : O(1)
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
    	if(head == NULL)
    		return NULL;
        
    	if(head -> next == NULL)   
    	{	
    		TreeNode *root = new TreeNode(head -> val);
    		return root;
    	}
        
    	ListNode *slow = head , *fast = head -> next;
        
    	while(fast->next != NULL && fast->next->next != NULL)
    	{
    		slow = slow -> next;
    		fast = fast -> next -> next;
    	}
        
        ListNode* mid = slow -> next;
        slow -> next = NULL;
        
    	TreeNode *root = new TreeNode(mid -> val);
    	root -> left = sortedListToBST(head);
    	root -> right = sortedListToBST(mid -> next);
        
    	return root;
    }
};



