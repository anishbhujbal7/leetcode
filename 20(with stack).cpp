#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> myst;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                // Push the opening brackets onto the stack
                myst.push(s[i]);
            } 
            else {
                // Check if the stack is empty before accessing the top element
                if (myst.empty()) {
                    return false;
                }

                // Compare closing brackets with the top element in the stack
                if (s[i] == ')' && myst.top() == '(') {
                    myst.pop();  // If it's a match, pop the top element
                } 
                else if (s[i] == ']' && myst.top() == '[') {
                    myst.pop();
                } 
                else if (s[i] == '}' && myst.top() == '{') {
                    myst.pop();
                } 
                else {
                    return false;  // If no match is found, return false
                }
            }
        }

        // If the stack is empty at the end, all brackets matched correctly
        return myst.empty();
    }
};

