/*  Given an m x n board of characters and a list of strings words, return all words on the board.
    Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell 
    may not be used more than once in a word.

          Example 1:
              Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
              Output: ["eat","oath"]

          Example 2:
              Input: board = [["a","b"],["c","d"]], words = ["abcb"]
              Output: []
*/



class Solution {
public:

    string str;
    bool vis[13][13];

    unordered_set<string> res;
    unordered_set<string> toFound;
    unordered_map<string, int> m;

    void rec(int i, int j, vector<vector<char>> &a)
    {
        if (toFound.find(str) != toFound.end())
        {
            string curr;

            for (auto x : str)
            {
                curr += x;
                m[curr]--;
            }

            toFound.erase(curr);
            res.insert(str);
        }

        if (i < 0 || j < 0 || i >= a.size() || j >= a[0].size() || vis[i][j] || m[str] == 0)
        {
            return;
        }

        vis[i][j] = 1;

        str += a[i][j];

        rec(i + 1, j, a);
        rec(i, j + 1, a);
        rec(i, j - 1, a);
        rec(i - 1, j, a);

        vis[i][j] = 0;

        str.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& a, vector<string>& words) {


        for (auto x : words)
        {
            string curr;

            toFound.insert(x);

            for (auto y : x)
            {
                curr += y;
                m[curr]++;
            }
        }

        m[""]++;

        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[0].size(); j++)
            {
                memset(vis, 0, sizeof(vis));
                rec(i, j, a);
            }
        }

        vector<string> ans;

        for (auto x : res)
        {
            ans.push_back(x);
        }

        return ans;
    }
};





