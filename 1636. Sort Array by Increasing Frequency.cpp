/*  Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in
    decreasing order.
    Return the sorted array.

            Example 1:
                    Input: nums = [1,1,2,2,2,3]
                    Output: [3,1,1,2,2,2]
                    Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

            Example 2:
                    Input: nums = [2,3,1,3,2]
                    Output: [1,3,3,2,2]
                    Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

            Example 3:
                    Input: nums = [-1,1,-6,4,5,-6,1,4,1]
                    Output: [5,-1,4,4,-6,-6,1,1,1]
*/




/*    
USE LAMBDA FUNCTION
FORMAT : 
        [&] (int a , int b) { return Expression; }
        [&] (parameters) { return Expression; }
        
If using a lambda function during sort. The lambda function specifies how to sort :-
        1. if the two no.s have different frequencies, the one with smaller frequency goes first.
        2. If frequencies are equal, then lexicographically greater goes first.
*/



class Solution {
public:
    vector<int> frequencySort(vector<int>& nums)
    {
        unordered_map<int , int> m;
        
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        
        sort(nums.begin(),nums.end() , [&] (int a, int b)
             //if frequencies are not equal then check which one is greater or
             // if frequencies are equal then check which element is greater
             { return m[a] != m[b] ? m[a] < m[b] : a > b ; });
        
        return nums;
    }
};



