/*  Given the head of a linked list, remove the nth node from the end of the list and return its head.

              Example 1:
              Input: head = [1,2,3,4,5], n = 2
              Output: [1,2,3,5]

              Example 2:
              Input: head = [1], n = 1
              Output: []

              Example 3:
              Input: head = [1,2], n = 1
              Output: [1]
*/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 1; i <= n; i++) 
        {
            fast = fast -> next;
        }

        if (fast == NULL)                    //case if we have to delete first element in linked list
        { 
            return head -> next;
        }

        while(fast -> next != NULL) 
        {
            fast = fast -> next;
            slow = slow -> next;
        }

        slow -> next = slow -> next -> next;
        
        return head;
    }
};

