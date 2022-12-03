/*  Design a special dictionary that searches the words in it by a prefix and a suffix.
    
    Implement the WordFilter class:
         * WordFilter(string[] words) Initializes the object with the words in the dictionary.
         * f(string pref, string suff) Returns the index of the word in the dictionary, which has the prefix pref and the suffix suff. If there is more than one valid
           index, return the largest of them. If there is no such word in the dictionary, return -1.

                Example 1:
                        Input
                        ["WordFilter", "f"]
                        [[["apple"]], ["a", "e"]]

                        Output
                        [null, 0]

                        Explanation
                        WordFilter wordFilter = new WordFilter(["apple"]);
                        wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = "e".
*/



class WordFilter {
public:
    unordered_map<string, int> mp; //stores preffix and suffix sequence in it
    
    WordFilter(vector<string>& words) 
    {
        int n = words.size();
        
        for(int i=0; i<n; i++) //cover each word in words
        {
            string word = words[i]; 
            int wordsize = word.size();
            
            //storing all possible sequence of prefix and suffix of a word in the hashmap
            for(int j=1; j<=wordsize; j++) //for preffix 
            {
                string pre = word.substr(0,j);
                
                for(int k=0; k<wordsize; k++) //for suffix
                {
                    string suff = word.substr(k, wordsize);
                    mp[pre + "|" + suff] = i+1; //set index i+1 for all possible sequence of a word
                    //we set i+1 to handle i=0 because by-default map initialized with 0 
                }
            }
        }
    }
    
    int f(string prefix, string suffix) 
    {
        string s = prefix + "|" + suffix;
        return mp[s]-1; //if sequence found in hashmap we return its index
    }
};




