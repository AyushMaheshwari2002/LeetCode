/* Given the head of a linked list, rotate the list to the right by k places.

            Example 1:
            Input: head = [1,2,3,4,5], k = 2
            Output: [4,5,1,2,3]

            Example 2:
            Input: head = [0,1,2], k = 4
            Output: [2,0,1]
*/



class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == NULL)
        {
            return NULL;
        }
        if(head -> next == NULL)
        {
            return head;
        }
        int count = 1;             //count started with one because we need to stop at temp not at temp->next
        
        ListNode* temp = head;
        
        while(temp -> next != NULL)
        {
            temp = temp -> next;
            count++;
        }
 
        temp -> next = head ;                 // making the list circular
        
        k = k % count;                         //making k less than the size of linked list
         
        k = count - k;                        //making k less than the size of linked list
        
        while(k--)                          // running the while loop till k =0
        {
            temp = temp -> next;
        }
        head = temp -> next;
        temp -> next = NULL;
        
        return head;
    }  
};


