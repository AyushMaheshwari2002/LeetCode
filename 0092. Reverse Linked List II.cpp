/*  Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, 
    and return the reversed list.

          Example 1:
                Input: head = [1,2,3,4,5], left = 2, right = 4
                Output: [1,4,3,2,5]

          Example 2:
                Input: head = [5], left = 1, right = 1
                Output: [5]
*/



class Solution {
public:
    
    ListNode* reverse(ListNode* head) 
    {    
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* next;
        
        while(current != NULL)
        {
            next = current -> next;
            current -> next = previous;
            
            previous = current;
            current = next;
        }
        
        return previous;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* curr = head, *prev = NULL;
        int count = 1;
        
        while(count != left) {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        
        // this is the node where we have to start reversing the node
        ListNode* start = curr;
        
        while(count != right) {
            curr = curr -> next;
            count++;
        }
        
        ListNode* connect = curr -> next;
        curr -> next = NULL;
        
        ListNode* newHead = reverse(start);
        
        if(prev != NULL)
            prev -> next = newHead;
        
        curr = newHead;
        while(curr -> next != NULL)
            curr = curr -> next;
        
        curr -> next = connect;
        
        if(left == 1)
            return newHead;
        return head;
    }
};




