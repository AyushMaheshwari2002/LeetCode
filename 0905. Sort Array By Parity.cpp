/* Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
          Input: nums = [3,1,2,4]
          Output: [2,4,3,1]
          Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       vector<int>ans;
       vector<int>t;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0) 
                ans.push_back(nums[i]);
            
            else if(nums[i] % 2 != 0) 
                t.push_back(nums[i]);
        }
        for(auto it : t){
            ans.push_back(it);
        }
       return ans; 
    }
};
