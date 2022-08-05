/* Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

   Implement the FreqStack class:
       * FreqStack() constructs an empty frequency stack.
       * void push(int val) pushes an integer val onto the top of the stack.
       * int pop() removes and returns the most frequent element in the stack.
            * If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

            Example 1:
                  Input
                  ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
                  [[], [5], [7], [5], [7], [4], [5], [], [], [], []]

                  Output
                  [null, null, null, null, null, null, null, 5, 7, 5, 4]

                  Explanation
                  FreqStack freqStack = new FreqStack();
                  freqStack.push(5); // The stack is [5]
                  freqStack.push(7); // The stack is [5,7]
                  freqStack.push(5); // The stack is [5,7,5]
                  freqStack.push(7); // The stack is [5,7,5,7]
                  freqStack.push(4); // The stack is [5,7,5,7,4]
                  freqStack.push(5); // The stack is [5,7,5,7,4,5]
                  freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
                  freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
                  freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
                  freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
*/




class FreqStack {
public:
    // this will store the frequency of element
    unordered_map<int,int> freq;
    // we create multiple stacks for different values of frequency
    // But the element that come last will come first of same count
    unordered_map<int,stack<int>> group_stack;
    
    int maxfreq = 0;
    
    FreqStack() {}
    
    void push(int val)
    {
        // increment the frequency 
        freq[val]++;
        // if element occurs many times then update the value of max_freq(store the maximum frequency of element)
        maxfreq = max(maxfreq , freq[val]);
        // store the element in stack according to its frequency
        group_stack[freq[val]].push(val);     
    }
    
    int pop() 
    {
        // find the maximum frequency element in stack
        int top = group_stack[maxfreq].top();
        // remove that element from stack
        group_stack[maxfreq].pop();
        // decrement its count from frequency map
        freq[top]--;
        // if there is no element in stack for that frequency then decrement maxfreq
        if(group_stack[maxfreq].size() == 0)
            maxfreq--;
        
        return top;
        
    }
};




