/*  You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
    Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
    Return a list of integers representing the size of these parts.

            Example 1:
                  Input: s = "ababcbacadefegdehijhklij"
                  Output: [9,7,8]
                  Explanation:
                  The partition is "ababcbaca", "defegde", "hijhklij".
                  This is a partition so that each letter appears in at most one part.
                  A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

            Example 2:
                  Input: s = "eccbbbbdec"
                  Output: [10]
*/



class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        // this will store the index of last occurrence of character
        vector<int> last_occ(26,0);
       
        // find the index of last occurrence
        for(int i = 0; i < s.size(); i++)
        {
            last_occ[s[i] - 'a'] = i;
        }
        
        vector<int> ans;
        int start = 0, end = 0;
        
        // whenever we find the character
        // we point the end to the last index of that character
        for(int i = 0; i < s.size(); i++)
        {
            end = max(end , last_occ[s[i] - 'a']);
            if(i == end)
            {
                // all the characters of current partition included
                ans.push_back(i - start + 1);
				// update the start pointer for fresh start
                start = i + 1;
            }
        }
        return ans;
    }
};




