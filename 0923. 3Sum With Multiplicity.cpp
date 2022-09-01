/*  Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
    As the answer can be very large, return it modulo 109 + 7.

            Example 1:
                    Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
                    Output: 20
                    Explanation: 
                    Enumerating by the values (arr[i], arr[j], arr[k]):
                    (1, 2, 5) occurs 8 times;
                    (1, 3, 4) occurs 8 times;
                    (2, 2, 4) occurs 2 times;
                    (2, 3, 3) occurs 2 times.

            Example 2:
                    Input: arr = [1,1,2,2,2,2], target = 5
                    Output: 12
                    Explanation: 
                    arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
                    We choose one 1 from [1,1] in 2 ways,
                    and two 2s from [2,2,2,2] in 6 ways.

            Example 3:
                    Input: arr = [2,1,3], target = 6
                    Output: 1
                    Explanation: (1, 2, 3) occured one time in the array so we return 1.
*/




class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {
        long res = 0, mod = 1000000007;
        
        for(int i = 0; i < arr.size(); i++)
        {
            vector<int> v(101 , 0);
            
            for(int j = i+1; j < arr.size(); j++) 
            {
                int k = target - arr[i] - arr[j];
                
                if(k >= 0 && k <= 100 && v[k] > 0)
                {
                    res += v[k];
                    res %= mod;
                }
                v[arr[j]]++;
            }
        }
        return res;
    }
};



