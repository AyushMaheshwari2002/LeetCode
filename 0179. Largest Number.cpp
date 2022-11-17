/*  Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
    Since the result may be very large, so you need to return a string instead of an integer.

            Example 1:
                  Input: nums = [10,2]
                  Output: "210"

            Example 2:
                  Input: nums = [3,30,34,5,9]
                  Output: "9534330"
*/



class Solution {
public:
    
    //here we create a custom sort function.
    static bool cmp(string a , string b)
    {
        return (a+b) > (b+a);
    }
    
    string largestNumber(vector<int>& nums) 
    {
        //written to handle the corner case like [0,0,0] in these cases of all zeros we need to return 0 only. 
        int x = 0 ; 
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                x++;
        }
        if(x == nums.size())
            return "0";
        
        vector<string> v;
        
        for(auto i : nums)
            v.push_back(to_string(i));
        
        sort(v.begin() , v.end() , cmp);
        
        string s = "";
        
        for(auto i : v)
        {
            s += i;
        }
		
        return s;
        
    }
};



