/*  You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
    Return the maximum possible length of s.
    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

              Example 1:
                    Input: arr = ["un","iq","ue"]
                    Output: 4
                    Explanation: All the valid concatenations are:
                    - ""
                    - "un"
                    - "iq"
                    - "ue"
                    - "uniq" ("un" + "iq")
                    - "ique" ("iq" + "ue")
                    Maximum length is 4.

              Example 2:
                    Input: arr = ["cha","r","act","ers"]
                    Output: 6
                    Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

              Example 3:
                    Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
                    Output: 26
                    Explanation: The only string in arr has all 26 characters.
*/



class Solution {
public:
    int maxLength(vector<string>& arr, string str = "", int index = 0)
    {
	    //Use set to check if the string contains all unique characters
        unordered_set<char>s(str.begin(), str.end());
        if (s.size() != ((int)str.length())) 
            return 0;
        
        int ret = str.length();
        for (int i = index; i < arr.size(); i++)
            ret = max(ret, maxLength(arr, str+arr[i], i+1));

        return ret;
    }
};


