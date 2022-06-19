/*  A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various 
    applications of this data structure, such as autocomplete and spellchecker.

    Implement the Trie class:
        * Trie() Initializes the trie object.
        * void insert(String word) Inserts the string word into the trie.
        * boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
        * boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 
            Example 1:
                  Input
                  ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
                  [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
                  Output
                  [null, null, true, false, true, null, true]

                  Explanation
                  Trie trie = new Trie();
                  trie.insert("apple");
                  trie.search("apple");   // return True
                  trie.search("app");     // return False
                  trie.startsWith("app"); // return True
                  trie.insert("app");
                  trie.search("app");     // return True
*/



class Trie 
{
    Trie* children[26];
    bool isEndofWord;
    
public:
    Trie() 
    {
        isEndofWord = false;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
    
    void insert(string word) 
    {
        Trie* curr = this;
        for(char c : word)
        {
            if(curr -> children[c - 'a'] == NULL)
            {
                curr -> children[c - 'a'] = new Trie;
            }
            curr = curr -> children[c - 'a'];
        }
        curr -> isEndofWord = true;
    }
    
    bool search(string word) 
    {
        Trie* curr = this;
        for(char c : word)
        {
            curr = curr -> children[c - 'a'];
            
            if(curr == NULL)
            {
                return false;
            }
        }
        if(curr -> isEndofWord == true)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) 
    {
        Trie* curr = this;
        for(char c : prefix)
        {
            curr = curr -> children[c - 'a'];
            
            if(curr == NULL)
            {
                return false;
            }
        }
        return true;
    }
};
 
 
 
 
