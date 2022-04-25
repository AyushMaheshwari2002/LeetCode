/*  You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type 
    of stone you have. You want to know how many of the stones you have are also jewels.
    Letters are case sensitive, so "a" is considered a different type of stone from "A".

              Example 1:
              Input: jewels = "aA", stones = "aAAbbbb"
              Output: 3

              Example 2:
              Input: jewels = "z", stones = "ZZ"
              Output: 0
*/



class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        int count = 0;
        for(int i = 0; i < jewels.size(); i++)
        {
            for(int j = 0; j < stones.size(); j++)
            {
                if(jewels[i] == stones[j])
                    count++;
            }
        }
        return count;
    }
};


