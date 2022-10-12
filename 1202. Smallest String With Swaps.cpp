/*  You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
    You can swap the characters at any pair of indices in the given pairs any number of times.
    Return the lexicographically smallest string that s can be changed to after using the swaps.

          Example 1:
                Input: s = "dcab", pairs = [[0,3],[1,2]]
                Output: "bacd"
                Explaination: 
                Swap s[0] and s[3], s = "bcad"
                Swap s[1] and s[2], s = "bacd"

          Example 2:
                Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
                Output: "abcd"
                Explaination: 
                Swap s[0] and s[3], s = "bcad"
                Swap s[0] and s[2], s = "acbd"
                Swap s[1] and s[2], s = "abcd"

          Example 3:
                Input: s = "cba", pairs = [[0,1],[1,2]]
                Output: "abc"
                Explaination: 
                Swap s[0] and s[1], s = "bca"
                Swap s[1] and s[2], s = "bac"
                Swap s[0] and s[1], s = "abc"
*/




class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    
    void dfs(int i, vector<int> &index, vector<char> &letters, string &s)
    {
        visited[i] = true;
        index.push_back(i);
        letters.push_back(s[i]);
        
        for(auto k : graph[i])
        {
            if(!visited[k])
            {
                dfs(k, index, letters, s);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        graph.resize(n);
        visited.resize(n , false);
        
        for(auto x : pairs)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
       
        for(int i = 0; i < n; i++)
        {
            vector<int> index;
            vector<char> letters;
            
            if(!visited[i])
            {
                dfs(i, index, letters, s);
            }
            sort(index.begin(),index.end());
            sort(letters.begin(),letters.end());
            
            for(int i = 0; i < index.size(); i++)
            {
                s[index[i]] = letters[i];
            }
        }
        
        return s;
    }
};



