/* You are given the heads of two sorted linked lists list1 and list2.
   Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
   Return the head of the merged linked list.

              Example 1:
              Input: list1 = [1,2,4], list2 = [1,3,4]
              Output: [1,1,2,3,4,4]

              Example 2:
              Input: list1 = [], list2 = []
              Output: []

              Example 3:
              Input: list1 = [], list2 = [0]
              Output: [0]
*/


// RECURSIVE METHOD
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		if(l1 == NULL)
        {
			return l2;
		}
		if(l2 == NULL)
        {
			return l1;
		}        
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};	


/* ITERATIVE METHOD
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {   
        if(list1 == NULL)
            return list2;
        
        if(list2 == NULL)
            return list1;
        
        ListNode *ptr = list1;
        if(list1 -> val > list2 -> val)
        {
            ptr = list2;
            list2 = list2 -> next;
        }
        else
        {
            list1 = list1 -> next;
        }
        
        ListNode *curr = ptr;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1 -> val < list2 -> val)
            {
                curr -> next = list1;
                list1 = list1 -> next;
            }
            else 
            {
                curr -> next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;
                
        }
        if(list1 != NULL)
            curr -> next = list2;
        else
            curr -> next = list1;
            
        return ptr;
       
    }
};
*/


