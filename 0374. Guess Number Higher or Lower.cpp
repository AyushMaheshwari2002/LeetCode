public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int start = 0;                                    // start from 0
        int end = n;                                      // till n --> GivenNumber
      
        while(start <= end)                               // repeat Following till start <= end
        {                                                                  
            int mid = start + (end - start)/2;            // Find mid
            int ans = guess(mid);                         // Pass mid as a Argument to guess Interface to find the Ans
          
            if(ans == 0)                                  // if ans is 0 it means mid is the Right Guess then return mid
                return mid;
            else if(ans < 0) {                            // if ans is Negative it means guess number is Smaller then search in left Half for Smaller Numbers
                end = mid-1;      
            }
            else                                          // otherwise Seach in Right Half for Greater Numbers
                start = mid+1;
        }
        return -1;                                        // if Number not Found return -1   
    }
}
