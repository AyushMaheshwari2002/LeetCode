/*  Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

            Example 1:
                  Input: nums = [5,2,6,1]
                  Output: [2,1,1,0]
                  Explanation:
                  To the right of 5 there are 2 smaller elements (2 and 1).
                  To the right of 2 there is only 1 smaller element (1).
                  To the right of 6 there is 1 smaller element (1).
                  To the right of 1 there is 0 smaller element.

            Example 2:
                  Input: nums = [-1]
                  Output: [0]

            Example 3:
                  Input: nums = [-1,-1]
                  Output: [0,0]
*/



class Solution {
public:
    
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right)
    {
        // take a temporary array which store value in decreasing order
        vector<pair<int,int>> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;
        
        while(i <= mid && j <= right)
        {   
            if(v[i].first <= v[j].first)
            {
                temp[k++] = v[j++];
            }
            
            else
            {   // case : 5 > 2 then increase the count vector
                count[v[i].second] += right-j+1;
                temp[k++] = v[i++];         // here we have increase the count and store the values in temp vector in decreasing order
            }
        }
        
        while(i <= mid)
        {
            temp[k++] = v[i++];
        }
        
        while(j <= right)
        {
            temp[k++] = v[j++];
        }
        
        for(int i = left; i <= right; i++)
        {
            v[i] = temp[i-left]; 
        }    
    }
    
    void mergeSort(vector<int> &count, vector<pair<int,int>> &v, int left, int right)
    {    
        if(left < right)
        {
            int mid = left + (right-left)/2;
            
            mergeSort(count, v, left, mid);
            mergeSort(count, v, mid+1, right);
            
            merge(count, v, left, mid, right);
        }  
    }
    
    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        
        // we have store the value and the index in vector
        for(int i = 0; i < n; i++)
        {
            v[i] = {nums[i] , i};
        }
        
        // this vector store the answer which we have to return
        vector<int> count(n, 0);
        mergeSort(count, v, 0, n-1);
        
        return count;
    }
};



