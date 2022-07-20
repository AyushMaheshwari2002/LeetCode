/* Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
   You must write an algorithm that runs in O(n) time.

            Example 1:
                  Input: nums = [100,4,200,1,3,2]
                  Output: 4
                  Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

            Example 2:
                  Input: nums = [0,3,7,2,5,8,4,6,0,1]
                  Output: 9
*/



class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> s;
        int ans = 0;

        for(int i : nums)
            s.insert(i);

        for(int i = 0; i < nums.size(); i++)
        {
            if(s.find(nums[i]-1) == s.end())        //run if previous element is not found
            {
                int count = 1;
                
                while(s.find(nums[i] + count) != s.end())          //runs if next element is found
                {
                    count++;
                }
                
                ans = max(ans , count);
            }
        }
        
        return ans;
    }
};



