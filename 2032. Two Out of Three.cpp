/*  Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays.
    You may return the values in any order.
 
            Example 1:
                  Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
                  Output: [3,2]
                  Explanation: The values that are present in at least two arrays are:
                  - 3, in all three arrays.
                  - 2, in nums1 and nums2.

            Example 2:
                  Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
                  Output: [2,3,1]
                  Explanation: The values that are present in at least two arrays are:
                  - 2, in nums2 and nums3.
                  - 3, in nums1 and nums2.
                  - 1, in nums1 and nums3.

            Example 3:
                  Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
                  Output: []
                  Explanation: No value is present in at least two arrays.
*/




/*
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& num1, vector<int>& num2, vector<int>& num3) 
    {
        set<int> a , b , c;
        
        for(auto x : num1)
            a.insert(x);
        
        for(auto x : num2) 
            b.insert(x);
        
        for(auto x : num3) 
            c.insert(x);
        
        
        map<int,int> m;
        for(auto x : a)
            m[x]++;
        
        for(auto x : b) 
            m[x]++;
        
        for(auto x : c)
            m[x]++;
        
        
        vector<int> res;
        for(auto x : m)
        {
            if(x.second > 1) 
                res.push_back(x.first);
        }
        
        return res;
    }
};
*/



class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) 
    {
        set<int> s;
        set<int> res;
        
        for(int i : nums1) 
        {
            s.insert(i);
        }
        
        for(int i : nums2) 
        {
            if(s.find(i) != s.end()) 
            {
                res.insert(i);
            }
        }
        
        for(int i : nums2)
        {
            s.insert(i);
        }
        
        for(int i : nums3)
        {
            if(s.find(i) != s.end()) 
            {
                res.insert(i);
            }
        }
        
        // convert set into vector
        return vector<int>(res.begin(), res.end());
    }
};



