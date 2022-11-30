/*  Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
    An alphanumeric string is a string consisting of lowercase English letters and digits.

          Example 1:
                Input: s = "dfa12321afd"
                Output: 2
                Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.

          Example 2:
                Input: s = "abc1111"
                Output: -1
                Explanation: The digits that appear in s are [1]. There is no second largest digit. 
*/



class Solution {
public:
	int secondHighest(string s) 
    {
		set<int> st;
        
		for(auto i : s)
        {
			if(isdigit(i))
            {
				st.insert(i - '0');
			}
		}
        
        vector<int> v;
        for(auto i : st)
            v.push_back(i);
        
        sort(v.rbegin() , v.rend());
        
		if(st.size() < 2)
			return -1;
        	
        return v[1];
	}
};



/*
class Solution {
public:
	int secondHighest(string s) 
    {
		set<int> st;
        
		for(auto i : s)
        {
			if(isdigit(i))
            {
				st.insert(i - '0');
			}
		}
        
		if(st.size() < 2)
			return -1;
        
		else {
			auto it = st.end();
			it--;
			it--;
			
            return *it;
		}
	}
};
*/


