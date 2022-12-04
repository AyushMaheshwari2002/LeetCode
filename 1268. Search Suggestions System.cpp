/*  You are given an array of strings products and a string searchWord.
    Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix
    with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.
    Return a list of lists of the suggested products after each character of searchWord is typed.

          Example 1:
                Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
                Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
                Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
                After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
                After typing mou, mous and mouse the system suggests ["mouse","mousepad"].

          Example 2:
                Input: products = ["havana"], searchWord = "havana"
                Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
                Explanation: The only word "havana" will be always suggested while typing the search word.
*/



class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        sort(products.begin(), products.end());
         vector<vector<string>> result;
         int start, bsStart = 0, n=products.size();
         string prefix;
        
         for (char &c : searchWord) {
             prefix += c;

             start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();

             result.push_back({});
             for (int i = start; i < min(start + 3, n) && !products[i].compare(0, prefix.length(), prefix); i++)
                 result.back().push_back(products[i]);

             bsStart = start;
         }
         return result;
    }
};



