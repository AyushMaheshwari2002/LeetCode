/*  You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation
    Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
    You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
    Return the answers to all queries. If a single answer cannot be determined, return -1.0.
    Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

          Example 1:
                Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
                Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
                Explanation: 
                Given: a / b = 2.0, b / c = 3.0
                queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
                return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

          Example 2:
                Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
                Output: [3.75000,0.40000,5.00000,0.20000]

          Example 3:
                Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
                Output: [0.50000,2.00000,-1.00000,-1.00000]
*/




class Solution {
private:
	double find(unordered_map<string, vector<pair<string, double>>> &grf, unordered_set<string> visited, string start, string end)
    {
		if(grf.find(start) == grf.end() || grf.find(end) == grf.end()) 
            return -1.0; // return -1 if start and end not exist in adj. list

		if(start == end) 
            return 1.0; //if we are at end

		visited.insert(start); // mark as visited 

		for(auto next : grf[start])
        {
			if(visited.count(next.first) == 0)
            {
				double res = find(grf, visited, next.first, end);

				if(res != -1.0)
                {
					return res*next.second;
				}
			}
		}
		return -1.0;
	} 

public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
		unordered_map<string, vector<pair<string, double>>> grf;

		for(int i = 0; i < equations.size(); i++)
        { // making adj. list for each edge
			grf[equations[i][0]].push_back({equations[i][1], values[i]});
			grf[equations[i][1]].push_back({equations[i][0], 1/values[i]});
		}

		vector<double> ans;

		for(auto q : queries)
        {
			unordered_set<string> visited; // track previous visited nodes  in order to avoid infinite loop
			double res = find(grf, visited, q[0], q[1]);  // go for current query
			ans.push_back(res);
		}
		return ans;
	}
};




