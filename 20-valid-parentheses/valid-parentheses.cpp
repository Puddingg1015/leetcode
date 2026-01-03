#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;
        map<char, char> rbrackets;
        rbrackets[')'] = '(';
        rbrackets[']'] = '[';
        rbrackets['}'] = '{';
        int count = 0;
        for (char chr : s) {
            if (!rbrackets.contains(chr)) {
                // cout << "L" << chr << endl;
                chars.push(chr);
            } else {
                // cout << "R" << chr << endl;
                if (!chars.empty() && rbrackets[chr] == chars.top()) {
                    chars.pop();
                    count += 2;                    
                }
            }
        }
        if (chars.empty() && count == s.length()) return true;
        return false;
    }
};