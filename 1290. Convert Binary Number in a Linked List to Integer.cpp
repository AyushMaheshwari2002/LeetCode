/*  Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary 
    representation of a number.
    Return the decimal value of the number in the linked list.

            Example 1:
            Input: head = [1,0,1]
            Output: 5
            Explanation: (101) in base 2 = (5) in base 10

            Example 2:
            Input: head = [0]
            Output: 0
*/



class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        int ans = 0;
        
        while(head != NULL)
        {
            ans = 2 * ans + head -> val;
            head = head -> next;
		        // DRY  RUN FOR 1->0->1
            // 2*0 + 1 = 1
            // 1*2 + 0 = 2
            // 2*2 + 1 = 5
        }
        
        return ans;
    }
};



