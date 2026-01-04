class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return solve(n, n, "");
    }
    
    vector<string> solve(int lefts, int rights, string prev) {
        if (rights == 0) return vector<string>{prev};
        vector<string> curr;
        if (lefts != 0) {
            if (lefts < rights) {
                vector<string> new_vec = solve(lefts, rights-1, prev + ')');
                curr.insert(curr.end(), new_vec.begin(), new_vec.end());
            }
            vector<string> new_vec = solve(lefts-1, rights, prev + '(');
            curr.insert(curr.end(), new_vec.begin(), new_vec.end());
        } else {
            string end(rights, ')');
            vector<string> new_vec = solve(0, 0, prev + end);
            curr.insert(curr.end(), new_vec.begin(), new_vec.end());
        }
        return curr;
    }
};