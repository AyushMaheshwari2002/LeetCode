/*  Given the head of a linked list, return the list after sorting it in ascending order.

          Example 1:
              Input: head = [4,2,1,3]
              Output: [1,2,3,4]

          Example 2:
              Input: head = [-1,5,3,4,0]
              Output: [-1,0,3,4,5]

          Example 3:
              Input: head = []
              Output: []
*/



class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        ListNode* temp = head;
        ListNode* temp2 = head;
        
        // store the linked list in the form of vector
        vector<int> v;
        
        while(temp != NULL)
        {
            v.push_back(temp -> val);
            temp = temp -> next;
        }
        
        sort(v.begin() , v.end());
        
        // rebuilt the linked list
        int i = 0;
        while(temp2 != NULL)
        {
            temp2 -> val = v[i];
            i++;
            temp2 = temp2 -> next;
        }
        
        return head;
    }
};



