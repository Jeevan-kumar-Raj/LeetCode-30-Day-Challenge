/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?


*/
//TC=O(N)
//TC& SC= O(N+M)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        string result1 = "", result2 = "";
        int i = 0;
        
        while(S[i]!='\0')
        {
            if(S[i]>'a' && S[i]<='z')
                result1 += S[i];
            else if(!result1.empty())
                result1.pop_back();
            ++i;
            
        }
        
        i=0;
        while(T[i]!='\0')
        {
            if(T[i]>'a' && T[i]<='z')
                result2 += T[i];
            else if(!result2.empty())
                result2.pop_back();
            ++i;
            
        }
        
        if(result1.compare(result2)==0)
            return true;
        return false;
        
    }
};


//Second Solution
// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int skipS = 0, skipT = 0;
        for (int i = S.length() - 1, j = T.length() - 1;
             i >= 0 || j >= 0;
             --i, --j) {
            auto x = findNextChar(S, &i, &skipS);
            auto y = findNextChar(T, &j, &skipT);
            if (x != y) {
                return false;
            }
        }
        return true;
    }

private:
    char findNextChar(const string& s, int *i, int *skip) {
        for (; *i >= 0; --(*i)) {
            if (s[*i] == '#') {
                ++(*skip);
            } else if ((*skip) > 0) {
                --(*skip);
            } else {
                return s[*i];
            }
        }
        return '\0';
    }
};