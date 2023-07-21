ubhbjb/*  Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in 
    the string.
    Return the sorted string. If there are multiple answers, return any of them.

          Example 1:
                Input: s = "tree"
                Output: "eert"
                Explanation: 'e' appears twice while 'r' and 't' both appear once.
                So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
                
          Example 2:
                Input: s = "cccaaa"
                Output: "aaaccc"
                Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
                Note that "cacaca" is incorrect, as the same characters must be together.
                
          Example 3:
                Input: s = "Aabb"
                Output: "bbAa"
                Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
                Note that 'A' and 'a' are treated as two different characters.
*/



class Solution {
public:
    string frequencySort(string s)
    {
        map<int,int> m;
        
        for(int i = 0; i < s.length(); i++)
            m[s[i]]++;
        
        vector<pair<int , char>> v;
        for(auto i : m)
        {
            v.push_back({i.second , i.first});    // in vector we have first store the frequency then no. b'coz we have to sort the vector
                                                  // on the basis of increasing frequency
        }
        
        sort(v.begin() , v.end());
        reverse(v.begin() , v.end());
        
        string ans;
        for(int i = 0; i < v.size(); i++)
	    { 
            int k = v[i].first;              // store frequency of each characters
            
            while(k--)
		        ans += v[i].second;          // add each char by its frequency count
	    }
        
        return ans;   
    }
};




