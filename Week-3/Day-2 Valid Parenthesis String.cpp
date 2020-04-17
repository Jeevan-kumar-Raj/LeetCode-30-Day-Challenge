Day-2 Valid Parenthesis String.cpp

/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].

*/


class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> open,star;
        int len = s.length();
        
        for(int i=0;s[i]!='\0';++i)
        {
            if(s[i]=='(')
                open.push(i);
            else if(s[i]=='*')
                star.push(i);
            else
            {
                if(!open.empty())
                    open.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        
        //Now process leftover opening brackets
        while(!open.empty())
        {
            if(star.empty())
                return false;
            else if(open.top() < star.top())
            {
                open.pop();
                star.pop();
            }
            else    //CASE: open.top() > star.top()
                return false;
        }
        return true;
    }
};
