#include <iostream>
#include <string>

#define fori(n) for (int i = 0; i < n; i++)
#define forj(m) for (int j = 0; j < m; j++)

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1 || isPalindrome(s)) {
            return s;
        }
        int max = 0;
        string out = "";
        fori(s.length()) {
            if (max < i+1 && isPalindrome(s.substr(0, i+1))) { 
                max = i+1;
                out = s.substr(0, i+1);
            }
            for (int l = 0; l <= min((int)s.length()-i, i); l++) {
                // cout << i-l << " " << i+l << endl;
                if (s[i-l] != s[i+l]) {
                    // cout << l << endl;
                    l--;
                    if (2*l+1 > max) {
                        out = s.substr(i-l, 2*l+1);
                        max = 2*l+1;
                    }
                    break;
                }
            }
            for (int l = 0; l <= min((int)s.length()-i, i); l++) {
                // cout << i-l << " " << i+l+1 << endl;
                if (s[i-l] != s[i+l+1]) {
                    // cout << l << endl;
                    l--;
                    if (2*l+2 > max) {
                        out = s.substr(i-l, 2*l+2);
                        max = 2*l+2;
                    }
                    break;
                }
            }
            // int l = i;
            // int r = i;
            // bool increaseL = true;
            // while (l >= 0 && r < s.size() && s[l] == s[r]) {
            //     cout << l << " " << r << endl;
            //     if (increaseL) {
            //         l--;
            //     } else {
            //         r++;
            //     }
            //     increaseL = !increaseL;
            // }
            // r--;
            // l++;
            // if (r-l+1 >= max) {
            //     out = s.substr(l, r-l+1);
            //     max = r-l+1;
            // }
        }
        return out;
    }

    bool isPalindrome(string s) {
        fori(s.length()) {
            if (s[i] != s[s.length()-1-i]) return false;
        }
        return true;
    }
};