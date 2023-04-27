/*  You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single
    digit. Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

              Example 1:
                    Input: l1 = [7,2,4,3], l2 = [5,6,4]
                    Output: [7,8,0,7]

              Example 2:
                    Input: l1 = [2,4,3], l2 = [5,6,4]
                    Output: [8,0,7]

              Example 3:
                    Input: l1 = [0], l2 = [0]
                    Output: [0]
*/



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> s1, s2;

        while(l1 != NULL) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }

        while(l2 != NULL) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }

        ListNode* newNode = NULL;
        int carry = 0;

        while(!s1.empty() && !s2.empty())
        {
            int sum = s1.top() + s2.top() + carry;
            s1.pop();
            s2.pop();
            carry = sum / 10;

            if(newNode == NULL) {
                newNode = new ListNode(sum % 10);
            }
            else {
                ListNode* temp = new ListNode(sum % 10);
                temp -> next = newNode;
                newNode = temp;
            }
        }

        while(!s1.empty())
        {
            int sum = s1.top() + carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            s1.pop();
            temp -> next = newNode;
            newNode = temp;
        }

        while(!s2.empty())
        {
            int sum = s2.top() + carry;
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            s2.pop();
            temp -> next = newNode;
            newNode = temp;
        }

        if(carry)
        {
            ListNode* temp = new ListNode(carry);
            temp -> next = newNode;
            newNode = temp;
        }

        return newNode; 
    }
};




