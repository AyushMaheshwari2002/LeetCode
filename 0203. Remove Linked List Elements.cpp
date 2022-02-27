/* Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

                Example 1:
                Input: head = [1,2,6,3,4,5,6], val = 6
                Output: [1,2,3,4,5]

                Example 2:
                Input: head = [], val = 1
                Output: []

                Example 3:
                Input: head = [7,7,7,7], val = 7
                Output: []
*/



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {    
        while(head != NULL && head -> val == val)    // eg [7, 7, 7, 3] val = 7, then we have to delete all 7 and move head to 3.
        {
            head = head -> next;
        }
        
        if(head == NULL)            // eg [7, 7, 7, 7] val = 7, then we have to delete all 7 and return NULL.
            return head;
        
        ListNode* curr = head;
        
        while(curr -> next != NULL)
        {
            if(curr -> next -> val == val)
            {
                curr -> next = curr -> next -> next;
            }
            else  
            {
                curr = curr -> next;
            }
        }
        
        return head;
    }
};


