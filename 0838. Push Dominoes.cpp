/*  There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or 
    to the right.
    After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their 
    adjacent dominoes standing on the right.
    When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
    For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
    You are given a string dominoes representing the initial state where:
         * dominoes[i] = 'L', if the ith domino has been pushed to the left,
         * dominoes[i] = 'R', if the ith domino has been pushed to the right, and
         * dominoes[i] = '.', if the ith domino has not been pushed.
    Return a string representing the final state.

              Example 1:
                      Input: dominoes = "RR.L"
                      Output: "RR.L"
                      Explanation: The first domino expends no additional force on the second domino.

              Example 2:
                      Input: dominoes = ".L.R...LR..L.."
                      Output: "LL.RR.LLRRLL.."
*/



class Solution {
public:
    string pushDominoes(string s) {
         int N = s.size(), right = -1;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'L') {
            if (right == -1) { 
                for (int j = i - 1; j >= 0 && s[j] == '.'; --j) {
                  s[j] = 'L';  
                } 
            } else {
                for (int j = right + 1, k = i - 1; j < k; ++j, --k) {
                    s[j] = 'R';
                    s[k] = 'L';
                } 
                right = -1;
            }
        } else if (s[i] == 'R') {
            if (right != -1) {
                for (int j = right + 1; j < i; ++j) s[j] = 'R';
            }
            right = i;
        }
    }
    if (right != -1) {
        for (int j = right + 1; j < N; ++j) s[j] = 'R';
    }
    return s;
    }
};



