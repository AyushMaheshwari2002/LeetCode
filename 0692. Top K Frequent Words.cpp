/*  Given an array of strings words and an integer k, return the k most frequent strings.
    Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

          Example 1:
              Input: words = ["i","love","leetcode","i","love","coding"], k = 2
              Output: ["i","love"]
              Explanation: "i" and "love" are the two most frequent words.
              Note that "i" comes before "love" due to a lower alphabetical order.

          Example 2:
              Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
              Output: ["the","is","sunny","day"]
              Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
*/



class Solution {
public:
    bool static compare(pair<int , string> a , pair<int , string> b)
    {
        // if frequencies are same then arrange in lexicographical order
        if(a.first == b.first)
            return a.second < b.second;
        
        return a.first > b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string , int> m;
        
        for(int i = 0; i < words.size(); i++)
            m[words[i]]++;
        
        vector<pair<int , string>> v;
        for(auto i : m)
        {
            // in vector we have first store the frequency then no. b'coz we have to sort the vector on the basis of increasing frequency
            v.push_back({i.second , i.first});   
        }
        
        sort(v.begin() , v.end() , compare);
        
        vector<string> ans;
        for(int i = 0; i < k; i++)
        {
            ans.push_back(v[i].second);
        }
        
        return ans;
        
    }
};




