/*  You are given an array nums of n positive integers.
    You can perform two types of operations on any element of the array any number of times:
      * If the element is even, divide it by 2.
              * For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
      * If the element is odd, multiply it by 2.
              * For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
    The deviation of the array is the maximum difference between any two elements in the array.
    Return the minimum deviation the array can have after performing some number of operations.

          Example 1:
                Input: nums = [1,2,3,4]
                Output: 1
                Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.

          Example 2:
                Input: nums = [4,1,5,20,3]
                Output: 3
                Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.

          Example 3:
                Input: nums = [2,10,8]
                Output: 3
*/



/*
Solution - I (using Priority queue)
Time Complexity --> O(n * log(m) * log(n)) 
Space Complexity --> O(n) 
*/
class Solution {
public:
    int minimumDeviation(vector<int>& arr) 
    {
        int n = arr.size(); // extracting size of the array
        
        for(int i = 0; i < n; i++) // making every odd element to even
        {
            if(arr[i] % 2 == 1) // if it is odd
            {
                arr[i] = 2 * arr[i]; // multiply it by 2
            }
        }
        
        int mn = *min_element(arr.begin(), arr.end()); // take minimum element from array
        int mx = *max_element(arr.begin(), arr.end());// take maximum element from array
        
        int ans = mx - mn; // intially answer is difference of these two
        
        priority_queue<int> pq; // creating max heap
        
        for(int i = 0; i < n; i++) // push every element to max heap
        {
            pq.push(arr[i]);
        }
        
        // Until our top element is even, we will run the loop
        while(pq.top() % 2 == 0) 
        {
            int top = pq.top(); // extracting top of the heap
            pq.pop(); // pop that elemet from heap
            
            ans = min(ans, top - mn); // update answer to minimum difference
            
            top = top / 2; // divide by 2 to our top
            
            mn = min(mn, top); // also update minimum element as well
            
            pq.push(top); // push update top element to again heap
        }
        
        // again update the answer with one more time, because when we will stop 
        // we stop when we find an odd element on the top, so check the difference
        // with this also and update it to the answer
        ans = min(ans, pq.top() - mn); 
        
        return ans; // and at last return the answer
    }
};



/*
Solution - II (using Set)
Time Complexity --> O(n * log(n)) 
Space Complexity --> O(n) 

class Solution {
public:
    int minimumDeviation(vector<int>& arr) 
    {
        int n = arr.size(); // extracting size of the array
        
        set<int> s; // declaring set
        for(int i = 0; i < n; i++) // making every odd element to even
        {
            if(arr[i] % 2 == 1) // if it is odd
            {
                arr[i] = 2 * arr[i]; // multiply it by 2
                
                s.insert(arr[i]); // and then insert it to set
            }
            else if(arr[i] % 2 == 0) // if it is already even, 
            {
                s.insert(arr[i]); //simple insert to set
            }
        }
        
        //see proprty we dicussed about set 
        //(The set stores the elements in sorted order)
        
        // set::rbegin() is a built-in function in C++ STL which returns a reverse iterator pointing to the last element in the container and last should be our 
           maximum.
        
        // begin() function is used to return an iterator pointing to the first element of the set container and first element is our minimum
        int ans = *s.rbegin() - *s.begin();         // intially our answer
                
        while(*s.rbegin() % 2 == 0)
        {
            int last = *s.rbegin(); // take last element (or updated mx element)
            s.erase(last);
            
            s.insert(last / 2); // see property we discuss (second one)
            
            ans = min(ans, *s.rbegin() - *s.begin());
        }
        
        return ans; // at last, return the answer
        
    }
};
*/


