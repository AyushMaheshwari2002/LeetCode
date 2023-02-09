/*  Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
    An integer a is closer to x than an integer b if:
         * |a - x| < |b - x|, or
         * |a - x| == |b - x| and a < b

              Example 1:
                    Input: arr = [1,2,3,4,5], k = 4, x = 3
                    Output: [1,2,3,4]

              Example 2:
                    Input: arr = [1,2,3,4,5], k = 4, x = -1
                    Output: [1,2,3,4]
*/



// USING PRIORITY QUEUE
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // priority_queue<pair<int,int>> pq;
        
        for(int i = 0; i < arr.size(); i++)
        {
            pq.push(make_pair(abs(x-arr[i]),arr[i]));
            
            /*
            if(pq.size() > k)
                pq.pop();
            */
        }
        
        vector<int> ans;
        for(int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};



/* USING VECTOR PAIR 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        vector<pair<int,int>> v;
        vector<int> ans;
        
        for(int i = 0; i < arr.size(); i++)
        {
            v.push_back({abs(arr[i]-x),arr[i]});
        }
        
        sort(v.begin(),v.end());
        
        for(int i = 0; i < k; i++)
        {
            ans.push_back(v[i].second);
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
*/



