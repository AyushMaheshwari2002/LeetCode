/*  You are given the head of a linked list, and an integer k.
    Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

          Example 1:
              Input: head = [1,2,3,4,5], k = 2
              Output: [1,4,3,2,5]

          Example 2:
              Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
              Output: [7,9,6,6,8,7,3,0,9,5]
*/



class Solution {
public:
    
    void swap(int i, int j, vector<int> &v)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* temp = head;
        ListNode* temp2 = head;
        
        // store the linked list in the form of vector
        vector<int> v;
        int count = 0;              //this will give the size of linked list
        
        while(temp != NULL)
        {
            v.push_back(temp -> val);
            temp = temp -> next;
            count++;
        }
        
        swap(k - 1 , count - k , v);
        
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



