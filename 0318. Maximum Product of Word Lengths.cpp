/*  Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words
    exist, return 0.

            Example 1:
                  Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
                  Output: 16
                  Explanation: The two words can be "abcw", "xtfn".

            Example 2:
                  Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
                  Output: 4
                  Explanation: The two words can be "ab", "cd".

            Example 3:
                  Input: words = ["a","aa","aaa","aaaa"]
                  Output: 0
                  Explanation: No such pair of words.
*/



class Solution {
public:
    vector<int> out;
    int maxProduct(vector<string>& words) 
    {    
        int prod, maxprod = 0, cnt = 0;
        
        for(int i = 0; i<words.size() ; ++i)
        {
            map<char,int> m;
            for(auto itr : words[i])
                ++m[itr];
            
            for(int j = i+1; j < words.size(); ++j)
            {
                cnt = 0;
                for(auto s : words[j])
                {
                    if(m.find(s) !=  m.end())
                        break;
                    ++cnt;
                }
                if(cnt == words[j].size())
                {
                    prod = words[i].size() * words[j].size();
                    maxprod = max(maxprod,prod);
                }
            }
        }
        
        return maxprod;     
    }
};




