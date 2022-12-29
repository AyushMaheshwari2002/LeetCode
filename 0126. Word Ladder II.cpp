/*  A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
         * Every adjacent pair of words differs by a single letter.
         * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
         * sk == endWord
    Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if
    no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

            Example 1:
                  Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
                  Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
                  Explanation: There are 2 shortest transformation sequences:
                  "hit" -> "hot" -> "dot" -> "dog" -> "cog"
                  "hit" -> "hot" -> "lot" -> "log" -> "cog"

            Example 2:
                  Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
                  Output: []
                  Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/



class Solution {
public:
    bool isAdj(string&a , string&b)
    {
        int diff = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i])
            {
                if(++diff == 2)
                {
                    return false;
                }
            }
        }
        return diff == 1;
    }
    
    void collectPaths(vector<string>&words, vector<vector<int>>&prevs, vector<vector<string>>&result, int curr, vector<int>&currPath, int stop, int eindex)
    {
        if(stop == curr)
        {
            vector<string>temp;
            for(int i = currPath.size()-1; i >= 0; i--)
            {
                temp.push_back(words[currPath[i]]);
            }
            temp.push_back(words[eindex]);
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < prevs[curr].size(); i++)
        {
            currPath.push_back(prevs[curr][i]);
            collectPaths(words,prevs,result,prevs[curr][i],currPath,stop,eindex);
            currPath.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        int eindex = -1;
        int root = -1;
        
        for(int i = 0; i < wordList.size(); i++)
        {
            if(wordList[i] == beginWord)
            {
                root = i;
            }
            else if(wordList[i] == endWord)
            {
                eindex = i;
                break;
            }
        }
        if(eindex == -1)
        { 
            return {};
        }
        if(root == -1)
        {
            wordList.push_back(beginWord);
            root = wordList.size()-1;
        }
        
        int n = wordList.size();
        vector<vector<int>>graph(n+1);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(isAdj(wordList[i],wordList[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        vector<vector<int>>prevs(n);
        vector<int>steps(n,0);
        queue<int> q;
        q.push(root);
        int level = 0;
        
        while(q.size())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                
                for(auto adj : graph[curr])
                {
                    if(steps[adj])
                    {
                        if(steps[adj] == level+1)
                            prevs[adj].push_back(curr);
                        
                        continue;
                    }
                    steps[adj] = level+1;
                    prevs[adj].push_back(curr);
                    q.push(adj);
                }
            }
            level++;
        }
        
        vector<vector<string>>result;
        vector<int>currPath;
        collectPaths(wordList,prevs,result,eindex,currPath,root,eindex);
        
        return result;
    }
};




