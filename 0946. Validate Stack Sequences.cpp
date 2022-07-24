/* Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on
   an initially empty stack, or false otherwise.

            Example 1:
                  Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
                  Output: true
                  Explanation: We might do the following sequence:
                  push(1), push(2), push(3), push(4),
                  pop() -> 4,
                  push(5),
                  pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

            Example 2:
                  Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
                  Output: false
                  Explanation: 1 cannot be popped before 2.
*/



class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> s;
        int j = 0;
        
        for (int i = 0; i < pushed.size(); i++) 
        {
            s.push(pushed[i]);
            
            // check weather the current top element of stack matches with the "i"th element that needs to get popped
            while (!s.empty() && s.top() == popped[j]) 
            { 
                s.pop();
                j++;
            }
        }
        
        // Since pushed is a permutation of popped so that at the end we are supposed to be left with an empty stack
        return s.empty();
    }
};



