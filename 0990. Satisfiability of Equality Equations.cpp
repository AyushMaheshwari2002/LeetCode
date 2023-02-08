/*  You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two
    different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.
    Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

            Example 1:
                  Input: equations = ["a==b","b!=a"]
                  Output: false
                  Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
                  There is no way to assign the variables to satisfy both equations.

            Example 2:
                  Input: equations = ["b==a","a==b"]
                  Output: true
                  Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
*/



class Solution {
public:
 	int find(char x, unordered_map<char, char>& parent)
    {
 		if (parent[x] != x) parent[x] = find(parent[x], parent);
            return parent[x];
 	}
    
    bool equationsPossible(vector<string>& equations) 
    {
        unordered_map<char, char> parent;
        
        for(auto x: equations){
            parent[x[0]] = x[0];
            parent[x[3]] = x[3];
        }
        
        for(auto it: equations){
            char x = find(it[0], parent);
            char y = find(it[3], parent);
            
            if(it[1] == '=') 
                parent[y] = x; 
        }
        
        for(auto it: equations){
            char x = find(it[0], parent);
            char y = find(it[3], parent);
            
            if(it[1] == '!' && x==y)
                return false;
        }
            
        return true;
    }
};


