/*  A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
    Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in 
    the gene string.
    For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
    There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
    Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If 
    there is no such a mutation, return -1.
    Note that the starting point is assumed to be valid, so it might not be included in the bank.

            Example 1:
                Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
                Output: 1

            Example 2:
                Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
                Output: 2
*/



class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        unordered_map<string,int> mp,visited;
        
        vector<char> gene = {'A','G','T','C'};
        
        for (auto it:bank)
        {
            mp[it]++;
        }
        
        queue<string> q;
        q.push(start);
        
        int moves = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            
            for (int i=0; i<size; i++)
            {
                string curr = q.front();
                q.pop();
                
                if (curr==end)
                    return moves;
            
                for (int j=0; j<8; j++)
                {
                    string temp = curr;
                    
                    for (int k=0; k<4; k++)
                    {
                        temp[j]=gene[k];
                        cout << temp << endl;
                        if (mp[temp] && !visited[temp])
                        {
                            q.push(temp);
                            visited[temp]++;
                        }
                    }      
                }
            }
            moves++;
            
        }
        
        return -1;
        
    }
};



