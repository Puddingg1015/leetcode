class Solution {
public:

    map<char, vector<char>> letters;

    vector<string> letterCombinations(string digits) {
        letters['2'] = vector<char>{'a','b','c'};
        letters['3'] = vector<char>{'d','e','f'};
        letters['4'] = vector<char>{'g','h','i'};
        letters['5'] = vector<char>{'j','k','l'};
        letters['6'] = vector<char>{'m','n','o'};
        letters['7'] = vector<char>{'p','q','r','s'};
        letters['8'] = vector<char>{'t','u','v'};
        letters['9'] = vector<char>{'w','x','y','z'};
        return solve(digits, vector<string>{""});
    }

    vector<string> solve(string digits, vector<string> prev) {
        vector<string> current;
        vector<char> pot_chars = letters[digits[0]];
        for (string ele : prev) {
            for (char chr : pot_chars) current.push_back(ele + chr);
        }
        if (digits.size() <= 1) return current;
        digits = digits.substr(1);
        return solve(digits, current);
    }

};