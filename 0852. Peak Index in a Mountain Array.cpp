/* Peak Index in a Mountain Array
          Example 1:
                  Input: arr = [0,1,0]
                  Output: 1

          Example 2:
                  Input: arr = [0,2,1,0]
                  Output: 1

          Example 3:
                  Input: arr = [0,10,5,2]
                  Output: 1
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        // Solution using Linear Search
        int max = arr[0];
        int index = 0;                        //take this b'coz we have to return index not value
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] > max)
                index = i;                //this will give the index
                max = arr[i];             //this will give the value but we want index
        }
        return index;
    }
};


/* 
Other method using Standard Library Functions
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        return (max_element(arr.begin(),arr.end()) - arr.begin());
    }   
};
*/
