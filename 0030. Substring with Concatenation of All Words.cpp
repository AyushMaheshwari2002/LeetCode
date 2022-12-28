/*  You are given a string s and an array of strings words. All the strings of words are of the same length.
    A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
        * For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is
          not a concatenated substring because it is not the concatenation of any permutation of words.
    Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

            Example 1:
                  Input: s = "barfoothefoobarman", words = ["foo","bar"]
                  Output: [0,9]
                  Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
                  The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
                  The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
                  The output order does not matter. Returning [9,0] is fine too.

            Example 2:
                  Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
                  Output: []
                  Explanation: Since words.length == 4 and words[i].length == 4, the concatenated substring has to be of length 16.
                  There is no substring of length 16 is s that is equal to the concatenation of any permutation of words.
                  We return an empty array.

            Example 3:
                  Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
                  Output: [6,9,12]
                  Explanation: Since words.length == 3 and words[i].length == 3, the concatenated substring has to be of length 9.
                  The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which is a permutation of words.
                  The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which is a permutation of words.
                  The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which is a permutation of words.
*/



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        int n = words.size() , m = words[0].size();
        int len = words.size() * words[0].size();
        
        vector<int> res;
        unordered_map<string,int> wordCount;
        
        // base case
        if(s.length() < n * m)
            return {};
        
        for(auto i : words)
            wordCount[i]++;
        
        for(int i = 0; i <= s.length() - len; i++)
        {
            unordered_map<string,int> sCount;
            
            // creating substrings of size 3 for matching 
            for(int j = i; j < i + len; j += words[0].size())
            {
                string cur = s.substr(j , m);                   // make a string of size 3 from s 
                
                // if string is found in wordCount map then increase its count in sCount map
                // else break the loop no need to check further
                if(wordCount.find(cur) != wordCount.end())
                    sCount[cur]++;
                else
                    break;
                
                if(sCount[cur] > wordCount[cur])
                    break;
            }
            
            if(sCount == wordCount)
                res.push_back(i);
        }
        
        return res;
    }
};




/*     Naive Approach (Gives TLE)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        // base case
        if(words.size() == 0 || (s.size() < words.size() * words[0].size()))
            return {};
        
        // store all the possible permutations of word string in vector v
        vector<string> v;
        sort(words.begin(),words.end());
        
        do {
            string temp;
            for(auto i : words)
                temp += i;
            
            v.push_back(temp);
        }while(next_permutation(words.begin(),words.end()));
        
        int len = v[0].size();
        vector<int> res;
        
        // creating a substring of length len and check that substring is present in s or not
        // if present then store the starting index of substring in vector res 
        for(int i = 0; i <= s.length() - len; i++)
        {
            string cur = s.substr(i,len);
        
            for(auto a : v)
            {
                if(a == cur)
                    res.push_back(i);
            }
        }
        
        return res;
    }
};
*/





