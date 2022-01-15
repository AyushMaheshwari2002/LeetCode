/* Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
         Input: nums = [4,1,2,1,2]
         Output: 4
*/

class Solution {
public:

int singleNumber(vector<int>& nums) {
    int ans = 0;
  
    for(int i = 0; i < nums.size(); i++){
        ans = ans^nums[i];
    }
    return ans;
    }
};
