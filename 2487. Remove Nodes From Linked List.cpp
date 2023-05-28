/*  You are given the head of a linked list.
    Remove every node which has a node with a strictly greater value anywhere to the right side of it.
    Return the head of the modified linked list.

            Example 1:
                  Input: head = [5,2,13,3,8]
                  Output: [13,8]
                  Explanation: The nodes that should be removed are 5, 2 and 3.
                  - Node 13 is to the right of node 5.
                  - Node 13 is to the right of node 2.
                  - Node 8 is to the right of node 3.

            Example 2:
                  Input: head = [1,1,1,1]
                  Output: [1,1,1,1]
                  Explanation: Every node has value 1, so no nodes are removed.
*/



class Solution {
public:
    ListNode* removeNodes(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* nextNode = removeNodes(head->next);
        if(nextNode->val > head->val)
        {
            return nextNode;
        }
        
        head->next = nextNode;
        
        return head;
    }
};




