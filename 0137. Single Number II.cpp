/*  Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
    You must implement a solution with a linear runtime complexity and use only constant extra space.

            Example 1:
                  Input: nums = [2,2,3,2]
                  Output: 3

            Example 2:
                  Input: nums = [0,1,0,1,0,1,99]
                  Output: 99
*/



// Hash Table Algo
// Time: O(n)        Space: O(n)

class Solution {
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> m;

        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        for(auto i : m)
        {
            if(i.second == 1)
                return i.first;
        }

        return -1;
    }
};



/*
// XOR Bit Manipulation Algo
// Time: O(n)      Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {       
        int ones = 0;
        int twos = 0;
        
        for (int i : nums) 
        {
            ones = (ones ^ i) & (~twos);
            twos = (twos ^ i) & (~ones);
        }
        
        return ones;
    }
};
*/


