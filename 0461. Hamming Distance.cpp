/* The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
   Given two integers x and y, return the Hamming distance between them.

              Example 1:
              Input: x = 1, y = 4
              Output: 2
              Explanation:
              1   (0 0 0 1)
              4   (0 1 0 0)
                     ↑   ↑
              The above arrows point to positions where the corresponding bits are different.

              Example 2:
              Input: x = 3, y = 1
              Output: 1
*/


class Solution {
public:
    int hammingDistance(int x, int y)
    {    
        int result = x ^ y;    //Xor(^) gives 1 if bits are different.
        int count = 0;
        
        while(result > 0)
        {
            result = result & (result - 1);   // Brain Kernighan's Algorithm | AND(&) gives 1 if both bits are 1.
            count++;
        }
        return count;
    }
};


