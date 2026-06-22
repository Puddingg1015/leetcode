class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int chars[26] = {0};
        for (int i = 0; i < text.length(); i++) {
            chars[text[i] - 'a']++;
        }
        int min = text.length();
        string balloon = "balloon";
        for (char chr : balloon) {
            if ((chr == 'l' || chr == 'o') && chars[chr - 'a']/2 < min) min = chars[chr - 'a']/2;
            else if (chars[chr - 'a'] < min) min = chars[chr - 'a'];
        }
        return min;
    }
};