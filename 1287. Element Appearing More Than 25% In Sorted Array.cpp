/*  Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

            Example 1:
                  Input: arr = [1,2,2,6,6,6,6,7,10]
                  Output: 6

            Example 2:
                  Input: arr = [1,1]
                  Output: 1
*/



class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        unordered_map<int,int> m;
        
        for(auto i : arr)
            m[i]++;
        
        for(auto i : m)
        {
            if(i.second > (arr.size()/4))
                return i.first;
        }
        
        return arr[0];         // Useless line just for complete the code
    }
};




