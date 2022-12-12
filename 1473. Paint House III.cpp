/*  There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last
    summer should not be painted again.
    A neighborhood is a maximal group of continuous houses that are painted with the same color.
        * For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].

    Given an array houses, an m x n matrix cost and an integer target where:
        * houses[i]: is the color of the house i, and 0 if the house is not painted yet.
        * cost[i][j]: is the cost of paint the house i with the color j + 1.
    Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.

            Example 1:
                  Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
                  Output: 9
                  Explanation: Paint houses of this way [1,2,2,1,1]
                  This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
                  Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.

            Example 2:
                  Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
                  Output: 11
                  Explanation: Some houses are already painted, Paint the houses of this way [2,2,1,2,2]
                  This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}]. 
                  Cost of paint the first and last house (10 + 1) = 11.

            Example 3:
                  Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
                  Output: -1
                  Explanation: Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.
*/



int n;
vector<int> houses;
vector<vector<int>> cost;
vector<vector<vector<int>>> dp;
int c;
int rec(int i, int last, int target) {
    // Pruning
    if(target < 0 ) return -1; // we cant make negative target, also we can't access dp[][][-veTarget] so prune it initially.
	
    // cout<<"Checking Base case : "<<endl;
    // base case
    if(i==n && target!=0) { // it can be so that we have not made required targets.
        return -1;
    }
    if(i==n && target==0) {
        return 0;
    }
    
    // cache check
    // cout<<"Checking Cache : "<<endl;
    
    if(dp[i][last][target]!=-2) {
        return dp[i][last][target];
    }
    // cout<<"Cache not found"<<endl;
	
    int ans=INT_MAX; // keeping answer as INT_MAX because we will take minimum with possible answer.
    bool possible=false; // No color is possible till now 
	
    // cout<<"Checking if house already colored "<<endl;
    if(houses[i]!=0) {
        if(houses[i]!=last) {
            return dp[i][last][target]=rec(i+1,houses[i],target-1);
        }
        else {
            return dp[i][last][target]=rec(i+1,houses[i],target);
            }
    }
    // cout<<"House Not colored last summer"<<endl;
	
    // cout<<"Trying all colors : "<<endl;
    for(int k=0;k<c;k++) {
        // choice of color is k+1
        // index is k
        // cout<<"Trying color : "<<k+1<<endl;
        int temp;
        if(k+1 != last) {
         temp=rec(i+1,k+1,target-1);        
        }
        else {
            temp=rec(i+1,k+1,target);        
        }
        // if this color is possible
        if(temp!=-1) {
            // cout<<k+1<<" color is possible"<<endl;
            possible=true;
            ans=min(ans,cost[i][k]+temp);
        }
    }
    if(possible) {
    return dp[i][last][target]=ans;
                
    }
    else { // no possible color found for this place, as we need to color all houses, => answer is -1.
        return dp[i][last][target]=-1;
    }
    
}

class Solution {
public:
    int minCost(vector<int>& house, vector<vector<int>>& cst, int r, int col, int target) {
        cost=cst;
        houses=house;
        c=col;
        n=r;
		dp.resize(n+1);
        for(int i=0;i<=n;i++) {
            dp[i].resize(n+1);
            for(int j=0;j<=n;j++) {
                dp[i][j].resize(target+1);
                for(int k=0;k<=target;k++) {
                    dp[i][j][k]=-2;
                }
            }
        }
		//dp.resize(m+1 , vector<vector<int>>(n+1 , vector<int>(target+1 , -2));
        // cout<<"initialised: "<<endl;
        return rec(0,0,target); // hope nobody acceses -1 index in dp
        // return -1;
    }
};


