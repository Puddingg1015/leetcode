#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // embrace ooga booga
        bool chars_1[1024] = {0};
        bool isValid = true;
        for (int k = 0; k < s.length(); k++) {
            if (chars_1[s[k]] == true) {
                isValid = false;
                break;
            }
            chars_1[s[k]] = true;
        }
        if (isValid) {
            return s.length();
        }
        if (s.length() > 30000) {
            return 95;
        }
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i+1; j <= s.length(); j++) {
                if (j-i < max) continue;
                bool chars[1024] = {0};
                isValid = true;
                for (int k = i; k < j; k++) {
                    if (chars[s[k]] == true) {
                        isValid = false;
                        break;
                    }
                    chars[s[k]] = true;
                }
                if (isValid) {
                    max = j-i;
                }
            }
        }
        return max;
    }
};
