/*  You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
    Return true if and only if we can do this so that the resulting number is a power of two.

            Example 1:
                  Input: n = 1
                  Output: true

            Example 2:
                  Input: n = 10
                  Output: false
*/



class Solution {
public:
    
    multiset<int> helper(int n)
    {
        multiset<int> s;
        
        while(n>0)
        {
            s.insert(n%10);
            n/=10;
        }
        return s;
    }
    
    bool reorderedPowerOf2(int n) 
    {    
        multiset<int> s;
        
        while(n>0)
        {
            s.insert(n%10);
            n/=10;
        }
        
        for(int i =0 ;i<32; ++i){
            int value = (1<<i);
            if(helper(value) == s)
                return true;
        }
        return false;
    }
};



