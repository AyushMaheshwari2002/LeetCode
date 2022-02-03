/*  Given the head of a singly linked list, return true if it is a palindrome.

        Example 1:
              Input: head = [1,2,2,1]
              Output: true

        Example 2:
              Input: head = [1,2]
              Output: false
*/


class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        vector<int> v;
        ListNode* temp = head;
        
        while(temp != NULL)
        {
            v.push_back(temp -> val);
            temp = temp -> next;
        }
        
        int k = v.size()-1;
        
        for(int i = 0; i < v.size()/2; i++)
        {
            if(v[i] != v[k])
                return false;
            
            k--;
        }
        return true;
    }
};

