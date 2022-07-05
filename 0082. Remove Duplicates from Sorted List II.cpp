/* Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list
   sorted as well.

            Example 1:
                  Input: head = [1,2,3,3,4,4,5]
                  Output: [1,2,5]

            Example 2:
                  Input: head = [1,1,1,2,3]
                  Output: [2,3]
*/



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0 , head);
        ListNode* prev = dummy;
        
        while(head != NULL)
        {
            if(head->next != NULL && head->val == head->next->val)
            {
               while(head->next != NULL && head->val == head->next->val)
               {
                   head = head->next;
               }
                prev->next = head->next;
            } 
            else
            {
                prev = prev->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};



