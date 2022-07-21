/* Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers,
   return an empty array.

          Example 1:
                Input: num = 33
                Output: [10,11,12]
                Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
                10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].

          Example 2:
                Input: num = 4
                Output: []
                Explanation: There is no way to express 4 as the sum of 3 consecutive integers.
*/



class Solution {
public:
    vector<long long> sumOfThree(long long num)
    {
        if(num % 3 != 0)
            return {};
        
        long long mid = num / 3;
        
        return {mid-1 , mid , mid+1};
    }
};




/*
Explanation :
        Mathematically:
            x+(x-1)+(x+1) = n
            => 3x=n
            => x=n/3

        Thus, we can say that:
            If a number is divisible by 3, then only an answer exists.
            If a number is divisible by 3, then it's answer array would have three elements:
            i. num/3
            ii. num/3 + 1
            iii. num/3 - 1
        
        Let's check the validity of above points using examples!
            For num=2. No triplet is possible.
            For num=3. Our answer would be: [0, 1, 2].
            For num=4. No triplet is possible.
            For num=6. Our answer would be: [1, 2, 3].
            For num=9. Our answer would be: [2, 3, 4].
*/



