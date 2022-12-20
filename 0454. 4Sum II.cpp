/*  Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
        *  0 <= i, j, k, l < n
        *  nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
        
              Example 1:
                    Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
                    Output: 2
                    Explanation:
                    The two tuples are:
                    1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
                    2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

              Example 2:
                    Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
                    Output: 1

*/



class Solution {
public: 
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int count = 0;
        unordered_map<int,int> m;
        
        for(int i : nums1)
        { 
            for(int j : nums2)
            {
                m[i+j]++;
            }
        }
            
        for(int k : nums3)
        { 
            for(int l : nums4)
            { 
                count += m[-(k+l)];
            }
        }
        
        return count;
    }
};



/* TC : O(N^3)
class Solution {
public: 
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int count = 0;
        unordered_map<int,int> m;
        
        for(int i : nums1)
        { 
            m[i]++;
            
            for(int j : nums2)
            { 
                for(int k : nums3)
                { 
                    for(int l : nums4)
                    { 
                        count += m[-(j+k+l)];
                    }
                }
            }
        }
        return count;
    }
};
*/



/* TC : O(N^4)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int count = 0;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                for(int k = 0; k < nums3.size(); k++)
                {
                    for(int l = 0; l < nums4.size(); l++)
                    {
                        if(nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0)
                            count++;
                    }
                }
            }
        }
        return count;
    }
};
*/



