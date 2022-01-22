/*  Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

          Example 1:
                  Input: nums1 = [1,2,2,1], nums2 = [2,2]
                  Output: [2]

          Example 2:
                  Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
                  Output: [9,4]
                  Explanation: [4,9] is also accepted. 
*/


// Basic Approach 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> result;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    result.insert(nums1[i]);
                }
            }
        }
        vector<int> numbers {
            result.begin(), result.end()
        };
        return numbers;
    }
};



// Approach Using Standard Template Library(STL) 
class Solution {
public: 
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> v;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(v));
        v.erase(unique(v.begin(), v.end()), v.end());
        return v;
    }
};
