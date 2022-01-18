/* 
               Example 1:
                    Input: num1 = "11", num2 = "123"
                    Output: "134"

               Example 2:
                    Input: num1 = "456", num2 = "77"
                    Output: "533"

               Example 3:
                    Input: num1 = "0", num2 = "0"
                    Output: "0"
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        if(num1.length() > num2.length())
            swap(num1,num2);
        
        while(num1.length() < num2.length())
            num1 = num1 + "0";
        
        int carry = 0;
        string ans;
        
        for(int i = 0; i < num1.length(); i++){ 
            int value = (num1[i] - '0') + (num2[i] - '0') + carry;
            int curr_value = value % 10;
            carry = value / 10;
            ans += ('0' + curr_value);
        }
        
        if(carry)
            ans += ('0' + carry);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


/* 
class Solution {
public:
    string addStrings(string num1, string num2) {
    string result;

    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int current_value = carry;

        if (i >= 0) {
            current_value += num1[i] - '0';
        }

        if (j >= 0) {
            current_value += num2[j] - '0';
        }

        carry = current_value / 10;
        current_value = current_value % 10;

        result = (char)(current_value + '0') + result;

        i--;
        j--;
    }
    return result;
    }
};
*/
