/*                          Example 1:
                            Input: s = "III"
                            Output: 3
                            Explanation: III = 3.

                            Example 2:
                            Input: s = "LVIII"
                            Output: 58
                            Explanation: L = 50, V= 5, III = 3.

                            Example 3:
                            Input: s = "MCMXCIV"
                            Output: 1994
                            Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

class Solution {
public:
    int romanToInt(string s) {
     map<char , int>roman;
        roman.insert(make_pair('I' , 1));
        roman.insert(make_pair('V' , 5));
        roman.insert(make_pair('X' , 10));
        roman.insert(make_pair('L' , 50));
        roman.insert(make_pair('C' , 100));
        roman.insert(make_pair('D' , 500));
        roman.insert(make_pair('M' , 1000));
        
        int len = s.length(), num, sum = 0;
        
        for(int i = 0; i < len; )
        { 
            if(i == (len-1) || (roman[s[i]] >= roman[s[i+1]])){  
                num = roman[s[i]];
                i++;
            }
            else{  
                num = roman[s[i+1]] - roman[s[i]];
                i = i+2;
            }
            sum = sum + num;
        }
        return sum;
    }
};
